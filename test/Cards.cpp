#include <iostream>
#include <vector>
using namespace std;

class Color {
    private:
        int color;
    public:
        Color(){
            this->color = 3;
        };
        void print(){
            cout << this->color << endl;
        };
};

class Number {
    private:
        int number;
    public:
        Number() {
            this->number = 3;
        };
        void print(){
            cout << this->number << endl;
        };
};

class Card : public Color, public Number{
    private:
        Color color;
    public:
        Card() : Color(), Number() {};

        void print(){
            cout << "Test" << endl;
            this->Color::print();
            this->Number::print();
        };
};

class Table {
    private:
        vector<Card> cards;
    public:
        Table(){
            this->cards = vector<Card>();
        };
        void addCard(Card card){
            this->cards.push_back(card);
        };
        void removeCard(int index){
            this->cards.erase(this->cards.begin() + index);
        };
        Card getCard(int index){
            return this->cards[index];
        };
        int getTotalCard(){
            return this->cards.size();
        };
        void print(){
            for (int i = 0; i < this->getTotalCard(); i++){
                this->getCard(i).print();
            }
        };
};


int main(){
    Card card;
    Color *color = &card;
    Number *number = &card;

    card.print();

    Table table;
    table.addCard(card);
    table.addCard(card);
    table.print();

    return 0;
}