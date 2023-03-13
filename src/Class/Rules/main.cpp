#include "RulesImplementation.hpp"
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
    Straight straight;
    Flush flush;
    FullHouse fullHouse;
    FourOfKind fourOfKind;
    StraightFlush straightFlush;

    Card c1(1,0);
    Card c2(2,0);
    Card c3(3,0);
    Card c4(4,0);
    Card c5(5,0);
    Card c6(5,1);
    Card c7(5,2);
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
    cout << "High Card Score = " << card->getScore() << endl;

    card = &pair;
    card->setCards(cards);
    card->setScore(highCard.getScore());
    card->computeScore();
    cout << "Pair Score = " << card->getScore() << endl;

    card = &threeOfKind;
    card->setCards(cards);
    card->setScore(pair.getScore());
    card->computeScore();
    cout << "Three of Kind Score = " << card->getScore() << endl;

    card = &straight;
    card->setCards(cards);
    card->setScore(threeOfKind.getScore());
    card->computeScore();
    cout << "Straight Score = " << card->getScore() << endl;

    card = &flush;
    card->setCards(cards);
    card->setScore(straight.getScore());
    card->computeScore();
    cout << "Flush Score = " << card->getScore() << endl;

    card = &fullHouse;
    card->setCards(cards);
    card->setScore(flush.getScore());
    card->computeScore();
    cout << "Full House Score = " << card->getScore() << endl;

    card = &fourOfKind;
    card->setCards(cards);
    card->setScore(fullHouse.getScore());
    card->computeScore();
    cout << "Four of Kind Score = " << card->getScore() << endl;

    card = &straightFlush;
    card->setCards(cards);
    card->setScore(fourOfKind.getScore());
    card->computeScore();
    cout << "Straight Flush Score = " << card->getScore() << endl;
    
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