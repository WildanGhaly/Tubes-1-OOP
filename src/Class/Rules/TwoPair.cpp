#include "TwoPair.hpp"

int TwoPair::totalTwoPair = 0;

TwoPair::TwoPair() : ID(totalTwoPair++) {
    this->score = 0;
    this->cards = vector<Card>();
}

TwoPair::TwoPair(int totalCard) : ID(totalTwoPair++) {
    this->score = 0;
    this->cards = vector<Card>(totalCard);
}

TwoPair::TwoPair(const TwoPair& tp) : ID(totalTwoPair++) {
    this->score = tp.score;
    this->cards = tp.cards;
}

TwoPair::TwoPair(GameVec game, int index) : ID(totalTwoPair++) {
    // 2 kartu player
    // 5 kartu table
    this->score = 0;
    this->cards = vector<Card>();
    this->cards.push_back(game.getPlayer(index).getCard(0));
    this->cards.push_back(game.getPlayer(index).getCard(1));
    for (int i = 0; i < game.getTotalTableCard(); i++) {
        this->cards.push_back(game.getTable().getCard(i));
    }
}

TwoPair::~TwoPair() {
    // nothing to do
}

/* Getter */
int TwoPair::getID() const {
    return this->ID;
}

float TwoPair::getScore() const {
    return this->score;
}

const float TwoPair::getMaxTwoPair() const {
    return this->maxTwoPair;
}

vector<Card> TwoPair::getCards() const {
    return this->cards;
}

Card TwoPair::getCard(int index) const {
    return this->cards[index];
}

/* Setter */
void TwoPair::setID(int ID) {
    this->ID = ID;
}

void TwoPair::setScore(int score) {
    this->score = score;
}

/* Method */


