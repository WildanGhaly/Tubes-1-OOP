#include "RulesImplementation.hpp"
#include "../Game/GameVec.hpp"
#include "../Game/GameVec.cpp"
#include <iostream>


int main(){
    std::cout << "Deck before start" << std::endl;
    
    GameVec game(7); // 7 player
    game.print(); // print sebelum

    game.start(2); // 2 kartu
    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();
    std::cout << "Deck after start: " << game.getTotalCard() << std::endl;
    
    game.print(); // print setelah

    std::cout << "================================= BATAS SUCI =================================" << std::endl;

    HighCard highCard(game.getTable(), game.getPlayers().getPlayer(0));
    highCard.computeScore();

    Rules *rules = &highCard;
    std::cout << "\n Color = " << rules->getCard(0).getColor() << std::endl;
    rules->print();
    std::cout << "\n Color = " << rules->getCard(0).getColor() << std::endl;
    std::cout << "\n Color = " << rules->getCard(0).getColorAsString() << std::endl;


    return 0;
}

// int main(){
//     int a = 2;
//     int c = 13;
//     float b = a * 0.3 + c;
//     std::cout << b << std::endl;
//     return 0;
// }