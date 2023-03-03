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
float Pair::getScore() const{
    return this->Rules::getScore();
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
bool Pair::isPairs(std::vector<Card> cardComb, int &number1, int& number2, int& color1, int& color2){
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = this->Rules::getCard(i).getNumber();
    }
    int max = 13; // maximum nilai kartu
    std::vector<int> result = countElements(arr, size, max);
    bool twoKind = false;
    number1 = 0;
    number2 = 0;
    for (int i = 0; i < max+1; i++)
    {
        if(result[i]==2){
            number1=i;
            twoKind=true;
        }
    }
    if(twoKind){
        for (int i = 0; i < max+1; i++)
        {
            if(result[i]==2 && i!=number1){
                number2=i;
            }
        }
    }
    color1 =0;
    color2 =0;
    if(twoKind){
        for (int i = 0; i < this->Rules::getCombination(); i++)
        {
            if((this->getCard(i).getNumber()==number1) && (color1 < this->getCard(i).getNumber())){
                color1 = this->getCard(i).getColor();
            }
            if((this->getCard(i).getNumber()==number2) && (color2 < this->getCard(i).getNumber())){
                color2 = this->getCard(i).getColor();
            }
        }
    }
    return twoKind;
}

void Pair::computeScore(){
    int number1=0, number2=0;
    int color1=0, color2=0;
    float score=0;
    if (isPairs(this->Rules::getCards(), number1, number2, color1, color2)){
        score+=((number1+number2)*0.2) + (0.3 * (color1 + color2));
        if(number2!=0){
            score+=20;
        } else {
            score+=10;
        }
        this->Rules::setScore(score > this->getScore() ? score : this->getScore());
    }   
}