#include "Flush.hpp"

int Flush::IDcounter = 0;

/* Constructor */
Flush::Flush():ID(IDcounter++), Rules() {
    this->name="Flush";
}

Flush::Flush(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="Flush";
}

Flush::Flush(const Flush& cardComb) : ID(IDcounter++), Rules(cardComb){
    this->name = cardComb.name;
}

/* Destroyer */
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
bool Flush::isFlush(std::vector<Card> cardComb, int &number, int& color){
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getColor();
    }
    int max = 4;
    std::vector<int> result = countElements(arr, size, max);
    bool flush = false;
    color=0;
    for(int i = 0; i < max+1; i++){ 
        if(result[i]==5){
            flush=true;
            color=i;
        }
    }
    number =0;
    if(flush){
        for (int i = 0; i < this->Rules::getCombination(); i++)
        {
            if ((this->getCard(i).getColor() == color) && (number < this->getCard(i).getNumber())){
                number = this->getCard(i).getNumber();
            }
        }
    }
    return flush;
}

void Flush::computeScore(){
    int number = 0;
    int color = 0;
    float score = 0;
    if (isFlush(this->Rules::getCards(), number, color)){
        score = 50 + number * 0.1 + color * 0.3;
    }

    this->Rules::setScore(score > this->Rules::getScore() ? score : this->Rules::getScore());
}