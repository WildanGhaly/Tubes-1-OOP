#include "Combination.cpp"
#include "../Card/CardList.cpp"
#include "../Card/Card.cpp"
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
    cin.exceptions(ios_base::failbit);
    while(count<10){
        count++;
        cards = CardList<Card>();
        try{
            cout <<"Loop : " <<count << endl;
            Combination *combination;
            for(int i=0; i < 7; i++){
                while(true){
                    try{
                        cout << "Color[" << i+1 << "] : ";
                        cin >> color;
                        cout << "Number[" << i+1 <<"] : ";
                        cin >> number;
                        if(!cin.fail()){
                            break;
                        }
                    }catch (const ios_base::failure &) {
                        cout  << "\033[1;31mPlease enter numbers only!\033[0m" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
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
            cout << "High Card      : " << combination->getValue() << endl;

            combination = &pair;
            combination->setPoint(highCard.getValue());
            combination->computeScore();
            cout << "Pair           : " << combination->getValue() << endl;

            combination = &twoPair;
            combination->setPoint(pair.getValue());
            combination->computeScore();
            cout << "Two Pair       : " << combination->getValue() << endl;

            combination = &threeOfKind;
            combination->setPoint(twoPair.getValue());
            combination->computeScore();
            cout << "Three of Kind  : " << combination->getValue() << endl;

            combination = &straight;
            combination->setPoint(threeOfKind.getValue());
            combination->computeScore();
            cout << "Straight       : " << combination->getValue() << endl;

            combination = &flush;
            combination->setPoint(straight.getValue());
            combination->computeScore();
            cout << "Flush          : " << combination->getValue() << endl;

            combination = &fullHouse;
            combination->setPoint(flush.getValue());
            combination->computeScore();
            cout << "Full House     : " << combination->getValue() << endl;

            combination = &fourOfKind;
            combination->setPoint(fullHouse.getValue());
            combination->computeScore();
            cout << "Four of Kind   : " << combination->getValue() << endl;

            combination = &straightFlush;
            combination->setPoint(fourOfKind.getValue());
            combination->computeScore();
            cout << "Straight Flush : " << combination->getValue() << endl;
        } catch (exception& e){
            cout << e.what();
        }
    }
    
}