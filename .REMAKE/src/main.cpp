#include "Class/Combination/Combination.cpp"
#include "Class/Combination/SubCombination/HighCard/HighCard.cpp"
#include "Class/Combination/SubCombination/Pair/Pair.cpp"
#include "Class/Combination/SubCombination/TwoPair/TwoPair.cpp"
#include "Class/Combination/SubCombination/ThreeOfKind/ThreeOfKind.cpp"
#include "Class/Combination/SubCombination/Straight/Straight.cpp"
#include "Class/Combination/SubCombination/Flush/Flush.cpp"
#include "Class/Combination/SubCombination/FullHouse/FullHouse.cpp"
#include "Class/Combination/SubCombination/FourOfKind/FourOfKind.cpp"
#include "Class/Combination/SubCombination/StraightFlush/StraightFlush.cpp"
#include "Exception/Exception.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    try {
        int color;
        int number;
        CardList<Card> cards = CardList<Card>();

        string fileName;
        cout << "Masukkan nama file: ";
        cin >> fileName;

        ifstream infile ("../test/" + fileName);

        for (int i = 0; i < 7; i++){
            infile >> color >> number;
            cards << Card(color, number);
        }

        cout << "=== Daftar Kartu ===" << endl;
        cards.sortByNumberAndColor();
        cards.print();

        Combination *combination;
        HighCard highCard(cards);
        Pair pair(cards);
        TwoPair twoPair(cards);
        ThreeOfKind threeOfKind(cards);
        Straight straight(cards);
        Flush flush(cards);
        FullHouse fullHouse(cards);
        FourOfKind fourOfKind(cards);
        StraightFlush straightFlush(cards);

        combination = &highCard;
        cout << "High Card      : " << combination->getPoint() << endl;

        combination = &pair;
        cout << "Pair           : " << combination->getPoint() << endl;

        combination = &twoPair;
        cout << "Two Pair       : " << combination->getPoint() << endl;

        combination = &threeOfKind;
        cout << "Three of Kind  : " << combination->getPoint() << endl;

        combination = &straight;
        cout << "Straight       : " << combination->getPoint() << endl;

        combination = &flush;
        cout << "Flush          : " << combination->getPoint() << endl;

        combination = &fullHouse;
        cout << "Full House     : " << combination->getPoint() << endl;

        combination = &fourOfKind;
        cout << "Four of Kind   : " << combination->getPoint() << endl;

        combination = &straightFlush;
        cout << "Straight Flush : " << combination->getPoint() << endl;
    
    } catch (CardColorException e){
        cout << e.what();
    } catch (CardNumberException e){
        cout << e.what();
    }

    return 0;
}