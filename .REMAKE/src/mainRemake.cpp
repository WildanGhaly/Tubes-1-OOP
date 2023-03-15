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
#include "Class/Ability/Quadruple.cpp"
#include <fstream>
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
    int path=0;
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
    Ability *ability;
    Quadruple quadruple;
    // Quarter quarter;
    // Reroll reroll;
    // SwapCard swapCard;
    // Switch switch_;
    // ReverseDirection reverseDirection;  
    vector<int> abilityId;
    vector<int> selectedAbility;
    
    //buat file
    int color;
    int number;
    string fileName;
    //buat file


    do {
        cout << "Pilih opsi untuk membentuk deck!" << endl;
        cout << "1. Random" << endl;
        cout << "2. Input dari file" << endl;
        cout << ">> ";
        cin >> path;
        if (path == 1){
            game = new Game<Card>(7, "POKER"); // 7 pemain
            // default_deck = game->getDeck();
        } else if(path==2){
            cout << "Masukkan nama file: ";
            cin >> fileName;

            ifstream infile ("../test/" + fileName);
            if(infile.fail()){
                throw FileNotExistException();
            }
            if(infile.is_open()){
                while(!infile.eof()){
                    infile >> color >> number;
                    cards << Card(color, number);
                }
                infile.close();
            }
            cout << "=== Daftar Kartu ===" << endl;
            cards.sortByNumberAndColor();
            cards.print();
            game = new Game<Card>(7, "POKER");
            game->setDeck(cards);   
            }
            Player player;
            cout << "Pilih Game: " << endl;
            cout << "1. Poker" << endl;
            cout << "2. Capsa" << endl;
            cout << ">> ";
            cin >> choosegame;
            if (choosegame== 1) {
                for (int i = 0; i < game->getTotalPlayer(); i++){
                    cout << "Halo player " << i + 1 << " Silahkan Masukkan Nickname Anda ! (Maksimal 100 huruf)" << endl;
                    cout << ">> ";
                    cin >> nickname;
                    player = game->getPlayer(i);
                    player.setName(nickname);
                    game->setPlayer(i,player);
                    abilityId.push_back(i);
                    
                }
                for (int i = 3; i > 0; i--){
                    clear_screen();
                    cout << "Game will start in " << i << endl;
                    Sleep(1000);
                }
                for (int i = 0; i < 7; i++){
                int index = rand() % abilityId.size();
                selectedAbility.push_back(abilityId[index]);
                player = game->getPlayer(i);
                // player.setAbility(selectedAbility[i]);
                player.setAbility(2);
                game->setPlayer(i,player);
                abilityId.erase(abilityId.begin() + index);
                
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
                                    // bool use = game->getPlayer(i).isUsingAbility();
                                    if (playeropt == "QUADRUPLE"){
                                        ability=&quadruple;
                                        bool use = ability->useAbility(*game, game->getPlayer(i).getAbility(),i);
                                        if(use){
                                            temp_actv = game->getPlayer(i).getName();
                                            temp_actv += " melakukan QUADRUPLE! Poin hadiah naik dari " + to_string(game->getValue()/4) + " Menjadi " + to_string(game->getValue());
                                            activity.push_back(temp_actv);
                                        }else{
                                            valid = false;
                                        }
                                        
                                    } else if (playeropt == "QUARTER"){

                                        // if(game->getPlayer(i).getAbility() == 3){
                                        //     if(!use){
                                        //         // ability = &quarter;
                                        //         // ability->useAbility();
                                        //         temp_actv = game->getPlayer(i).getName();
                                        //         temp_actv += " melakukan QUARTER! Poin hadiah naik dari " + to_string(game->getValue()) + " Menjadi " + to_string(game->getValue() / 4);
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        // }
                                    } else if (playeropt == "RE-ROLL"){
                                        
                                        // if(game->getPlayer(i).getAbility() == 1){
                                        //     if(!use){
                                        //         // ability = &reroll;
                                        //         // ability->useAbility();
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        //     valid = false;
                                        // }
                                    } else if (playeropt == "REVERSE") {
                                        // if(game->getPlayer(i).getAbility() == 4){
                                        //     if(!use){
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        //     valid = false;
                                        // }
                                    } else if (playeropt == "SWAP"){
                                        // if(game->getPlayer(i).getAbility() == 5){
                                        //     if(!use){
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        //     valid = false;
                                        // }
                                    } else if (playeropt == "SWITCH"){
                                        // if(game->getPlayer(i).getAbility() == 6){
                                        //     if(!use){
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        //     valid = false;
                                        // }
                                    } else if (playeropt == "ABLITYLESS") {
                                        // if(game->getPlayer(i).getAbility() == 7){
                                        //     if(!use){
                                        //         //USE ABILITY
                                        //     }else{
                                        //         game->getPlayer(i).printPesan2(playeropt);
                                        //         valid = false;
                                        //     }
                                        // }else{
                                        //     game->getPlayer(i).printPesan(playeropt);
                                        //     valid = false;
                                        // }
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
            } else if (choosegame == 2) {
            
            int ii = 0;
            int winnerCapsaPoint;
            bool done;
            float value[3];
            int swap1, swap2;
            float playerValue[4][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
            game = new Game<Card>(4, "POKER");
            game->start(13);
            while (ii < 4){
                done = false;
                while (!done){
                    cout << "Player " << ii+1 << " turn" << endl;
                    cout << "Kartu saat in: " << endl;
                    game->getPlayer(ii).printCapsa();
                    cout << "Kartu yang akan ditukar: " << endl;
                    cout << "Urutan kartu: " << endl;
                    cout << "0  1  2" << endl;
                    cout << "3  4  5  6  7" << endl;
                    cout << "8  9  10 11 12" << endl;
                    cout << "Contoh input: 1 2" << endl;
                    cout << "Jika tidak ada kartu yang akan ditukar, masukkan 0 0" << endl;
                    cin >> swap1 >> swap2;
                    cin.ignore();

                    if (swap1 == 0 && swap2 == 0){
                        done = true;
                    } else if (swap1 < -1 || swap1 > 12 || swap2 < -1 || swap2 > 12){
                        cout << "Input tidak valid" << endl;
                        // Exception handling
                    } else {
                        tempPlayer = game->getPlayer(ii);
                        tempPlayer.swapCardPosition(swap1, swap2);
                        game->setPlayer(ii, tempPlayer);
                    }
                }
                for (int j = 0; j < 3; j++){
                    value[j] = 0.0;
                }

                for (int k = 0; k < 3; k++){
                    if (k == 0) {
                        cards << game->getPlayer(ii).getHand(0) << game->getPlayer(ii).getHand(1) << game->getPlayer(ii).getHand(2);
                    } else if (k == 1) {
                        cards << game->getPlayer(ii).getHand(3) << game->getPlayer(ii).getHand(4) << game->getPlayer(ii).getHand(5) << game->getPlayer(ii).getHand(6) << game->getPlayer(ii).getHand(7);
                    } else if (k == 2) {
                        cards << game->getPlayer(ii).getHand(8) << game->getPlayer(ii).getHand(9) << game->getPlayer(ii).getHand(10) << game->getPlayer(ii).getHand(11) << game->getPlayer(ii).getHand(12);
                    }

                    cards.sortByNumberAndColor();

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
                    playerValue[ii][0] = value[0];
                    playerValue[ii][1] = value[1];
                    playerValue[ii][2] = value[2];
                    ii++;
                } else {
                    cout << "Kartu belum sesuai aturan capsa" << endl;
                }

            }

            for (int l = 0; l < 4; l++) {
                for (int m = 0; m < 4; m++) {
                    if (l != m) {
                        for (int n = 0; n < 3; n++) {
                            if (playerValue[l][n] > playerValue[m][n]) {
                                tempPlayer = game->getPlayer(l);
                                tempPlayer.addScore(10);
                                game->setPlayer(l, tempPlayer);
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
                cout << "Player " << o+1 << ": " << game->getPlayer(o).getValue() << endl;
                game->getPlayer(o).printCapsa();
            } 

            winnerCapsaPoint = find_max(game->getPlayer(0).getValue(), game->getPlayer(1).getValue(), game->getPlayer(2).getValue(), game->getPlayer(3).getValue());
            cout << "Pemenangnya adalah: " << endl;
            for (int p = 0; p < 4; p++) {
                if (game->getPlayer(p).getValue() == winnerCapsaPoint) {
                    cout << "Player " << p+1 << " Dengan poin " << game->getPlayer(p).getValue() << endl;
                }
            }
            
            cout << "Apakah anda ingin bermain lagi? (Y/N)" << endl;
            cin >> enter;
            cin.ignore();
            if (enter == "Y" || enter == "y") {
                end = false;
            } else if (enter == "N" || enter == "n") {
                end = true;
            } else {
                throw InvalidInputException();
            }


            delete game;
            
        }
    } while(!end);
    return 0;
}