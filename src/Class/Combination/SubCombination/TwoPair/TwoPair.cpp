#include "TwoPair.hpp"

TwoPair::TwoPair() : Combination() {
    this->computeScore();
}

TwoPair::TwoPair(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

TwoPair::TwoPair(const TwoPair& twoPair) : Combination(twoPair) {
    this->computeScore();
}

TwoPair::~TwoPair() {
    // Nothing to do
}

void TwoPair::computeScore() {
    int value = 0;
    int count = 0;
    int counter = 0;
    int number = 0;
    int color = 0;
    
    for (int i = 0; i < this->getCards().getTotalCard() - 1; i++){
        if (this->getCard(i).getNumber() == this->getCard(i + 1).getNumber() && this->getCard(i).getNumber() != number){
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

    if (count >= 2){
        this->setPoint(color * 0.03 + number * 0.1 + 40);
    }
}