#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch(int playerNumber, int enemyNumber){
    vector<Card> enemyCard,playerCard;
    enemyCard = ListPlayerVec::getPlayer(enemyNumber).getCards();
    playerCard = ListPlayerVec::getPlayer(playerNumber).getCards();

    ListPlayerVec::getPlayer(enemyNumber).setCards(playerCard);
    ListPlayerVec::getPlayer(playerNumber).setCards(enemyCard);
}