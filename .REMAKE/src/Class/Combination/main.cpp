#include "Combination.cpp"
#include "SubCombination/HighCard/HighCard.cpp"
#include "SubCombination/Pair/Pair.cpp"
#include "SubCombination/TwoPair/TwoPair.cpp"
#include "SubCombination/ThreeOfKind/ThreeOfKind.cpp"
#include "SubCombination/Straight/Straight.cpp"
#include "SubCombination/Flush/Flush.cpp"
#include "SubCombination/FullHouse/FullHouse.cpp"
#include "SubCombination/FourOfKind/FourOfKind.cpp"
#include "SubCombination/StraightFlush/StraightFlush.cpp"

int main(){
    Combination *combination;
    
    Card c1(3, 1); // kiri warna, kanan angka
    Card c2(0, 1); 
    Card c3(0, 3);
    Card c4(3, 3);
    Card c5(0, 4);
    Card c6(2, 4);
    Card c7(0, 4);

    CardList<Card> cards = CardList<Card>();
    cards << c1 << c2 << c3 << c4 << c5 << c6 << c7;

    cout << "=== Daftar Kartu ===" << endl;
    cards.sortByNumberAndColor();
    cards.print();
    cout << "====================" << endl << endl;

    HighCard highCard;
    highCard.setCards(cards);

    Pair pair;
    pair.setCards(cards);

    TwoPair twoPair;
    twoPair.setCards(cards);

    ThreeOfKind threeOfKind;
    threeOfKind.setCards(cards);

    Straight straight;
    straight.setCards(cards);

    Flush flush;
    flush.setCards(cards);

    FullHouse fullHouse;
    fullHouse.setCards(cards);

    FourOfKind fourOfKind;
    fourOfKind.setCards(cards);

    StraightFlush straightFlush;
    straightFlush.setCards(cards);

    combination = &highCard;
    combination->computeScore();
    cout << "High Card      : " << combination->getPoint() << endl;

    combination = &pair;
    combination->setPoint(highCard.getPoint());
    combination->computeScore();
    cout << "Pair           : " << combination->getPoint() << endl;

    combination = &twoPair;
    combination->setPoint(pair.getPoint());
    combination->computeScore();
    cout << "Two Pair       : " << combination->getPoint() << endl;

    combination = &threeOfKind;
    combination->setPoint(twoPair.getPoint());
    combination->computeScore();
    cout << "Three of Kind  : " << combination->getPoint() << endl;

    combination = &straight;
    combination->setPoint(threeOfKind.getPoint());
    combination->computeScore();
    cout << "Straight       : " << combination->getPoint() << endl;

    combination = &flush;
    combination->setPoint(straight.getPoint());
    combination->computeScore();
    cout << "Flush          : " << combination->getPoint() << endl;

    combination = &fullHouse;
    combination->setPoint(flush.getPoint());
    combination->computeScore();
    cout << "Full House     : " << combination->getPoint() << endl;

    combination = &fourOfKind;
    combination->setPoint(fullHouse.getPoint());
    combination->computeScore();
    cout << "Four of Kind   : " << combination->getPoint() << endl;

    combination = &straightFlush;
    combination->setPoint(fourOfKind.getPoint());
    combination->computeScore();
    cout << "Straight Flush : " << combination->getPoint() << endl;

    return 0;
}