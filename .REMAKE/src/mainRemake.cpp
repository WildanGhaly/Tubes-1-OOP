// Halo ges pakabar?
// Ini adalah main.cpp
#include <windows.h>
#include <cstring>
#include <time.h>
#include <math.h>
#include "Function/MaxMinAvg.hpp"
#include "Class/Valueable/Valueable.hpp"
#include "Class/Player/PlayerList.cpp"
#include "Class/Player/Player.cpp"
#include "Class/Card/CardList.cpp"
#include "Class/Card/Card.cpp"
#include "Class/Table/Table.cpp"
#include "Class/Game/game.cpp"
#include "Class/Ability/Ability.cpp"
// #include "Class/Ability/Quadruple.cpp"
// #include "Class/Ability/Quarter.cpp"
// #include "Class/Ability/Reroll.cpp"
// #include "Class/Ability/SwapCard.cpp"
// #include "Class/Ability/Switch.cpp"
// #include "Class/Ability/ReverseDirection.cpp"
// #include "Class/Ability/Abilityless.cpp"
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

#include <vector>
#include <iostream>
using namespace std;

void clear_screen(){
    #ifdef __linux__
        printf("\033[2J");
    	printf("\033[0;0f");
    #else
        system("CLS");
    #endif
}


int main(){
    Player tempPlayer;
    int choosegame=0;
    int round=1;
    string next;
    char* nickname;
    nickname = new char[100];
    string playeropt;
    string temp_actv;
    boolean valid = false;
    vector <string> activity;
    string enter;
    boolean end = false;
    int pWin;
    int game_total = 0;
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
    CardList<Card> cards = CardList<Card>();
    CardList<Card> default_deck("POKER");
    float max;
    Game<Card> *game;
    // Ability *ability;
    // Quadruple quadruple;
    // Quarter quarter;
    // Reroll reroll;
    // // SwapCard swapCard;
    // // Switch switch_;
    // ReverseDirection reverseDirection;  
    vector<int> abilityId;
    vector<int> selectedAbility;

    do {
        cout << "Pilih Game: " << endl;
        cout << "1. Poker" << endl;
        cout << "2. cangkul" << endl;
        cout << ">> ";
        cin >> choosegame;
        if (choosegame == 1){
            cout << "Pilih opsi untuk membentuk deck!" << endl;
            cout << "1. Random" << endl;
            cout << "2. Input dari file" << endl;
            cout << ">> ";
            cin >> choosegame;
            game = new Game<Card>(4, "POKER"); // 7 pemain
            // default_deck = game->getDeck();

            for (int i = 1; i <= 7; i++){
                abilityId.push_back(i);
            }
            for (int i = 0; i < 7; i++){
                int index = rand() % abilityId.size();
                selectedAbility.push_back(abilityId[index]);
                abilityId.erase(abilityId.begin() + index);
            }
            
            Player player;
            if (choosegame == 1) {
                for (int i = 0; i < game->getTotalPlayer(); i++){
                    cout << "Halo player " << i + 1 << " Silahkan Masukkan Nickname Anda ! (Maksimal 100 huruf)" << endl;
                    cout << ">> ";
                    cin >> nickname;
                    player = game->getPlayer(i);
                    player.setName(nickname);
                    game->setPlayer(i,player);
                    
                }
                for (int i = 3; i > 0; i--){
                    clear_screen();
                    cout << "Game will start in " << i << endl;
                    Sleep(1000);
                }
            while(!end) {
                // Reset
                game->start(2); // 2 kartu
                game->nextRound();

                game_total++;
                activity.push_back("Game ke-" + to_string(game_total));
                while(round<7){ 
                        for (int i = 0; i < game->getTotalPlayer(); i++){
                            valid = false;
                            while(!valid){
                                for (auto i = activity.begin(); i != activity.end(); ++i){
                                    cout << *i << endl;
                                }
                                valid = true;
                                cout << "Sekarang adalah giliran ";
                                cout << game->getPlayer(i).getName();
                                cout << " Anda memiliki kartu:" << endl;
                                game->getPlayer(i).printHand();
                                cout << "Kartu di meja :" << endl;
                                game->Table::print();
                                cout << ". Double" << endl;
                                cout << ". Next" << endl;
                                cout << ". Half" << endl;
                                if (round >= 2){
                                cout << ". Ability" << endl; 
                                }
                                cout << " Pilih opsi anda! " << endl;
                                cout << ">> ";
                                cin >> playeropt;
                                if (playeropt == "Double"){
                                    temp_actv = game->getPlayer(i).getName();
                                    temp_actv += " melakukan DOUBLE! Poin hadiah naik dari " + to_string(game->getValue()) + " Menjadi " + to_string(game->getValue() * 2);
                                    game->setReward(game->getValue() * 2);
                                    activity.push_back(temp_actv);
                                } else if (playeropt == "Next"){
                                } else if (playeropt == "Half"){
                                    temp_actv = game->getPlayer(i).getName();
                                    temp_actv += " melakukan Half! Poin hadiah turun dari " + to_string(game->getValue()) + " Menjadi " + to_string(game->getValue() / 2);
                                    game->setReward(game->getValue() / 2);
                                    activity.push_back(temp_actv);
                                } else if (playeropt == "QUADRUPLE" || playeropt == "QUARTER" || playeropt == "RE-ROLL" || playeropt == "REVERSE" || playeropt == "SWAP" || playeropt == "SWITCH" || playeropt == "ABLITYLESS"){
                                    bool use = game->getPlayer(i).isUsingAbility();
                                    if (playeropt == "QUADRUPLE"){
                                        if(game->getPlayer(i).getAbility() == 2){
                                            if(!use){
                                                //use ability here
                                                // game->getPlayer(i).useAbility();
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                        
                                    } else if (playeropt == "QUARTER"){
                                        if(game->getPlayer(i).getAbility() == 3){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    } else if (playeropt == "RE-ROLL"){
                                        if(game->getPlayer(i).getAbility() == 1){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    } else if (playeropt == "REVERSE" && !use) {
                                        if(game->getPlayer(i).getAbility() == 4){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    } else if (playeropt == "SWAP" && !use){
                                        if(game->getPlayer(i).getAbility() == 5){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    } else if (playeropt == "SWITCH" && !use){
                                        if(game->getPlayer(i).getAbility() == 6){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    } else if (playeropt == "ABLITYLESS" && !use ) {
                                        if(game->getPlayer(i).getAbility() == 7){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                game->getPlayer(i).printPesan2(playeropt);
                                            }
                                        }else{
                                            game->getPlayer(i).printPesan(playeropt);
                                        }
                                    }

                                } else {
                                    cout << "Command tidak valid atau ability tersebut bukan punyamu!" << endl;
                                    valid = false;
                                }
                                cout << "input apapun untuk melanjutkan..." << endl;
                                cout << ">> ";
                                cin >> enter;
                                clear_screen();
                            }
                            
                        }

                    
                    // cout << "Next Round: (Y/n)" << endl;
                    // cin >> next;
                    // if(next=="Y" || next=="y"){
                    // }
                if (round < 5) {
                    game->nextRound();
                }
                clear_screen();  
                round++;
                activity.clear(); 
                activity.push_back(temp_actv);
                }
                for (int i = 0; i < game->getTotalPlayer(); i++){ 
                    cards.setCardsList(game->getPlayer(i).getHand(), game->getCards());
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
                        
                    if (i == 0){
                        max = combination->getValue();
                        pWin = i;
                    }
                    else if (max < combination->getValue()) {
                            max = combination->getValue();
                            pWin = i;
                            // Bandingin Rules di sini
                        }
                    }
                // Setscore
                cout << "Player " << game->getPlayer(pWin).getName() << " memenangkan pertandingan!" << endl;
                player = game->getPlayer(pWin);
                player.setScore(player.getValue() + game->getValue());
                cout << "Player " << player.getName() << " mendapatkan " << game->getValue() << " poin!" << endl;
                game->setPlayer(pWin, player);
                
                for (int i = 0; i < game->getTotalPlayer(); i++){
                    cout << "Score Player " << game->getPlayer(i).getName() << " : " << game->getPlayer(i).getValue() << endl;
                        if (game->getPlayer(i).getValue() >= pow(2, 32)) {
                            end = true;
                            break;
                        }
                    player = game->getPlayer(i);
                    player.removeHand();
                    game->setPlayer(i,player);
                    }

                // Reset
                game->setReward(64);
                activity.clear();
                default_deck.shuffle();
                game->setDeck(default_deck);
                game->setTable(CardList<Card>());
                for (int i = 0; i < game->getTotalPlayer(); i++){
                    tempPlayer = game->getPlayer(i);
                    tempPlayer.setHand(CardList<Card>());
                    game->setPlayer(i, tempPlayer);
                }
                game->setRound(0);
                round = 1;
            }
            
            clear_screen();
            cout << "Permainan Telah berakhir! Player " << game->getPlayer(pWin).getName() <<  "Memenangkan pertandingan!" << endl;
            cout << ">> ";
            cin >> enter;
            if (enter == "Y" || enter == "y") {
                end = false;
            } else if (enter == "N" || enter == "n") {
                end = true;
            } else {
                throw InvalidInputException();
            }
            delete game;
            }
        } else if (choosegame == 2) {
            
        }
    } while(!end);
    return 0;
}