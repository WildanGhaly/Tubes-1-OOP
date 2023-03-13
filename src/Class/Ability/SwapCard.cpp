#include "SwapCard.hpp"

using namespace std;

SwapCard::SwapCard(int player1, int player2,int player1CardIdx, int player2CardIdx){
    Card player1Card = GameVec::getPlayers().getPlayer(player1).getCard(player1CardIdx);
    Card player2Card = GameVec::getPlayers().getPlayer(player2).getCard(player2CardIdx);
    vector<Card> temp1, temp2;

    if(player2CardIdx == 0){
        vector<Card> temp1 = {player1Card, GameVec::getPlayers().getPlayer(player2).getCard(1)};
    }else if(player2CardIdx == 1){
        vector<Card> temp1 = {GameVec::getPlayers().getPlayer(player1).getCard(0), player1Card};
    }
    if(player1CardIdx == 0){
        vector<Card> temp2 = {player2Card, GameVec::getPlayers().getPlayer(player1).getCard(1)};
    }else if(player1CardIdx == 1){
        vector<Card> temp2 = {GameVec::getPlayers().getPlayer(player1).getCard(0), player2Card};
    }

    GameVec::getPlayers().getPlayer(player2).setCards(temp1);
    GameVec::getPlayers().getPlayer(player1).setCards(temp2);

}