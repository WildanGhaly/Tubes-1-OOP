#include "HighCard.hpp"

int HighCard::IDcounter = 0;

/* Default Constructor */
HighCard::HighCard() : ID(IDcounter++), Rules() {
    this->name = "High Card";
}

/* Constructor with player and table */
HighCard::HighCard(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player) {
    this->name = "High Card";
}

/* Copy Constructor */
HighCard::HighCard(const HighCard& h) : ID(IDcounter++), Rules(h) {
    this->name = h.name;
}

/* Destructor */
HighCard::~HighCard() {
    // nothing to do
}

/* Getter */
int HighCard::getID() const {
    return this->ID;
}

string HighCard::getName() const {
    return this->name;
}

const float HighCard::getMin() const {
    return this->min;
}

/* Setter */
void HighCard::setID(int ID) {
    this->ID = ID;
}

void HighCard::setScore(float score) {
    this->Rules::setScore(score);
}

/* Method */
void HighCard::computeScore() {
    float score = this->Rules::getPlayer().getCard(0).getScore() > 
                this->Rules::getPlayer().getCard(1).getScore() ? 
                this->Rules::getPlayer().getCard(0).getScore() : 
                this->Rules::getPlayer().getCard(1).getScore();
    if (score > this->Rules::getPlayer().getScore())
        this->Rules::setScore(score);
    this->Rules::setScore(score);
}

