// Halo ges pakabar?
// Ini adalah main.cpp
#pragma 
#ifdef _WIN32
    #include <windows.h>
    #define DELAYSCR Sleep(1000)
#else
    #include <unistd.h>
    #define DELAYSCR usleep(1000000)    
#endif
#include <cstring>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
#include "Function/DoubleValue.hpp"
#include "Function/MaxMinAvg.hpp"
#include "Class/Valueable/Valueable.hpp"
#include "Class/Card/Card.hpp"
#include "Class/Card/CardList.hpp"
#include "Class/Player/Player.hpp"
#include "Class/Player/PlayerList.hpp"
#include "Class/Table/Table.hpp"
#include "Class/Game/Game.hpp"
#include "Class/Ability/Ability.hpp"
#include "Class/Ability/Quadruple.hpp"
#include "Class/Ability/Quarter.hpp"
#include "Class/Ability/Reroll.hpp"
#include "Class/Ability/SwapCard.hpp"
#include "Class/Ability/Switch.hpp"
#include "Class/Ability/ReverseDirection.hpp"
#include "Class/Ability/Abilityless.hpp"
#include "Class/Combination/Combination.hpp"
#include "Class/Combination/SubCombination/HighCard/HighCard.hpp"
#include "Class/Combination/SubCombination/Pair/Pair.hpp"
#include "Class/Combination/SubCombination/TwoPair/TwoPair.hpp"
#include "Class/Combination/SubCombination/ThreeOfKind/ThreeOfKind.hpp"
#include "Class/Combination/SubCombination/Straight/Straight.hpp"
#include "Class/Combination/SubCombination/Flush/Flush.hpp"
#include "Class/Combination/SubCombination/FullHouse/FullHouse.hpp"
#include "Class/Combination/SubCombination/FourOfKind/FourOfKind.hpp"
#include "Class/Combination/SubCombination/StraightFlush/StraightFlush.hpp"

void clear_screen(){
    #ifdef _WIN32
        system("CLS");
    #else
        printf("\033[2J");
    	printf("\033[0;0f");
    #endif
}

int main(){
    system("");
    bool valid = false, end = false, isReversed = false, antiReversed = false, isfile;
    int choosegame = 0, path = 0, round = 1, pWin, game_total = 0, locateReverse = 0, color, number;
    float max, tempMax;
    string next, playeropt, temp_actv, enter, fileName;
    vector <string> activity;
    vector<Player> temp2Players;
    Player tempPlayer;
    char* nickname;
    nickname = new char[100];
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
    Combination *combinations[9] = {&highCard, &pair, &twoPair, &threeOfKind, &straight, &flush, &fullHouse, &fourOfKind, &straightFlush};
    CardList<Card> cards = CardList<Card>();
    CardList<Card> default_deck("POKER");
    Game<Card> *game;
    Ability *ability;
    Quadruple quadruple;
    Quarter quarter;
    Reroll reroll;
    SwapCard swapCard;
    Switch switch_;
    ReverseDirection reverseDirection;  
    Abilityless abilityless;
    PlayerList tempPlayers;

    do {
        try{
        cout << "Pilih opsi untuk membentuk deck!" << endl;
        cout << "1. Random" << endl;
        cout << "2. Input dari file" << endl;
        cout << ">> ";
        Input(path);
        if (path == 1){
            isfile=false;
            game = new Game<Card>(7, "POKER"); // 7 pemain
        } else if(path==2){
            isfile=true;
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
            if(DoubleValue(cards)){
                cards=CardList<Card>();
                throw CardRedundancyException();
            }
            cout << "=== Daftar Kartu ===" << endl;
            cards.sortByNumberAndColor();
            cards.print();
            game = new Game<Card>(7, "POKER");
            game->setDeck(cards);   
        } else {
            throw InvalidInputException();
        }
            Player player;
            cout << "Pilih Game: " << endl;
            cout << "1. Poker" << endl;
            cout << "2. Capsa" << endl;
            cout << ">> ";
            Input(choosegame);
            if (choosegame== 1) {
                if(cards.getTotalCard()<21 && isfile){
                    cards=CardList<Card>();
                    cout << "\033[1;31mException: Minimum cards for poker is 21\033[0m\n";
                    throw CardInsufficientException();
                }
                for (int i = 0; i < game->getTotalPlayer(); i++){
                    cout << "Halo player " << i + 1 << " Silahkan Masukkan Nickname Anda ! (Maksimal 100 huruf)" << endl;
                    cout << ">> ";
                    Input(nickname);
                    player = game->getPlayer(i);
                    player.setName(nickname);
                    game->setPlayer(i,player);
                }
                for (int i = 3; i > 0; i--){
                    clear_screen();
                    cout << "Game will start in " << i << endl;
                    DELAYSCR;
                }
                while(!end) {
                isReversed = false;
                antiReversed = false;
                vector<int> abilityId;
                vector<int> selectedAbility;
                for(int i = 0; i < 7; i++){
                    abilityId.push_back(i);
                }
                srand(time(NULL));
                for (int i = 0; i < 7; i++){
                    int index = rand() % abilityId.size();
                    selectedAbility.push_back(abilityId[index]);
                    player = game->getPlayer(i);
                    player.setAbility(selectedAbility[i]+1);
                    game->setPlayer(i,player);
                    abilityId.erase(abilityId.begin()+index);
                }
                // Reset
                game->start(2); // 2 kartu
                game->nextRound();
                game_total++;
                activity.push_back("Game ke-" + to_string(game_total));
                for (int z = 0; z < 9; z++){
                    combination = combinations[z];
                    combination->setPoint(0);
                }
                while(round<7){ 
                        for (int i = isReversed ? game->getTotalPlayer() - 1 : 0; ((!isReversed) && (i < game->getTotalPlayer())) || ((isReversed) && (i >= 0)); i = i + (isReversed ? -1 : 1)){
                            valid = false;
                            while(!valid){
                                for (auto i = activity.begin(); i != activity.end(); ++i){
                                    cout << *i << endl;
                                }
                                valid = true;
                                cout << "Sekarang adalah giliran ";
                                cout << game->getPlayer(i % game->getTotalPlayer()).getName();
                                cout << " Anda memiliki kartu:" << endl;
                                game->getPlayer(i % game->getTotalPlayer()).printHand();
                                cout << "Kartu di meja :" << endl;
                                game->Table::print();
                                cout << ". Double" << endl;
                                cout << ". Next" << endl;
                                cout << ". Half" << endl;
                                if (round >= 2){
                                cout << ". Ability"<< endl; 
                                cout <<game->getPlayer(i).getAbilityName()<<endl;
                                }
                                cout << " Pilih opsi anda! " << endl;
                                cout << ">> ";
                                cin >> playeropt;
                                if (playeropt == "Double"){
                                    temp_actv = game->getPlayer(i % game->getTotalPlayer()).getName();
                                    temp_actv += " melakukan DOUBLE! Poin hadiah naik dari " + to_string(game->getValue()) + " Menjadi " + to_string(game->getValue() * 2);
                                    game->setReward(game->getValue() * 2);
                                    activity.push_back(temp_actv);
                                } else if (playeropt == "Next"){
                                } else if (playeropt == "Half"){
                                    temp_actv = game->getPlayer(i % game->getTotalPlayer()).getName();
                                    if(game->getValue()==1){
                                        temp_actv += " melakukan Half! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah..";
                                    }else if(game->getValue() / 2 < 1){
                                        game->setReward(1);
                                        temp_actv += " melakukan Half! Poin hadiah tidak bisa turun kurang dari 1";
                                    } else {
                                        temp_actv += " melakukan Half! Poin hadiah turun dari " + to_string(game->getValue()) + " Menjadi " + to_string(game->getValue() / 2);
                                        game->setReward(game->getValue() / 2);
                                    }
                                    // game->setReward(game->getValue() / 2);
                                    activity.push_back(temp_actv);
                                } else if ((playeropt == "QUADRUPLE" || playeropt == "QUARTER" || playeropt == "RE-ROLL" || playeropt == "REVERSE" || playeropt == "SWAP" || playeropt == "SWITCH" || playeropt == "ABILITYLESS") && game->getRound() >= 2){
                                    if (playeropt == "QUADRUPLE"){
                                        ability=&quadruple;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            temp_actv = game->getPlayer(i % game->getTotalPlayer()).getName();
                                            temp_actv += " melakukan QUADRUPLE! Poin hadiah naik dari " + to_string(game->getValue()/4) + " Menjadi " + to_string(game->getValue());
                                            activity.push_back(temp_actv);
                                        }else{
                                            valid = false;
                                        }
                                    } else if (playeropt == "QUARTER"){
                                        ability=&quarter;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(game->getValue()<1){
                                            game->setReward(1);
                                            temp_actv = game->getPlayer(i % game->getTotalPlayer()).getName();
                                            temp_actv += " melakukan QUARTER! Sayangnya poin hadiah tidak bisa turun kurang dari 1";
                                            activity.push_back(temp_actv);
                                        }else{
                                            if(use){
                                                temp_actv = game->getPlayer(i % game->getTotalPlayer()).getName();
                                                temp_actv += " melakukan QUARTER! Poin hadiah turun dari " + to_string(game->getValue()*4) + " Menjadi " + to_string(game->getValue());
                                                activity.push_back(temp_actv);
                                            }else{
                                                valid = false;
                                            }
                                        }
                                    } else if (playeropt == "RE-ROLL"){
                                        ability=&reroll;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            cout << "Melakukan pembuangan kartu yang sedang dimiliki"<<endl;
                                            cout << "Kamu mendapatkan 2 kartu baru yaitu: "<< endl;
                                            game->getPlayer(i % game->getTotalPlayer()).printHand();
                                        }else{
                                            valid = false;
                                        }
                                    } else if (playeropt == "REVERSE") {
                                        ability=&reverseDirection;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            //USE ABILITY
                                            antiReversed = !antiReversed;
                                            cout << "Mengubah arah putaran" << endl;
                                            locateReverse = i % game->getTotalPlayer();
                                            valid = false;
                                        } else {
                                            valid = false;
                                        }
                                    } else if (playeropt == "SWAP"){
                                        ability=&swapCard;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            temp_actv = game->getPlayer(i).getName();
                                            temp_actv += " melakukan SWAP!"; 
                                            activity.push_back(temp_actv);
                                        }else{
                                            valid = false;
                                        }
                                    } else if (playeropt == "SWITCH"){
                                        ability=&switch_;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            temp_actv = game->getPlayer(i).getName();
                                            temp_actv += " melakukan SWITCH!";
                                            activity.push_back(temp_actv);
                                        }else{
                                            valid = false;
                                        }
                                    } else if (playeropt == "ABILITYLESS") {
                                        ability=&abilityless;
                                        bool use = ability->useAbility(*game, game->getPlayer(i % game->getTotalPlayer()).getAbility(),i % game->getTotalPlayer());
                                        if(use){
                                            temp_actv = game->getPlayer(i).getName();
                                            temp_actv += " melakukan ABILITYLESS!";
                                            activity.push_back(temp_actv);
                                        }else{
                                            valid = false;
                                        }
                                    }
                                } else {
                                    cout << "Command tidak valid atau ability tersebut bukan punyamu!" << endl;
                                    valid = false;
                                }
                                cout << "input apapun untuk melanjutkan..." << endl;
                                cout << ">> ";
                                cin >> enter;   
                                // DELAYSCR;
                                clear_screen();
                            }   
                        }
                        if (!isReversed && antiReversed) {
                            temp2Players = game->getPlayers();
                            reverse(temp2Players.begin() + locateReverse + 1, temp2Players.end());
                            rotate(temp2Players.begin(), temp2Players.begin() + 1, temp2Players.end());
                            game->setPlayers(temp2Players);
                            isReversed = true;
                        }
                        temp2Players = game->getPlayers();
                        rotate(temp2Players.begin(), temp2Players.begin() + 1, temp2Players.end());
                        game->setPlayers(temp2Players);
                if (round < 5) {
                    game->nextRound();
                } else {
                    game->addRound();
                }
                clear_screen();  
                round++;
                activity.clear(); 
                activity.push_back(temp_actv);
                }
                for (int j = 0; j < game->getTotalPlayer(); j++){ 
                    cards.setCardsList(game->getPlayer(j).getHand(), game->getCards());
                    tempMax = 0;
                    for (int i = 0; i < 9; i++){
                        combination = combinations[i];
                        if (i == 0){
                            combination->setCards(game->getPlayer(j).getHand());
                        } else {
                            combination->setCards(cards);
                        }
                        combination->setPoint(0);
                        combination->computeScore();
                        tempMax += combination->getValue();
                    }
                    if (j == 0){
                        max = tempMax;
                        pWin = j;
                    }
                    else if (max < tempMax) {
                        max = tempMax;
                        pWin = j;
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
                cout << "Game ke-"<< game_total<<" telah berakhir!!" <<endl;
                cout << "Pilih opsi untuk membentuk deck!" << endl;
                cout << "1. Random" << endl;
                cout << "2. Input dari file" << endl;
                cout << ">> ";
                while(true){
                try{
                Input(path);
                if (path == 1){
                    default_deck.shuffle();
                    game->setDeck(default_deck);
                    break;
                }
                else if (path == 2){
                    while(true){
                    cards=CardList<Card>();
                    try{
                    isfile=true;
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
                    if(DoubleValue(cards)){
                        cards=CardList<Card>();
                        throw CardRedundancyException();
                    }
                    if(cards.getTotalCard()<21 && isfile){
                    cards=CardList<Card>();
                    cout << "\033[1;31mException: Minimum cards for poker is 21\033[0m\n";
                    throw CardInsufficientException();
                    }
                    break;
                    
                    game->setDeck(cards); 
                    }catch(exception& e){
                        cout<<e.what();
                    }
                }  
                break;
                } else {
                    throw InvalidInputException();
                } 
                }catch(InvalidInputException e){
                    cout << e.what();
                }
                }
                
                // default_deck.shuffle();
                // game->setDeck(default_deck);
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
            cout << "Permainan Telah berakhir! Player " << game->getPlayer(pWin).getName() <<  " Memenangkan pertandingan!" << endl;
            cout << "Lanjutkan permainan? (Y/N)"<<endl;
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
            if(cards.getTotalCard()<52 && isfile){
                cards = CardList<Card>();
                cout << "\033[1;31mException: Minimum cards for capsa is 52\033[0m\n";
                throw CardInsufficientException();
            }
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
                clear_screen();
                while (!done){
                    try {
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
                    Input(swap1);
                    Input(swap2);
                    cin.ignore();

                    if (swap1 == 0 && swap2 == 0){
                        done = true;
                    } else if (swap1 < 0 || swap1 > 12 || swap2 < 0 || swap2 > 12){
                        throw InvalidInputException();
                    } else {
                        tempPlayer = game->getPlayer(ii);
                        tempPlayer.swapCardPosition(swap1, swap2);
                        game->setPlayer(ii, tempPlayer);
                    }
                    } catch(InvalidInputException e){
                        cout << e.what();
                        DELAYSCR;
                    }
                    clear_screen();
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
                    for (int l = 0; l < 9; l++){
                        combination = combinations[l];
                        combination->setCards(cards);
                        combination->setPoint(l > 0 ? combinations[l-1]->getValue() : 0);
                        combination->computeScore();
                    }
                    value[k] = combination->getValue();
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
                            } 
                        }
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
        } else {
            throw InvalidInputException();
        }
        }catch(exception& e){
            cout << e.what();
        }
    } while(!end);
    return 0;
}