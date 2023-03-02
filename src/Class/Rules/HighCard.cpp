#include "HighCard.hpp"

HighCard::HighCard(){
    this->name = "High Card";
}

/* Selalu true karena apapun yang terjdi akan ada high card */
bool HighCard::check(Game game){
    return true;
}

std::string HighCard::getName() const{
    return this->name;
}
