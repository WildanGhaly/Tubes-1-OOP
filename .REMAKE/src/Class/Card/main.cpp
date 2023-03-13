#include "CardList.cpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello\n";
    CardList<Card> cardList = CardList<Card>("POKER");
    cardList.shuffle();
    cardList.sortByNumber();
    cardList.sortByColor();
    cardList.print();
    cout << "Hello\n";
    return 0;
}