#include "Pair.hpp"

int Pair::IDcounter = 0;
Pair::Pair():ID(IDcounter++), Rules() {
    this->name="Pair";
}
Pair::Pair(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="Pair";
}
Pair::Pair(const Pair& otherPair) : ID(IDcounter++), Rules(otherPair){
    this->name = otherPair.name;
}
Pair::~Pair(){
/*Destroy*/
}

/* Getter */
int Pair::getID() const{
    return this->ID;
}
int Pair::getScore() const{
    this->Rules::getScore();
}
std::string Pair::getName() const{
    return this->name;
}

/* Setter */
void Pair::setID(int IDnew){
    this->ID=IDnew;
}
void Pair::setScore(float ScoreNew){
    this->Rules::setScore(ScoreNew);
}
        
/* Method */
/*!
*@attention Sort needed
*/
bool isPairs(std::vector<Card> cardComb, int &total){
    int count=0;
    total=0;
    for (int i = 0; i < cardComb.size(); i++){
        for (int j = 0; i < cardComb.size(); i++){
            if(i!=j){
                if(cardComb[i].getNumber()==cardComb[j].getNumber()){
                    count++;
                    if(count==2){
                        total++;
                    } else if (count>2){
                        total=0;
                        return false;
                    }
                }
            }
        }
        count=0;
    }
    return total>0;
}

void Pair::computeScore(){
    int total;
    if (isPairs(this->Rules::getCards(), total)){
        if(total==1){
            this->Rules::addScore(10);
        } else if (total==2 || total == 3){
            this->Rules::addScore(20);
        }
    }   
}