#include "Rules.hpp"

int Rules::IDcounter = 0;

/* Default Constructor */
Rules::Rules() : ID(IDcounter++) {
    this->score = 0;
    this->player = PlayerVec();
    this->cards = vector<Card>(this->combination);
}

/* Constructor with player and table */
Rules::Rules(Table table, PlayerVec player) : ID(IDcounter++) {
    this->score = 0;
    this->player = player;
    this->cards = vector<Card>(this->combination);
    this->cards[0] = player.getCard(0);
    this->cards[1] = player.getCard(1);
    for (int i = 0; i < this->combination - 2; i++) {
        this->cards[i+2] = table.getCard(i);
    }
}

/* Copy Constructor */
Rules::Rules(const Rules& r) : ID(IDcounter++) {
    this->score = r.score;
    this->player = r.player;
    this->cards = r.cards;
}

/* Destructor */
Rules::~Rules() {
    // nothing to do
}

/* Getter */
int Rules::getID() const {
    return this->ID;
}

float Rules::getScore() const {
    return this->score;
}

PlayerVec Rules::getPlayer() const {
    return this->player;
}

vector<Card> Rules::getCards() const {
    return this->cards;
}

Card Rules::getCard(int index) const {
    return this->cards[index];
}

int Rules::getCombination() const {
    return this->combination;
}

/* Setter */
void Rules::setID(int ID) {
    this->ID = ID;
}

void Rules::setScore(float score) {
    this->score = score;
}

/* Method */

void Rules::print() const {
    cout << "ID: " << this->ID << endl;
    cout << "Score: " << this->score << endl;
    cout << "Player: " << endl;
    this->player.print();
    cout << "Cards: " << endl;
    for (int i = 0; i < this->combination; i++) {
        this->cards[i].print();
    }
}

void Rules::print(int index) const {
    cout << "ID: " << this->ID << endl;
    cout << "Score: " << this->score << endl;
    cout << "Player: " << endl;
    this->player.print(index);
    cout << "Cards: " << endl;
    for (int i = 0; i < this->combination; i++) {
        this->cards[i].print();
    }
}

void Rules::print(int index, int index2) const {
    cout << "ID: " << this->ID << endl;
    cout << "Score: " << this->score << endl;
    cout << "Player: " << endl;
    this->player.print(index, index2);
    cout << "Cards: " << endl;
    for (int i = 0; i < this->combination; i++) {
        this->cards[i].print();
    }
}

void Rules::addCard(Card card) {
    this->cards.push_back(card);
}

void Rules::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
}

void Rules::removeCard(Card card) {
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] == card) {
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

void Rules::addScore(float score) {
    this->score += score;
}

void Rules::computeScore() {
    // diturunkan ke kelas turunan
}

void Rules::setPlayer(PlayerVec player) {
    this->player = player;
}

void Rules::setCards(vector<Card> cards) {
    this->cards = cards;
}

bool Rules::operator==(const Rules& rules) const {
    return this->ID == rules.ID;
}

bool Rules::operator!=(const Rules& rules) const {
    return this->ID != rules.ID;
}

Rules& Rules::operator=(const Rules& rules) {
    this->ID = rules.ID;
    this->score = rules.score;
    this->player = rules.player;
    this->cards = rules.cards;
    return *this;
}