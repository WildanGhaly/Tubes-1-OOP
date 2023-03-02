// Halo ges pakabar?
// Ini adalah main.cpp

#include "Class/Game/GameVec.cpp"

int main(){
    int chooseGame=0;
    int round=0;
    std::string next;
    do{
        cout << "Pilih Game: " << endl;
        cout << "1. Poker" << endl;
        cout << "2. camgkul" << endl;
        cout << ">> ";
        cin >> chooseGame;
        if(chooseGame == 1){
        std::cout << "Deck before start" << std::endl;
        GameVec game(7); // 7 player
        // game.print(); // print sebelum
        game.start(2); // 2 kartu
        while(round<5){ 
            game.nextRound();
            std::cout << "Next Round: (Y/n)" << std::endl;
            std::cin >> next;
            game.getTable().print();
            if(next=="Y" || next=="y"){
                round++;
            }
        }

        std::cout << "Deck after start: " << game.getTotalCard() << std::endl;
        game.getTable().print();
        }
    }while(true);
    return 0;
}