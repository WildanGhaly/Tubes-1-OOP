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

    Rules *card;
    
    // HighCard highCard;
    Pair pair;
    ThreeOfKind threeOfKind;
    FullHouse fullHouse;

    Card c1(10,0);
    Card c2(10,1);
    Card c3(10,2);
    Card c4(2,1);
    Card c5(11,1);
    Card c6(12,3);
    Card c7(1,0);
    vector<Card> cards(7);
    cards[0] = c1;
    cards[1] = c2;
    cards[2] = c3;
    cards[3] = c4;
    cards[4] = c5;
    cards[5] = c6;
    cards[6] = c7;

    // highCard.setCards(cards);
    // card = &highCard;
    // card->computeScore();

    threeOfKind.setCards(cards);
    card = &threeOfKind;
    card->computeScore();

    cout << "Score ToK: " << card->getScore() << endl;

    
    fullHouse.setCards(cards);
    card = &fullHouse;
    card->computeScore();
    cout << "Score fullhouse: " << card->getScore() << endl;
    
    // Rules *rules = &highCard;
    std::cout << "\n Color = " << card->getCard(0).getColor() << std::endl;
    card->print();
    // std::cout << "\n Color = " << rules->getCard(0).getColor() << std::endl;
    // std::cout << "\n Color = " << rules->getCard(0).getColorAsString() << std::endl;

    


    return 0;
}

// int main(){
//     int a = 2;
//     int c = 13;
//     float b = a * 0.3 + c;
//     std::cout << b << std::endl;
//     return 0;
// }