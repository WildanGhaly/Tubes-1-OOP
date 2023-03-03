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
    
    HighCard highCard;
    Pair pair;
    ThreeOfKind threeOfKind;
    // Straight straight;
    Flush flush;
    FullHouse fullHouse;
    FourOfKind fourOfKind;
    // StraightFlush straightFlush;

    Card c1(5,0);
    Card c2(1,1);
    Card c3(10,3);
    Card c4(10,2);
    Card c5(13,3);
    Card c6(2,2);
    Card c7(3,3);
    vector<Card> cards(7);
    cards[0] = c1;
    cards[1] = c2;
    cards[2] = c3;
    cards[3] = c4;
    cards[4] = c5;
    cards[5] = c6;
    cards[6] = c7;

    card = &highCard;
    card->setCards(cards);
    card->computeScore();

    card = &pair;
    card->setCards(cards);
    card->setScore(highCard.getScore());
    card->computeScore();

    card = &threeOfKind;
    card->setCards(cards);
    card->setScore(pair.getScore());
    card->computeScore();

    // card = &straight;
    // card->setCards(cards);
    // card->setScore(threeOfKind.getScore());
    // card->computeScore();

    card = &flush;
    card->setCards(cards);
    card->setScore(threeOfKind.getScore());
    card->computeScore();

    card = &fullHouse;
    card->setCards(cards);
    card->setScore(flush.getScore());
    card->computeScore();

    card = &fourOfKind;
    card->setCards(cards);
    card->setScore(fullHouse.getScore());
    card->computeScore();

    // card = &straightFlush;
    // card->setCards(cards);
    // card->setScore(fourOfKind.getScore());
    // card->computeScore();
    
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