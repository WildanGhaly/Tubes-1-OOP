#include "ThreeOfKind.hpp"

int ThreeOfKind::IDcounter=0;

ThreeOfKind::ThreeOfKind(): ID(IDcounter++), Rules(){
    this->name="Three Of Kind";
}
ThreeOfKind::ThreeOfKind(Table table, PlayerVec player): ID(IDcounter++), Rules(table, player){
    this->name="Three Of Kind";
}
ThreeOfKind::ThreeOfKind(const ThreeOfKind& cardComb) : ID(IDcounter++), Rules(cardComb){
    this->name = cardComb.name;
}
/*Destroyer*/
ThreeOfKind::~ThreeOfKind(){

}

/* Getter */
int ThreeOfKind::getID() const{
    return this->ID;
}
int ThreeOfKind::getScore() const{
    return this->Rules::getScore();
}
std::string ThreeOfKind::getName() const{
    return this->name;
}

/* Setter */
void ThreeOfKind::setID(int IDnew){
    this->ID=IDnew;
}
void ThreeOfKind::setScore(float ScoreNew){
    this->Rules::setScore(ScoreNew);
}
        
/* Method */

bool ThreeOfKind::isThreeOfKind(std::vector<Card> cardComb, int& total){
    int count=0;
    total=0;
    for (int i = 0; i < cardComb.size(); i++){
        for (int j = 0; i < cardComb.size(); i++){
            if(i!=j){
                if(cardComb[i].getNumber()==cardComb[j].getNumber()){
                    count++;
                    if(count==3){
                        total++;
                    } else if (count>3){
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

void ThreeOfKind::computeScore(){
    int total;
    if(isThreeOfKind(this->Rules::getCards(), total)){
        if(total==1){
            this->Rules::addScore(30);
        }
    }
}