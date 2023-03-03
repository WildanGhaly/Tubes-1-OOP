#include "SwapCard.hpp"

using namespace std;

SwapCard::SwapCard(int playerNumber, int enemyNumber,int playerCardIdx, int enemyCardIdx){
    Card enemyCard = ListPlayerVec::getPlayer(enemyNumber).getCard(enemyCardIdx);
    Card myCard = ListPlayerVec::getPlayer(playerNumber).getCard(playerCardIdx);
    vector<Card> temp1, temp2;

    if(enemyCardIdx == 0){
        vector<Card> temp1 = {myCard, ListPlayerVec::getPlayer(enemyNumber).getCard(1)};
    }else if(enemyCardIdx == 1){
        vector<Card> temp1 = {ListPlayerVec::getPlayer(enemyNumber).getCard(0), myCard};
    }
    if(playerCardIdx == 0){
        vector<Card> temp2 = {enemyCard, ListPlayerVec::getPlayer(playerNumber).getCard(1)};
    }else if(playerCardIdx == 1){
        vector<Card> temp2 = {ListPlayerVec::getPlayer(playerNumber).getCard(0), enemyCard};
    }

    ListPlayerVec::getPlayer(enemyNumber).setCards(temp1);
    ListPlayerVec::getPlayer(playerNumber).setCards(temp2);

}