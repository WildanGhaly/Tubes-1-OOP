// Halo ges pakabar?
// Ini adalah main.cpp
#include <windows.h>
#include <cstring>
#include "Class/Game/GameVec.cpp"
#include "Class/Table/Table.hpp"
#include <vector>
using namespace std;

int main(){
    int choosegame=0;
    int round=0;
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
    Table table;

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
            GameVec game(7); // 7 pemain
            game.start(2); // 2 kartu
            game.nextRound();
            PlayerVec player;
            if (choosegame == 1) {
                for (int i = 0; i < 7; i++){
                    cout << "Halo player " << i + 1 << " Silahkan Masukkan Nickname Anda ! (Maksimal 100 huruf)" << endl;
                    cout << ">> ";
                    cin >> nickname;
                    player = game.getPlayer(i);
                    player.setNickname(nickname);
                    game.setPlayer(i, player);
                    
                }
                for (int i = 3; i > 0; i--){
                    system("CLS");
                    cout << "Game will start in " << i << endl;
                    Sleep(1000);
                }
            while(!end) {
                game_total++;
                activity.push_back("Game ke-" + to_string(game_total));
                while(round<2){ 
                        for (int i = 0; i < 7; i++){
                            valid = false;
                            while(!valid){
                                for (auto i = activity.begin(); i != activity.end(); ++i){
                                    cout << *i << endl;
                                }
                                valid = true;
                                cout << "Sekarang adalah giliran ";
                                cout << game.getPlayer(i).getNickname();
                                cout << " Anda memiliki kartu:" << endl;
                                game.getPlayer(i).print();
                                cout << "Kartu di meja :" << endl;
                                game.Table::print();
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
                                    temp_actv = game.getPlayer(i).getNickname();
                                    temp_actv += " melakukan DOUBLE! Poin hadiah naik dari " + to_string(game.getScore()) + " Menjadi " + to_string(game.getScore() * 2);
                                    game.setScore(game.getScore() * 2);
                                    activity.push_back(temp_actv);


                                } else if (playeropt == "Next"){
                                    
                                } else if (playeropt == "Half"){
                                    temp_actv = game.getPlayer(i).getNickname();
                                    temp_actv += " melakukan Half! Poin hadiah turun dari " + to_string(game.getScore()) + " Menjadi " + to_string(game.getScore() / 2);
                                    game.setScore(game.getScore() / 2);
                                    activity.push_back(temp_actv);


                                } else if (playeropt == "QUADRUPLE" || playeropt == "QUARTER" || playeropt == "RE-ROLL" || playeropt == "REVERSE" || playeropt == "SWAP" || playeropt == "SWITCH" || playeropt == "ABLITYLESS"){
                                    bool use = game.getPlayer(i).isUsingAbility();
                                    if (playeropt == "QUADRUPLE"){
                                        if(game.getPlayer(i).getAbilityID() == 1){
                                            if(!use){

                                            }else{
                                                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE."<<endl;
                                                cout<< "Silahkan lakukan perintah lain."<<endl;
                                            }
                                        }else{
                                            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE."<<endl;
                                            cout<< "Silahkan lakukan perintah lain."<<endl;
                                        }
                                        game.getPlayers().getPlayer(i);
                                    } else if (playeropt == "QUARTER"){
                                        if(game.getPlayer(i).getAbilityID() == 2){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER."<<endl;
                                                cout<< "Silahkan lakukan perintah lain."<<endl;
                                            }
                                        }else{
                                            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER."<<endl;
                                            cout<< "Silahkan lakukan perintah lain."<<endl;
                                        }
                                        game.getPlayers().getPlayer(i);
                                    } else if (playeropt == "RE-ROLL"){
                                        if(game.getPlayer(i).getAbilityID() == 3){
                                            if(!use){
                                                //USE ABILITY
                                            }else{
                                                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability RE-ROLL."<<endl;
                                                cout<< "Silahkan lakukan perintah lain."<<endl;
                                            }
                                        }else{
                                            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE."<<endl;
                                            cout<< "Silahkan lakukan perintah lain."<<endl;
                                        }
                                } 

                                    else if (playeropt == "REVERSE" && !use) {

                                    } else if (playeropt == "SWAP" && !use){

                                    } else if (playeropt == "SWITCH" && !use){

                                    } else if (playeropt == "ABLITULESS" && !use ) {

                                    }

                                } else {
                                    cout << "Command tidak valid atau ability tersebut bukan punyamu!" << endl;
                                    valid = false;
                                }
                                cout << "input apapun untuk melanjutkan..." << endl;
                                cout << ">> ";
                                cin >> enter;
                                system("CLS");
                            }
                            
                        }

                    game.nextRound();
                    cout << "Next Round: (Y/n)" << endl;
                    cin >> next;
                    if(next=="Y" || next=="y"){
                        round++;
                        system("CLS");
                    }
                }
                for (int i = 0; i < game.getTotalPlayer(); i++){ 
                        // Bandingin Rules di sini
                        if ("Max < Rules") {
                            pWin = i;
                            
                        }
                    }
                player = game.getPlayer(pWin);
                player.setScore(player.getScore() + game.getScore());
                game.setPlayer(pWin, player);
                for (int i = 0; i < game.getTotalPlayer(); i++){ 
                        // Bandingin score
                        if ("some player > 2^32") {
                            end = true;
                            break;
                        }
                    }
            }
            for (int i = 0; i < game.getTotalPlayer(); i++){ 
                system("CLS");
                cout << "Permainan Telah berakhir! Player " "game.getPlayers().getPlayer(pWin).setNickname(nickname) Memenangkan pertandingan!" << endl;
                cout << "input apapun untuk melanjutkan..." << endl;
                cout << ">> ";
                cin >> enter;
            }
            
            }
        }
    } while(true);
    return 0;
}