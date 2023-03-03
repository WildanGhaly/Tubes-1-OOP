#include "FullHouse.hpp"

FullHouse::FullHouse() {
    this->ID = 0;
    this->name = "Full House";
}

FullHouse::FullHouse(const FullHouse& fh) {
    this->ID = fh.ID;
    this->name = fh.name;
}

FullHouse::~FullHouse() {
    // nothing to do
}

/* Getter */
int FullHouse::getID() const {
    return this->ID;
}

std::string FullHouse::getName() const {
    return this->name;
}

/* Setter */
void FullHouse::setID(int ID) {
    this->ID = ID;
}

void FullHouse::setName(std::string name) {
    this->name = name;
}

/* Method */
void FullHouse::addScore(float score) {
    this->Rules::addScore(60);
}

void FullHouse::computeScore() {
    this->addScore(60);
}

// return true if the cards is full house
// return false if the cards is not full house
// first and second is the number of the card
bool FullHouse::isFullHouse(std::vector<Card> cards, int& first, int& second) {
    int size = this->Rules::getCombination();
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = this->Rules::getCard(i).getNumber();
    }
    int max = 13; // maximum nilai kartu
    std::vector<int> result = countElements(arr, size, max);
    bool threeKind = false; 
    bool twoKind = false;
    first = 0; 
    second = 0;
    for (int i = 0; i < max+1; i++){
        if (result[i] == 3 && threeKind){
            twoKind = true;
            second = first;
            first = i;
        } else if (result[i] == 3) {
            first = i;
            threeKind = true;
        } else if (result[i] == 2) {
            second = i;
            twoKind = true;
        }
    }
    return (threeKind && twoKind);
}

bool FullHouse::operator==(const FullHouse& fh) const {
    return this->ID == fh.ID;
}

bool FullHouse::operator!=(const FullHouse& fh) const {
    return this->ID != fh.ID;
}

FullHouse& FullHouse::operator=(const FullHouse& fh) {
    this->ID = fh.ID;
    this->name = fh.name;
    return *this;
}