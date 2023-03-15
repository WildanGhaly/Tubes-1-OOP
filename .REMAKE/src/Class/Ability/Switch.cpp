#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch() : Ability::Ability(6){
    
}


void Switch::useAbility(int playerNumber){
    cout << PlayerList::getPlayer(playerNumber).getName() << " melakukan Switch" << endl;
    cout << "Kartumu sekarang adalah : "<<endl;
    PlayerList::getPlayer(playerNumber).printHand();
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    int count=1;
    for(int i=0;i<PlayerList::getPlayers().size();i++){
        if(i != playerNumber){
            cout<< count <<"." << PlayerList::getPlayer(i).getName();
            count++;
        }
    }
    cout<<">";
    int enemyNumber;
    cin >> enemyNumber;
    
    cout<<"Kedua kartu " << PlayerList::getPlayer(playerNumber).getName() <<" telah ditukar dengan "<< PlayerList::getPlayer(enemyNumber).getName()<<"!";

    CardList<Card> enemyCard,playerCard;
    enemyCard = this->PlayerList::getPlayer(enemyNumber).getHand();
    playerCard = this->PlayerList::getPlayer(playerNumber).getHand();

    this->PlayerList::getPlayer(enemyNumber).setHand(playerCard);
    this->PlayerList::getPlayer(playerNumber).setHand(enemyCard);

    Ability::setUsingAbility(true);

    cout << "Kartumu sekarang adalah : "<<endl;
    PlayerList::getPlayer(playerNumber).printHand();
}