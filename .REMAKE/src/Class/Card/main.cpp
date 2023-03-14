#include "CardList.cpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello\n";
    std::vector<std::string> printCard(5);
    CardList<Card> cardList = CardList<Card>("POKER");
    cardList.shuffle();
    // cardList.sortByNumber();
    // cardList.sortByColor();
    for (int i = 0; i < 10; i++)
    {
        printCard=cardList.getCard(i).setToPrint(printCard);
    }
    for (int i = 0; i < printCard.size(); i++)
    {
        cout << printCard[i] << endl;
    }
    cardList.print();
    cout << "Hello\n";
    return 0;
}