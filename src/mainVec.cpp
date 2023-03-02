// Halo ges pakabar?
// Ini adalah main.cpp

#include "Class/Game/GameVec.cpp"

int main(){
    std::cout << "Deck before start" << std::endl;
    
    GameVec game(7); // 7 player
    game.print(); // print sebelum

    game.start(6); // 2 kartu
    game.nextRound();
    game.nextRound();
    std::cout << "Deck after start: " << game.getTotalCard() << std::endl;
    
    game.print(); // print setelah

    return 0;
}