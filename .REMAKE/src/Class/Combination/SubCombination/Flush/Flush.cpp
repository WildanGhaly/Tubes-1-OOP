#include "Flush.hpp"

Flush::Flush() : Combination() {
    this->computeScore();
}

Flush::Flush(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

Flush::Flush(const Flush& flush) : Combination(flush) {
    this->computeScore();
}

Flush::~Flush() {
    // Nothing to do
}

void Flush::computeScore() {
    int count = 0;
    int color = 0;
    int number = 0;
    int j;
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        for (j = 0; j < this->getCards().getTotalCard(); j++) {
            if (this->getCard(i).getColor() == this->getCard(j).getColor()) {
                count++;
                if (this->getCard(j).getNumber() > number) {
                    number = this->getCard(j).getNumber();
                    color = this->getCard(j).getColor();
                }
            }
        }
        if (count >= 5) {
            break;
        }
        count = 0;
    }
    if (count >= 5) {
        this->setPoint(number * 0.1 + color * 0.03 + 100);
    }
}