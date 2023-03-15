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
bool FourOfKind::isFourOfKind(std::vector<Card> cardComb, int& number, int& color){
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getNumber();
    }
    int max = 13;
    std::vector<int> result = countElements(arr, size, max);
    bool fourOfKind = false;
    number=0;
    for(int i = 0; i < max+1; i++){
        if(result[i]==4){
            fourOfKind=true;
            number=i;
        }
    }
    color =0;
    if(fourOfKind){
        for (int i = 0; i < this->Rules::getCombination(); i++)
        {
            if ((this->getCard(i).getNumber() == number) && (color < this->getCard(i).getColor())){
                color = this->getCard(i).getColor();
            }
        }
        
    }
    return fourOfKind;
}

void FourOfKind::computeScore(){
    int number=0;
    int color=0;
    float score=0;
    if(isFourOfKind(this->Rules::getCards(), number, color)){
        score+=70 + number * 0.1 + 0.3 * color;
    }
    this->Rules::setScore(score > this->getScore() ? score : this->getScore());
}