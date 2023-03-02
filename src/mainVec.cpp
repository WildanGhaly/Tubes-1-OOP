// Halo ges pakabar?
// Ini adalah main.cpp
#include <windows.h>
#include <cstring>
#include "Class/Game/GameVec.cpp"
using namespace std;

int main(){
    int choosegame=0;
    int round=0;
    string next;
    char* nickname;
    nickname = new char[100];
    string blank;

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
                while(round<5){ 
                    for (int i = 0; i < 7; i++){
                        cout << "Sekarang adalah giliran ";
                        cout << game.getPlayers().getPlayer(i).getNickname();
                        cout << "Anda memiliki kartu:" << endl;
                        game.getPlayer(i).print();
                        cout << "Kartu di meja :" << endl;
                        game.getTable().print();
                        cout << "1. Double" << endl;
                        cout << "2. Next" << endl;
                        cout << "3. Half" << endl;
                        cout << "4. Ability" << endl;
                        cout << " Pilih opsi anda! " << endl;
                        cout << ">> ";
                        cin >> blank;
                        system("CLS");
                        
                    }
                
                    game.nextRound();
                    cout << "Next Round: (Y/n)" << endl;
                    cin >> next;
                    if(next=="Y" || next=="y"){
                        round++;
                        system("CLS");
                    }
                }
            }
        }
    } while(true);
    return 0;
}