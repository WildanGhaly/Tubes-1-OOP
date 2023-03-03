#include "StraightFlush.hpp"

int StraightFlush::IDcounter = 0;
StraightFlush::StraightFlush():ID(IDcounter++), Rules() {
    this->name="StraightFlush";
}

StraightFlush::StraightFlush(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="StraightFlush";
}

StraightFlush::StraightFlush(const StraightFlush& cardComb) : ID(IDcounter++), Rules(cardComb){
    this->name = cardComb.name;
}

StraightFlush::~StraightFlush() {
    /* Destructor */
}

/* Getter */
int StraightFlush::getID() const {
    return this->ID;
}

int StraightFlush::getScore() const {
    return this->Rules::getScore();
}

std::string StraightFlush::getName() const {
    return this->name;
}

/* Setter */
void StraightFlush::setID(int IDnew) {
    this->ID = IDnew;
}

void StraightFlush::setScore(float scoreNew) {
    this->Rules::setScore(scoreNew);
}

/* Method */
/*! @attention Sorted by number needed 
*/
bool StraightFlush::isStraightFlush(std::vector<Card> cardComb, int& total) {
    total = 0;
    for (int i = 0; i < 3; i++) {
        if (cardComb[i].getNumber() == cardComb[i+1].getNumber() - 1 && cardComb[i].getColor() == cardComb[i+1].getColor() &&
            cardComb[i].getNumber() == cardComb[i+2].getNumber() - 2 && cardComb[i].getColor() == cardComb[i+2].getColor() &&
            cardComb[i].getNumber() == cardComb[i+3].getNumber() - 3 && cardComb[i].getColor() == cardComb[i+3].getColor() &&
            cardComb[i].getNumber() == cardComb[i+4].getNumber() - 4 && cardComb[i].getColor() == cardComb[i+4].getColor()
        ) {
            total++;
        }
    }        
    return total > 0;
}

void StraightFlush::computeScore() {
    int total;
    if (isStraightFlush(this->Rules::getCards(), total)) {
        if (total < 1) {
            this->Rules::setScore(80);
        }
    }
}