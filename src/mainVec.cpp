// Halo ges pakabar?
// Ini adalah main.cpp
#include <windows.h>
#include <cstring>
#include <fstream>
#include "Class/Game/GameVec.cpp"
#include "Table/Table.hpp"
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
            if (choosegame == 1) {
                for (int i = 0; i < 7; i++){
                    cout << "Halo player " << i + 1 << " Silahkan Masukkan Nickname Anda ! (Maksimal 100 huruf)" << endl;
                    cout << ">> ";
                    cin >> nickname;
                    game.getPlayers().getPlayer(i).setNickname(nickname);
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
                                cout << game.getPlayers().getPlayer(i).getNickname();
                                cout << "Anda memiliki kartu:" << endl;
                                game.getPlayer(i).print();
                                cout << "Kartu di meja :" << endl;
                                game.getTable().print();
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
                                    temp_actv = "game.getPlayers().getPlayer(i).getNickname() ""melakukan DOUBLE! Poin hadiah naik dari " + to_string(table.getScore()) + " Menjadi " + to_string(table.getScore() * 2);
                                    table.setScore(table.getScore() * 2);
                                    activity.push_back(temp_actv);


                                } else if (playeropt == "Next"){
                                    
                                } else if (playeropt == "Half"){
                                    temp_actv = "game.getPlayers().getPlayer(i).getNickname() ""melakukan Half! Poin hadiah turun dari " + to_string(table.getScore()) + " Menjadi " + to_string(table.getScore() / 2);
                                    table.setScore(table.getScore() / 2);
                                    activity.push_back(temp_actv);


                                } else if (playeropt == "this -> Ability"){
                                    if (playeropt == "Quadruple"){
                                        game.getPlayers().getPlayer(i);
                                    } else if (playeropt == "Quarter"){
                                        game.getPlayers().getPlayer(i);
                                    } else if (playeropt == "Reroll"){

                                    } else if (playeropt == "Reverse") {

                                    } else if (playeropt == "Swap"){

                                    } else if (playeropt == "Switch"){

                                    } else if (playeropt == "Abilityless" ) {

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
                for (int i = 0; i < game.getPlayers().getTotalPlayer(); i++){ 
                        // Bandingin Rules di sini
                        if ("Max < Rules") {
                            pWin = i;
                            
                        }
                    }
                game.getPlayers().getPlayer(pWin).setScore(64);
                for (int i = 0; i < game.getPlayers().getTotalPlayer(); i++){ 
                        // Bandingin score
                        if ("some player > 2^32") {
                            end = true;
                            break;
                        }
                    }
            }
            for (int i = 0; i < game.getPlayers().getTotalPlayer(); i++){ 
                system("CLS");
                cout << "Permainan Telah berakhir! Player " "game.getPlayers().getPlayer(pWin).setNickname(nickname) Memenangkan pertandingan!" << endl;
                cout << "input apapun untuk melanjutkan..." << endl;
                cout << ">> ";
                cin >> enter;
            }
            
            }
            if (choosegame == 2) {
                string filename;
                cout << "Masukkan nama file: ";
                cin >> filename;
                ifstream input(filename);
                if (!input) {
                    cerr << "File tidak ditemukan: " << filename << endl;
                    return 1;
                }
                string line;
                while (getline(input, line)) {
                    cout << line << endl;
                }
                input.close();
            }
        }
    } while(true);
    return 0;
}