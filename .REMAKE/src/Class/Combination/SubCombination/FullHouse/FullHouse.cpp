#include "FullHouse.hpp"

FullHouse::FullHouse() : Combination() {
    this->computeScore();
}

FullHouse::FullHouse(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

FullHouse::FullHouse(const FullHouse& fullHouse) : Combination(fullHouse) {
    this->computeScore();
}

FullHouse::~FullHouse() {
    // Nothing to do
}

void FullHouse::computeScore() {
    int count = 0;
    int counter = 0;
    int color = 0;
    int number = 0;
    
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        for (int j = 0; j < this->getCards().getTotalCard(); j++) {
            if (this->getCard(i).getNumber() == this->getCard(j).getNumber()) {
                count++;
                if (this->getCard(j).getNumber() > number && count >= 3) {
                    number = this->getCard(j).getNumber();
                    color = this->getCard(j).getColor();
                } else if (this->getCard(j).getNumber() == number && count >= 3) {
                    if (this->getCard(j).getColor() > color) {
                        color = this->getCard(j).getColor();
                    }
                }
            }
        }

        if (count >= 3) {
            counter++;
        }
        count = 0;
    }

    if (counter >= 1){
        for (int i = 0; i < this->getCards().getTotalCard(); i++) {
            for (int j = 0; j < this->getCards().getTotalCard(); j++) {
                if (this->getCard(i).getNumber() == this->getCard(j).getNumber()) {
                    count++;
                }
            }
            if (count >= 2) {
                this->setPoint(color * 0.03 + number * 0.1 + 120);
                break;
            }
            count = 0;
        }
    }
    
}