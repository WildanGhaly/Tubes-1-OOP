#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch(int playerNumber, int enemyNumber){
    vector<Card> enemyCard,playerCard;
    enemyCard = GameVec::getPlayers().getPlayer(enemyNumber).getCards();
    playerCard = GameVec::getPlayers().getPlayer(playerNumber).getCards();

    GameVec::getPlayers().getPlayer(enemyNumber).setCards(playerCard);
    GameVec::getPlayers().getPlayer(playerNumber).setCards(enemyCard);
}