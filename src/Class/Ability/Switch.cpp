#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch() : Ability::Ability(6){
    
}


void Switch::useAbility(int playerNumber, int enemyNumber){
    vector<Card> enemyCard,playerCard;
    enemyCard = this->ListPlayerVec::getPlayer(enemyNumber).getCards();
    playerCard = this->ListPlayerVec::getPlayer(playerNumber).getCards();

    this->ListPlayerVec::getPlayer(enemyNumber).setCards(playerCard);
    this->ListPlayerVec::getPlayer(playerNumber).setCards(enemyCard);

    Ability::setUsingAbility(true);
}