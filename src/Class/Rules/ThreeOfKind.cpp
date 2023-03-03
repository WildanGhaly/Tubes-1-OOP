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
float ThreeOfKind::getScore() const{
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

bool ThreeOfKind::isThreeOfKind(std::vector<Card> cardComb, int& total, int& color){
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getNumber();
    }
    int max = 13;
    std::vector<int> result = countElements(arr, size, max);
    bool threeOfKind = false;
    total=0;
    for(int i = 0; i < max+1; i++){
        if(result[i]==3){
            threeOfKind=true;
            total=i;
        }
    }
    color =0;
    if(threeOfKind){
        for (int i = 0; i < this->Rules::getCombination(); i++)
        {
            if ((this->getCard(i).getNumber() == total) && (color < this->getCard(i).getColor())){
                color = this->getCard(i).getColor();
            }
        }
        
    }
    return threeOfKind;
}

void ThreeOfKind::computeScore(){
    int total=0;
    int color=0;
    float score=0;
    if(isThreeOfKind(this->getCards(), total, color)){
        score+=30 + total * 0.1 + 0.3*color;
    }
    cout << "sblm: " << this->getScore();
    this->Rules::setScore(score > this->getScore() ? score : this->getScore());
    cout << "stlh: " << this->getScore();
}