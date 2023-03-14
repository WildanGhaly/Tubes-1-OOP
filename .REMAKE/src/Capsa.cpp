// #pragma once

#include "Function/MaxMinAvg.hpp"
#include "Class/Valueable/Valueable.hpp"
#include "Class/Player/PlayerList.cpp"
#include "Class/Table/Table.cpp"
#include "Class/Game/Game.cpp"
#include "Class/Combination/Combination.cpp"
#include "Class/Combination/SubCombination/HighCard/HighCard.cpp"
#include "Class/Combination/SubCombination/Pair/Pair.cpp"
#include "Class/Combination/SubCombination/TwoPair/TwoPair.cpp"
#include "Class/Combination/SubCombination/ThreeOfKind/ThreeOfKind.cpp"
#include "Class/Combination/SubCombination/Straight/Straight.cpp"
#include "Class/Combination/SubCombination/Flush/Flush.cpp"
#include "Class/Combination/SubCombination/FullHouse/FullHouse.cpp"
#include "Class/Combination/SubCombination/FourOfKind/FourOfKind.cpp"
#include "Class/Combination/SubCombination/StraightFlush/StraightFlush.cpp"

#include "Exception/Exception.h"
#include <iostream>
#include <fstream>
using namespace std;
using std::cout;

int main(){
    bool done;
    Game<Card> game(4, "POKER");
    cout << "MASUK" << endl;


    int swap1, swap2;
    Player tempPlayer;
    float maxValue;

    game.start(13);
    // game.print();

    CardList<Card> cards = CardList<Card>();
    Combination *combination;
    HighCard highCard;
    Pair pair;
    TwoPair twoPair;
    ThreeOfKind threeOfKind;
    Straight straight;
    Flush flush;
    FullHouse fullHouse;
    FourOfKind fourOfKind;
    StraightFlush straightFlush;


    int i = 0;
    float value[3];
    float playerValue[4][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};


    while (i < 4){
        done = false;
        while (!done){
            cout << "Player " << i << " turn" << endl;
            cout << "Kartu saat in: " << endl;
            game.getPlayer(i).printCapsa();
            cout << "Kartu yang akan ditukar: " << endl;
            cout << "Urutan kartu: " << endl;
            cout << "0  1  2" << endl;
            cout << "3  4  5  6  7" << endl;
            cout << "8  9  10 11 12" << endl;

            cout << "Contoh input: 1 2" << endl;
            cout << "Jika tidak ada kartu yang akan ditukar, masukkan 0 0" << endl;
            cin >> swap1 >> swap2;

            if (swap1 == 0 && swap2 == 0){
                done = true;
            } else if (swap1 < -1 || swap1 > 12 || swap2 < -1 || swap2 > 12){
                cout << "Input tidak valid" << endl;
                // Exception handling
            } else {
                tempPlayer = game.getPlayer(i);
                tempPlayer.swapCardPosition(swap1, swap2);
                game.setPlayer(i, tempPlayer);
            }
        }
        for (int j = 0; j < 3; j++){
            value[j] = 0.0;
        }

        for (int k = 0; k < 3; k++){
            if (k == 0) {
                cards << game.getPlayer(i).getHand(0) << game.getPlayer(i).getHand(1) << game.getPlayer(i).getHand(2);
            } else if (k == 1) {
                cards << game.getPlayer(i).getHand(3) << game.getPlayer(i).getHand(4) << game.getPlayer(i).getHand(5) << game.getPlayer(i).getHand(6) << game.getPlayer(i).getHand(7);
            } else if (k == 2) {
                cards << game.getPlayer(i).getHand(8) << game.getPlayer(i).getHand(9) << game.getPlayer(i).getHand(10) << game.getPlayer(i).getHand(11) << game.getPlayer(i).getHand(12);
            }

            combination = &highCard;
            combination->setPoint(0);
            combination->setCards(cards);
            combination->computeScore();

            combination = &pair;
            combination->setPoint(highCard.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &twoPair;
            combination->setPoint(pair.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &threeOfKind;
            combination->setPoint(twoPair.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &straight;
            combination->setPoint(threeOfKind.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &flush;
            combination->setPoint(straight.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &fullHouse;
            combination->setPoint(flush.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &fourOfKind;
            combination->setPoint(fullHouse.getValue());
            combination->setCards(cards);
            combination->computeScore();

            combination = &straightFlush;
            combination->setPoint(fourOfKind.getValue());
            combination->setCards(cards);
            combination->computeScore();

            value[k] = straightFlush.getValue();

            cards = CardList<Card>(); // clear card
        }

        if (value[0] <= value[1] && value[1] <= value[2]){
            // sesuai aturan capsa
            cout << "Sudah sesuai!" << endl;
            playerValue[i][0] = value[0];
            playerValue[i][1] = value[1];
            playerValue[i][2] = value[2];
            i++;
        } else {
            cout << "Kartu belum sesuai aturan capsa" << endl;
        }

    }

    for (int l = 0; l < 4; l++) {
        for (int m = 0; m < 4; m++) {
            if (l != m) {
                for (int n = 0; n < 3; n++) {
                    if (playerValue[l][n] > playerValue[m][n]) {
                        tempPlayer = game.getPlayer(l);
                        tempPlayer.addScore(10);
                        game.setPlayer(l, tempPlayer);
                    } else {
                        // do nothing
                    }
                }
            } else {
                // do nothing
            }
        }
    }

    cout << "Hasil akhir: " << endl;
    for (int o = 0; o < 4; o++) {
        cout << "Player " << o << ": " << game.getPlayer(o).getValue() << endl;
        game.getPlayer(o).printCapsa();
    }


    return 0;
}
