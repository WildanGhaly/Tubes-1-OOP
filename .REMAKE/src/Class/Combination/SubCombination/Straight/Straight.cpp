#include "Straight.hpp"

Straight::Straight() : Combination() {
    this->computeScore();
}

Straight::Straight(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

Straight::Straight(const Straight& straight) : Combination(straight) {
    this->computeScore();
}

Straight::~Straight() {
    // Nothing to do
}

void Straight::computeScore() {
    int count = 0;
    int color = 0;
    int number = 0;
    
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        for (int j = 0; j < this->getCards().getTotalCard(); j++) {
            if (this->getCard(i).getNumber() + count == this->getCard(j).getNumber()) {
                count++;
                if (this->getCard(j).getNumber() > number) {
                    number = this->getCard(j).getNumber();
                    color = this->getCard(j).getColor();
                } else if (this->getCard(j).getNumber() == number) {
                    if (this->getCard(j).getColor() > color) {
                        color = this->getCard(j).getColor();
                    }
                }
            }
        }
        if (count >= 5) {
            this->setPoint(color * 0.03 + number * 0.1 + 80);
            break;
        }
        count = 0;
    }
}