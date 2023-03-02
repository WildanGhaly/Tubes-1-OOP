#include "CardListVec.hpp"

int CardDeckVec::totalDeck = 0;

CardDeckVec::CardDeckVec() : ID(totalDeck++) {
    this->totalCard = 52;
    this->cards = vector<Card>(this->totalCard);
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i] = Card(i % 13 + 1, i / 13);
    }
}

CardDeckVec::CardDeckVec(int totalCard) : ID(totalDeck++) {
    this->totalCard = totalCard;
    this->cards = vector<Card>(this->totalCard);
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i].input();
    }
}

CardDeckVec::CardDeckVec(const CardDeckVec& cd) : ID(totalDeck++) {
    this->totalCard = cd.totalCard;
    this->cards = cd.cards;
}

CardDeckVec::~CardDeckVec() {
    this->cards.clear();
}

int CardDeckVec::getTotalCard() const {
    return this->totalCard;
}

int CardDeckVec::getID() const {
    return this->ID;
}

Card CardDeckVec::getCard(int index) const {
    return this->cards[index];
}

void CardDeckVec::addCard(Card c) {
    this->cards.push_back(c);
    this->totalCard++;
}

void CardDeckVec::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
    this->totalCard--;
}

void CardDeckVec::removeCard(Card c) {
    int index = -1;
    for (int i = 0; i < this->totalCard; i++) {
        if (this->cards[i] == c) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        this->removeCard(index);
    }
}

void CardDeckVec::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->totalCard; i++) {
        int j = rand() % this->totalCard;
        Card temp = this->cards[i];
        this->cards[i] = this->cards[j];
        this->cards[j] = temp;
    }
}

void CardDeckVec::sortByNumber() {
    for (int i = 0; i < this->totalCard - 1; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardDeckVec::sortByColor() {
    for (int i = 0; i < this->totalCard - 1; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardDeckVec::sortByID() {
    for (int i = 0; i < this->totalCard - 1; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getID() > this->cards[j].getID()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardDeckVec::print() const {
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i].print();
    }
}

bool CardDeckVec::operator==(const CardDeckVec& cd) const {
    if (this->totalCard != cd.totalCard) {
        return false;
    }
    for (int i = 0; i < this->totalCard; i++) {
        if (this->cards[i] != cd.cards[i]) {
            return false;
        }
    }
    return true;
}

bool CardDeckVec::operator!=(const CardDeckVec& cd) const {
    return !(*this == cd);
}

CardDeckVec& CardDeckVec::operator=(const CardDeckVec& cd) {
    this->totalCard = cd.totalCard;
    this->cards = cd.cards;
    return *this;
}




