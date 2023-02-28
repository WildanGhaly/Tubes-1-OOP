#include "CardColor.hpp"

CardColor::CardColor(){
    this->color = GREEN;
}

CardColor::CardColor(int color){
    this->color = color;
}

CardColor::CardColor(const CardColor& cc){
    this->color = cc.color;
}

CardColor::~CardColor(){
    // nothing to do
}

void CardColor::setColor(int color){
    this->color = color;
}

void CardColor::setColor(std::string color){
    if(color == GREEN_STRING){
        this->color = GREEN;
    } else if(color == BLUE_STRING){
        this->color = BLUE;
    } else if(color == YELLOW_STRING){
        this->color = YELLOW;
    } else if(color == RED_STRING){
        this->color = RED;
    } else {
        this->color = GREEN;
    }
}

int CardColor::getColor() const{
    return this->color;
}

std::string CardColor::getColorAsString() const{
    switch(this->color){
        case GREEN:
            return GREEN_STRING;
        case BLUE:
            return BLUE_STRING;
        case YELLOW:
            return YELLOW_STRING;
        case RED:
            return RED_STRING;
        default:
            return GREEN_STRING;
    }
}

CardColor &CardColor::operator=(const CardColor& cc){
    this->color = cc.color;
    return *this;
}

bool CardColor::operator==(const CardColor& cc) const{
    return this->color == cc.color;
}

bool CardColor::operator!=(const CardColor& cc) const{
    return this->color != cc.color;
}

void CardColor::print() const{
    std::cout << this->getColorAsString() << std::endl;
}

void CardColor::input(){
    std::cin >> this->color;
}