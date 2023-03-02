#include "Card.hpp"

/* Static ID counter */
int Card::IDCounter = 0;

/* Default Constructor */
Card::Card() :  IDCard(IDCounter++), 
                CardColor(), 
                CardNumber() {
}

/* Constructor with number and color */
Card::Card(int number, int color) : IDCard(IDCounter++),
                                    CardColor(color), 
                                    CardNumber(number) {
}

Card::Card(const Card& c) : IDCard(IDCounter++) {
    CardColor::operator=(c);
    CardNumber::operator=(c);
}

Card::~Card() {
}

/* Setter number */
void Card::setNumber(int number) {
    CardNumber::setNumber(number);
}

/* Setter color with int */
void Card::setColor(int color) {
    CardColor::setColor(color);
}

/* Setter color with string */
void Card::setColor(std::string color) {
    CardColor::setColor(color);
}

/* Mengembalikan number */
int Card::getNumber() const {
    return CardNumber::getNumber();
}

/* Mengembalikan color */
int Card::getColor() const {
    return CardColor::getColor();
}

/* Mengembalikan ID */
int Card::getID() const {
    return this->IDCard;
}

/* Input manual for cards */
void Card::input() {
    while (true){
        std::cout << "Input number: ";
        CardNumber::input();
        std::cout << "0. Green" << std::endl;
        std::cout << "1. Blue" << std::endl;
        std::cout << "2. Yellow" << std::endl;
        std::cout << "3. Red" << std::endl;
        std::cout << "Input color: ";
        CardNumber::input();
        if (this->getColor() >= 0 && this->getColor() <= 3 && this->getNumber() >= 1 && this->getNumber() <= 13) {
            break;
        } else {
            std::cout << "Invalid input" << std::endl;
        }
    }
}

/* Mengembalikan string dari color */
std::string Card::getColorAsString() const {
    switch (this->getColor()) {
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
        case RED:
            return "Red";
        default:
            return "Error";
    }
}

/* Mengembalikan string dari number */
std::string Card::getCardNumberAsString() const {
    switch (this->getNumber()) {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "11";
        case 12:
            return "12";
        case 13:
            return "13";
        default:
            return "Error";
    }
}

/* Mengembalikan string dari color dan number */
std::string Card::toString() const {
    return this->getColorAsString() + " " + this->getCardNumberAsString();
}

/* Operator overloading untuk operator = */
Card& Card::operator=(const Card& c) {
    CardColor::operator=(c);
    CardNumber::operator=(c);
    return *this;   
}

/* Operator overloading untuk operator == */
bool Card::operator==(const Card& c) const {
    return (this->getColor() == c.getColor() && this->getNumber() == c.getNumber());
}

/* Operator overloading untuk operator != */
bool Card::operator!=(const Card& c) const {
    return !(*this == c);
}

/* KURANG DARI, LEBIH DARI, DLL itu harus ngitung dulu?? */

/* printing */
void Card::print() const {
    std::cout << this->toString() << std::endl;
}

float Card::getScore() const {
    return (0.3 * this->getColor()) + this->getNumber();
}