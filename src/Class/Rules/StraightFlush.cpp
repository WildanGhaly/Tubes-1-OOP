#include "StraightFlush.hpp"

int StraightFlush::IDcounter = 0;
StraightFlush::StraightFlush() : ID(IDcounter++), Rules() {
    this->name="StraightFlush";
}

StraightFlush::StraightFlush(Table table, PlayerVec player) : ID(IDcounter++), Rules(table, player) {
    this->name="StraightFlush";
}

StraightFlush::StraightFlush(const StraightFlush& cardComb) : ID(IDcounter++), Rules(cardComb) {
    this->name = cardComb.name;
}

StraightFlush::~StraightFlush() {
    /* Destructor */
}

/* Getter */
int StraightFlush::getID() const {
    return this->ID;
}

float StraightFlush::getScore() const {
    return this->Rules::getScore();
}

std::string StraightFlush::getName() const {
    return this->name;
}

/* Setter */
void StraightFlush::setID(int IDnew) {
    this->ID = IDnew;
}

void StraightFlush::setScore(float scoreNew) {
    this->Rules::setScore(scoreNew);
}

/* Method */
bool StraightFlush::isStraightFlush(std::vector<Card> cardComb, int& number, int& color) {
    int size = this->Rules::getCombination();
    int sizeColor = 4;
    int arr[size];
    int arrColor[sizeColor];
    for (int i = 0; i < size; i++)
    {
        arr[i]= this->Rules::getCard(i).getNumber();
    }
    for (int i = 0; i < this->Rules::getCombination(); i++)
    {
        arrColor[i]= this->Rules::getCard(i).getColor();
    }
    int max = 13;
    int maxColor = 4;
    std::vector<int> result = countElements(arr, size, max);
    cout << "result: " << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << " " << result[6] << " " << result[7] << " " << result[8] << " " << result[9] << " " << result[10] << " " << result[11] << endl;
    std::vector<int> resultColor = countElements(arrColor, size, sizeColor);
    cout << "resultColor: " << resultColor[0] << " " << resultColor[1] << " " << resultColor[2] << " " << resultColor[3] << endl;
    bool straightFlush = false;
    number=0;
    color=0;
    for(int i = 0; i < maxColor; i++){ 
        if(resultColor[i]==5){
            color=i;
            for(int j = 0; j < size + 1; j++){ 
                if(result[j]>0 && result[j+1]>0 && result[j+2]>0 && result[j+3]>0 && result[j+4]>0){
                    straightFlush=true;
                    number=j+4;
                }
            }
        }
    }
    return straightFlush;
}
void StraightFlush::computeScore() {
    int number, color = 0;
    float score = 0;
    if (isStraightFlush(this->Rules::getCards(), number, color)) {
        score = 80 + number * 0.1 + color * 0.3;
    }
    cout << "StraightFlush: " << score << endl;
    this->Rules::setScore(score > this->Rules::getScore() ? score : this->Rules::getScore());
    
}

    

