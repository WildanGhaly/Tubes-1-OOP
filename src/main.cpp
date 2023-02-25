// Halo ges pakabar?
// Ini adalah main.cpp

#include "Class/Game/Game.cpp"

int main(){
    std::cout << "Deck before start" << std::endl;
    
    Game game(7); // 7 player
    game.print(); // print sebelum

    game.start(2); // 2 kartu
    std::cout << "Deck after start: " << game.getTotalCard() << std::endl;
    
    game.print(); // print setelah

    return 0;
}