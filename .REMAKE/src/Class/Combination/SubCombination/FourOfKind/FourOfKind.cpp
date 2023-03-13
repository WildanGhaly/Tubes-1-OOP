#include "FourOfKind.hpp"

FourOfKind::FourOfKind() : Combination() {
    this->computeScore();
}

FourOfKind::FourOfKind(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

FourOfKind::FourOfKind(const FourOfKind& fourOfKind) : Combination(fourOfKind) {
    this->computeScore();
}

FourOfKind::~FourOfKind() {
    // Nothing to do
}

void FourOfKind::computeScore(){
    int count = 0;
    int color = 0;
    int number = 0;

    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        for (int j = 0; j < this->getCards().getTotalCard(); j++) {
            if (this->getCard(i).getNumber() == this->getCard(j).getNumber()) {
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
        if (count >= 4) {
            this->setPoint(color * 0.03 + number * 0.1 + 140);
            break;
        }
        count = 0;
    }
}