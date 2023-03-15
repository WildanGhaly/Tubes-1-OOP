#include "SwapCard.hpp"

using namespace std;

SwapCard::SwapCard() : Ability::Ability(6){
    
}

void SwapCard::useAbility(int player1, int player2,int player1CardIdx, int player2CardIdx){

    Card player1Card = this->PlayerList::getPlayer(player1).getHand(player1CardIdx);
    Card player2Card = this->PlayerList::getPlayer(player2).getHand(player2CardIdx);
    vector<Card> temp1, temp2;

    if(player2CardIdx == 0){
        vector<Card> temp1 = {player1Card, this->PlayerList::getPlayer(player2).getHand(1)};
    }else if(player2CardIdx == 1){
        vector<Card> temp1 = {this->PlayerList::getPlayer(player1).getHand(0), player1Card};
    }
    if(player1CardIdx == 0){
        vector<Card> temp2 = {player2Card, this->PlayerList::getPlayer(player1).getHand(1)};
    }else if(player1CardIdx == 1){
        vector<Card> temp2 = {this->PlayerList::getPlayer(player1).getHand(0), player2Card};
    }
    CardList<Card> temp11 = CardList<Card>();
    CardList<Card> temp12 = CardList<Card>();
    temp11.setCards(temp1);
    temp12.setCards(temp2);


    this->PlayerList::getPlayer(player2).setHand(temp11);
    this->PlayerList::getPlayer(player1).setHand(temp12);


    Ability::setUsingAbility(true);
}