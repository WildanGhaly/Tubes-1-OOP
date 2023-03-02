#include "Table.cpp"
using namespace std;

int main(){
    Table table;
    CardDeckVec deck;
    deck.shuffle();
    cout << "Total deck: " << deck.getTotalCard() << endl;
    table.nextRound(deck);
    table.print();
    cout << "==========================================" << endl;
    deck.print();
    cout << "Total Card: " << table.getTotalCard() << endl;
    cout << "Total deck: " << deck.getTotalCard() << endl;
    table.nextRound(deck);
    table.print();
    cout << "==========================================" << endl;
    deck.print();
   
    return 0;
}