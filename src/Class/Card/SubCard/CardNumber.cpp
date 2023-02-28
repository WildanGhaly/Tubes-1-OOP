#include "CardNumber.hpp"

CardNumber::CardNumber(){
    this->number = 0;
}

CardNumber::CardNumber(int number){
    this->number = number;
}

CardNumber::CardNumber(const CardNumber& cn){
    this->number = cn.number;
}

CardNumber::~CardNumber(){
    // nothing to do
}

void CardNumber::setNumber(int number){
    this->number = number;
}

int CardNumber::getNumber() const{
    return this->number;
}

CardNumber &CardNumber::operator=(const CardNumber& cn){
    this->number = cn.number;
    return *this;
}

bool CardNumber::operator==(const CardNumber& cn) const{
    return this->number == cn.number;
}

bool CardNumber::operator!=(const CardNumber& cn) const{
    return this->number != cn.number;
}

void CardNumber::print() const{
    std::cout << this->number << std::endl;
}

void CardNumber::input(){
    std::cin >> this->number;
}