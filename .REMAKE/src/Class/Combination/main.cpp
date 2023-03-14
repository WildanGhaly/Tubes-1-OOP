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
#include "../../Exception/Exception.h"

int main(){
    int count=0;
    CardList<Card> cards = CardList<Card>();
    int color;
    int number;
    while(count<10){
            count++;
        try{
            cout <<"Loop : " <<count << endl;
            Combination *combination;
            for(int i=0; i < 7; i++){
                cout << "Color : ";
                cin >> color;
                cout << "Number: ";
                cin >> number;
                Card c(color, number);
                cards << c;
            }


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
        } catch (CardColorException e){
            cout << e.what();
        } catch (CardNumberException e){
            cout << e.what();
        }
    }
    
}