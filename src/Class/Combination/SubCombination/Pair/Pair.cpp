#include "Pair.hpp"

Pair::Pair() : Combination() {
    this->computeScore();
}

Pair::Pair(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

Pair::Pair(const Pair& pair) : Combination(pair) {
    this->computeScore();
}

Pair::~Pair() {
    // Nothing to do
}

void Pair::computeScore() {
    int value = 0;
    int count = 0;
    int counter = 0;
    int color = 0;
    int number = 0;

    for (int i = 0; i < this->getCards().getTotalCard() - 1; i++){
        if (this->getCard(i).getNumber() == this->getCard(i + 1).getNumber()){
            count++;
            if (this->getCard(i).getNumber() > number){
                number = this->getCard(i).getNumber();
                color = this->getCard(i).getColor() > this->getCard(i + 1).getColor() ? 
                        this->getCard(i).getColor() : this->getCard(i + 1).getColor();
            } 

            while (i < this->getCards().getTotalCard() - 1 && this->getCard(i).getNumber() == this->getCard(i + 1).getNumber()){
                i++;
            }
        }
    }

    if (count >= 1){
        this->setPoint(color * 0.03 + number * 0.1 + 20);
    }
}