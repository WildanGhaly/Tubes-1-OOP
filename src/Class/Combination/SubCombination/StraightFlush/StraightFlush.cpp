#include "StraightFlush.hpp"

StraightFlush::StraightFlush() : Combination() {
    this->computeScore();
}

StraightFlush::StraightFlush(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

StraightFlush::StraightFlush(const StraightFlush& straightFlush) : Combination(straightFlush) {
    this->computeScore();
}

StraightFlush::~StraightFlush() {
    // Nothing to do
}

void StraightFlush::computeScore() {
    int count = 0;
    int number = 0;
    int color = 0;
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        for (int j = 0; j < this->getCards().getTotalCard(); j++) {
            if (this->getCard(i).getNumber() + count == this->getCard(j).getNumber() && 
                this->getCard(i).getColor() == this->getCard(j).getColor()) {
                count++;
                if (this->getCard(j).getNumber() > number) {
                    number = this->getCard(j).getNumber();
                    color = this->getCard(j).getColor();
                }
            }
        }

        if (count >= 5){
            this->setPoint(number * 0.1 + color * 0.03 + 160);
            break;
        }
        count = 0;
    }
}