#include "CardList.hpp"

CardList::CardList() {
    this->cards = vector<Card>();
}

CardList::CardList(int totalCard) {
    this->cards = vector<Card>(totalCard);
}

CardList::CardList(string name) {
    this->cards = vector<Card>();
    if (name == "POKER") {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                this->cards.push_back(Card(i, j));
            }
        }
    } else {
        // Bonus spec
        // Exception handling for invalid name
    }
}

CardList::CardList(const CardList& cardList) {
    this->cards = cardList.cards;
}

CardList::~CardList() {
    // Nothing to do
}

int CardList::getTotalCard() const {
    return this->cards.size();
}

Card CardList::getCard(int index) const {
    return this->cards[index];
}

vector<Card> CardList::getCards() const {
    return this->cards;
}

void CardList::addCard(Card card) {
    this->cards.push_back(card);
}

void CardList::removeCard(Card card) {
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] == card) {
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

void CardList::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
}

void CardList::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cards.size(); i++) {
        int randomIndex = rand() % this->cards.size();
        Card temp = this->cards[i];
        this->cards[i] = this->cards[randomIndex];
        this->cards[randomIndex] = temp;
    }
}

void CardList::sortByNumber() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardList::sortByNumberDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() < this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardList::sortByColor() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

void CardList::print() const {
    for (int i = 0; i < this->cards.size(); i++) {
        cout << this->cards[i] << endl;
    }
}

bool CardList::operator==(const CardList& cardList) const {
    if (this->cards.size() != cardList.cards.size()) {
        return false;
    }
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] != cardList.cards[i]) {
            return false;
        }
    }
    return true;
}

bool CardList::operator!=(const CardList& cardList) const {
    return !(*this == cardList);
}

const Card& CardList::operator[](int index) const {
    return this->cards[index];
}

CardList& CardList::operator=(const CardList& cardList) {
    this->cards = cardList.cards;
    return *this;
}

CardList& CardList::operator<<(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

CardList& CardList::operator>>(Card& card) {
    card = this->cards.back();
    this->cards.pop_back();
    return *this;
}