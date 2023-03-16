#include "Combination.hpp"

Combination::Combination() {
    this->cards = CardList<Card>();
    this->point = 0;
}

Combination::Combination(CardList<Card> cards) {
    this->cards = cards;
    this->point = 0;
}

Combination::Combination(const Combination& combination) {
    this->cards = combination.cards;
    this->point = combination.point;
}

Combination::~Combination() {
    // Nothing to do
}

CardList<Card> Combination::getCards() const {
    return this->cards;
}

Card Combination::getCard(int index) const {
    return this->cards.getCard(index);
}

float Combination::getValue() const {
    return this->point;
}

void Combination::setCards(CardList<Card> cards) {
    this->cards = cards;
}

void Combination::setCard(int index, Card card) {
    this->cards.setCard(index, card);
}

void Combination::setPoint(float point) {
    this->point = point;
}

bool Combination::operator==(const Combination& combination) const {
    return this->cards == combination.cards;
}

bool Combination::operator!=(const Combination& combination) const {
    return this->cards != combination.cards;
}

bool Combination::operator<(const Combination& combination) const {
    return this->point < combination.point;
}

bool Combination::operator>(const Combination& combination) const {
    return this->point > combination.point;
}

bool Combination::operator<=(const Combination& combination) const {
    return this->point <= combination.point;
}

bool Combination::operator>=(const Combination& combination) const {
    return this->point >= combination.point;
}

Combination& Combination::operator=(const Combination& combination) {
    this->cards = combination.cards;
    this->point = combination.point;
    return *this;
}

Combination& Combination::operator<<(const Card& card) {
    this->cards << card;
    return *this;
}

Combination& Combination::operator>>(Card& card) {
    this->cards >> card;
    return *this;
}