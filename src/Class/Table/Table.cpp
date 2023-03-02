#include "Table.hpp"

Table::Table() {
    this->round = 0;
    this->cards = std::vector<Card>();
}

Table::Table(CardDeckVec cd, int round) : round(round) {
    this->cards = std::vector<Card>();
    for (int i = 0; i < round-1; i++) {
        this->cards.push_back(cd.getCard(0));
        cd.removeCard(0);
    }
}

Table::Table(const Table& table) : cards(table.cards) {
    this->round = table.round;
    this->cards = table.cards;
}

Table::~Table() {
    this->cards.clear();
}

/* Getter */
std::vector<Card> Table::getCards() const {
    return this->cards;
}

int Table::getTotalCard() const {
    return this->cards.size();
}

Card Table::getCard(int index) const {
    return this->cards[index];
}

int Table::getRound() const {
    return this->round;
}

/* Setter */
void Table::setCards(CardDeckVec cd) {
    this->cards.clear();
    for (int i = 0; i < this->round-1; i++) {
        this->cards.push_back(cd.getCard(0));
        cd.removeCard(0);
    }
}

int Table::setRound(int round) {
    this->round = round;
    return this->round;
}

/* Method */
void Table::print() const {
    for (int i = 0; i < this->getTotalCard(); i++) {
        std::cout << "      ";
        this->getCard(i).print();
    }
}

void Table::addCard(Card card) {
    this->cards.push_back(card);
}

void Table::addRound() {
    this->round++;
}

void Table::nextRound(CardDeckVec &cd) {
    this->round++;
    this->cards.push_back(cd.getCard(0));
    cd.removeCard(0);
}

void Table::removeCard(Card card) {
    for (int i = 0; i < this->getTotalCard(); i++) {
        if (this->getCard(i) == card) {
            this->cards.erase(this->cards.begin() + i);
        }
    }
}

void Table::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
}

void Table::shuffle() {
    std::random_shuffle(this->cards.begin(), this->cards.end());
}

/* Operator */
bool Table::operator==(const Table& table) const {
    if (this->round != table.round) {
        return false;
    }
    for (int i = 0; i < this->getTotalCard(); i++) {
        if (this->getCard(i) != table.getCard(i)) {
            return false;
        }
    }
    return true;
}

bool Table::operator!=(const Table& table) const {
    return !(*this == table);
}

Table& Table::operator=(const Table& table) {
    this->round = table.round;
    this->cards = table.cards;
    return *this;
}