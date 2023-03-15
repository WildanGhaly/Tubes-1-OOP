#include "HighCard.hpp"

HighCard::HighCard() : Combination() {
    this->computeScore();
}

HighCard::HighCard(CardList<Card> cards) : Combination(cards) {
    this->computeScore();
}

HighCard::HighCard(const HighCard& highCard) : Combination(highCard) {
    this->computeScore();
}

HighCard::~HighCard() {
    // Nothing to do
}

void HighCard::computeScore() {
    for (int i = 0; i < this->getCards().getTotalCard(); i++) {
        this->setPoint(this->getValue() > 
        this->getCard(i).getValue() ? 
        this->getValue() : 
        this->getCard(i).getValue());
    }
}
