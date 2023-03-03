#include "Flush.hpp"

int Flush::IDcounter = 0;
Flush::Flush():ID(IDcounter++), Rules() {
    this->name="Flush";
}

Flush::Flush(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="Flush";
}

Flush::Flush(const Flush& otherFlush) : ID(IDcounter++), Rules(otherFlush){
    this->name = otherFlush.name;
}

Flush::~Flush(){

}

/* Getter */
int Flush::getID() const{
    return this->ID;
}

int Flush::getScore() const{
    return this->Rules::getScore();
}

std::string Flush::getName() const{
    return this->name;
}

/* Setter */
void Flush::setID(int IDnew){
    this->ID=IDnew;
}

void Flush::setScore(float ScoreNew){
    this->Rules::setScore(ScoreNew);
}

/* Method */
bool Flush::isFlush(std::vector<Card> cardComb, int &total){
    int count=0;
    total=0;
    for (int i = 0; i < cardComb.size(); i++){
        for (int j = 0; i < cardComb.size(); i++){
            if(i!=j){
                if(cardComb[i].getColor()==cardComb[j].getColor()){
                    count++;
                    if(count==5){
                        total++;
                    }
                }
            }
        }
        count=0;
    }
    return total>0;
}

void Flush::computeScore(){
    int total;
    if(isFlush(this->Rules::getCards(), total)){
        if (total < 1) {
            this->Rules::setScore(50);
        }
    }
}