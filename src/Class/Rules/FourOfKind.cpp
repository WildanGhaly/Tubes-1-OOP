#include "FourOfKind.hpp"

int FourOfKind::IDcounter=0;

FourOfKind::FourOfKind(): ID(IDcounter++), Rules(){
    this->name="Four Of Kind";
}
FourOfKind::FourOfKind(Table table, PlayerVec player): ID(IDcounter++), Rules(table, player){
    this->name="Four Of Kind";
}
FourOfKind::FourOfKind(const FourOfKind& cardComb): ID(IDcounter++), Rules(cardComb){
    this->name = cardComb.name;
}
FourOfKind::~FourOfKind(){

}

/* Getter */
int FourOfKind::getID() const{
    return this->ID;
}
float FourOfKind::getScore() const{
    return this->Rules::getScore();
}
std::string FourOfKind::getName() const{
    return this->name;
}

/* Setter */
void FourOfKind::setID(int IDnew){
    this->ID=IDnew;
}
void FourOfKind::setScore(float scoreNew){
    this->Rules::setScore(scoreNew);
}
        
/* Method */
bool FourOfKind::isFourOfKind(std::vector<Card> cardComb, int& total){
    int count=0;
    total=0;
    for (int i = 0; i < cardComb.size(); i++){
        for (int j = 0; i < cardComb.size(); i++){
            if(i!=j){
                if(cardComb[i].getNumber()==cardComb[j].getNumber()){
                    count++;
                    if(count==4){
                        total++;
                    }
                }
            }
        }
        count=0;
    }
    return total>0;
}

void FourOfKind::computeScore(){
    int total;
    if(isFourOfKind(this->Rules::getCards(), total)){
        if(total<1){
            this->Rules::addScore(70);
        }
    }
}