#include "HighCard.hpp"

int HighCard::IDcounter = 0;

/* Default Constructor */
HighCard::HighCard() : ID(IDcounter++), Rules() {
    this->name = "High Card";
}

/* Constructor with player and table */
HighCard::HighCard(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player) {
    this->name = "High Card";
}

/* Copy Constructor */
HighCard::HighCard(const HighCard& h) : ID(IDcounter++), Rules(h) {
    this->name = h.name;
}

/* Destructor */
HighCard::~HighCard() {
    // nothing to do
}

/* Getter */
int HighCard::getID() const {
    return this->ID;
}

float HighCard::getScore() const{
    return this->Rules::getScore();
}

string HighCard::getName() const {
    return this->name;
}

const float HighCard::getMin() const {
    return this->min;
}

/* Setter */
void HighCard::setID(int ID) {
    this->ID = ID;
}

void HighCard::setScore(float score) {
    this->Rules::setScore(score);
}

/* Method */
void HighCard::computeScore() {
    float score =0;
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getNumber();
    }
    int max = 13;
    std::vector<int> result = countElements(arr, size, max);
    int number=0;
    for(int i = 0; i < max+1; i++){
        if(result[i]==1){
            number=i;
        }
    }
    int color=0;
    for (int i=0; i < this->Rules::getCombination(); i++){
        if((this->getCard(i).getNumber()==number) && (color < this->getCard(i).getColor())){
            color = this->getCard(i).getColor();
        }
    }
    score= (number*0.1) + (0.3*color);
    this->Rules::setScore(score);
}

