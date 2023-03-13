#include "ThreeOfKind.hpp"

ThreeOfKind::ThreeOfKind() : Combination() {
    this->computeScore();
}

ThreeOfKind::ThreeOfKind(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

ThreeOfKind::ThreeOfKind(const ThreeOfKind& threeOfKind) : Combination(threeOfKind) {
    this->computeScore();
}

ThreeOfKind::~ThreeOfKind() {
    // Nothing to do
}

void ThreeOfKind::computeScore() {
    int value = 0;
    int count = 0;
    int max = 0;
    int color = 0;
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        if (this->getCard(i).getNumber() == value) {
            count++;
            if (this->getCard(i).getNumber() > max) {
                max = this->getCard(i).getNumber();
                color = this->getCard(i).getColor();
            } else if (this->getCard(i).getNumber() == max) {
                if (this->getCard(i).getColor() > color) {
                    color = this->getCard(i).getColor();
                }
            }
        } else {
            value = this->getCard(i).getNumber();
            count = 1;
        }
    }
    if (count >= 3) {
        this->setPoint(max * 0.1 + color * 0.03 + 60);
    }
}