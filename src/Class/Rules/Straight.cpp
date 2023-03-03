#include "Straight.hpp"

int Straight::IDcounter = 0;
Straight::Straight():ID(IDcounter++), Rules() {
    this->name="Straight";
}

Straight::Straight(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="Straight";
}

Straight::Straight(const Straight& otherStraight) : ID(IDcounter++), Rules(otherStraight){
    this->name = otherStraight.name;
}

Straight::~Straight(){
/*Destroy*/
}

/* Getter */
int Straight::getID() const{
    return this->ID;
}

int Straight::getScore() const{
    this->Rules::getScore();
}

std::string Straight::getName() const{
    return this->name;
}

/* Setter */
void Straight::setID(int IDnew){
    this->ID=IDnew;
}

void Straight::setScore(float ScoreNew){
    this->Rules::setScore(ScoreNew);
}

/* Method */
/*!
* @attention Sort needed
*/

bool isStraight(std::vector<Card> cardComb, int &total) {
    total = 0;
    for (int i = 0; i < 3; i++) {
        if (cardComb[i].getNumber() == cardComb[i+1].getNumber() - 1 &&
            cardComb[i].getNumber() == cardComb[i+2].getNumber() - 2 &&
            cardComb[i].getNumber() == cardComb[i+3].getNumber() - 3 &&
            cardComb[i].getNumber() == cardComb[i+4].getNumber() - 4 
        ) {
            total++;
        }
    }        
    return total > 0;
}

void Straight::computeScore(){
    int total;
    if(isStraight(this->Rules::getCards(), total)){
        if(total<1){
            this->Rules::setScore(40);
        }
    }
}