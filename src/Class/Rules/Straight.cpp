#include "Straight.hpp"

int Straight::IDcounter = 0;
Straight::Straight():ID(IDcounter++), Rules() {
    this->name="Straight";
}

Straight::Straight(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player){
    this->name="Straight";
}

Straight::Straight(const Straight& cardComb) : ID(IDcounter++), Rules(cardComb){
    this->name = cardComb.name;
}

Straight::~Straight() {
    /* Destructor */
}

/* Getter */
int Straight::getID() const {
    return this->ID;
}

int Straight::getScore() const {
    return this->Rules::getScore();
}

std::string Straight::getName() const {
    return this->name;
}

/* Setter */
void Straight::setID(int IDnew) {
    this->ID = IDnew;
}

void Straight::setScore(float scoreNew) {
    this->Rules::setScore(scoreNew);
}

/* Method */
bool Straight::isStraight(std::vector<Card> cardComb, int& number, int& color) {
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getNumber();
    }
    int max = 13;
    std::vector<int> result = countElements(arr, size, max);
    bool straight = false;
    int count = 0;
    number = 0;
    for (int i = 0; i < max; i++)
    {
        if(result[i]>0 && result[i+1]>0 && result[i+2]>0 && result[i+3]>0 && result[i+4]>0){
            straight=true;
            number=i+4;
        }
    }
    color = 0;
    if (straight) {
        for (int i = 0; i < size; i++)
        {
            if (number == this->Rules::getCard(i).getNumber() && color < this->Rules::getCard(i).getColor()) {
                color = this->Rules::getCard(i).getColor();
            }
        }
    }
    return straight;
}

void Straight::computeScore() {
    int number, color = 0;
    float score = 0;
    if (isStraight(this->Rules::getCards(), number, color)) {
        score = 40 + number * 0.1 + color * 0.3;
    }
    this->Rules::setScore(score > this->Rules::getScore() ? score : this->Rules::getScore());    
}
