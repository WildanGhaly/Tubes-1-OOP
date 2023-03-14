#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch() : Ability::Ability(6){
    
}


void Switch::useAbility(int playerNumber){
    cout << ListPlayerVec::getPlayer(playerNumber).getNickname() << " melakukan Switch" << endl;
    cout << "Kartumu sekarang adalah : "<<endl;
    ListPlayerVec::getPlayer(playerNumber).print();
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    int count=1;
    for(int i=0;i<ListPlayerVec::getPlayers().size();i++){
        if(i != playerNumber){
            cout<< count <<"." << ListPlayerVec::getPlayer(i).getNickname();
            count++;
        }
    }
    cout<<">";
    int enemyNumber;
    cin >> enemyNumber;
    
    cout<<"Kedua kartu " << ListPlayerVec::getPlayer(playerNumber).getNickname() <<" telah ditukar dengan "<< ListPlayerVec::getPlayer(enemyNumber).getNickname()<<"!";

    vector<Card> enemyCard,playerCard;
    enemyCard = this->ListPlayerVec::getPlayer(enemyNumber).getCards();
    playerCard = this->ListPlayerVec::getPlayer(playerNumber).getCards();

    this->ListPlayerVec::getPlayer(enemyNumber).setCards(playerCard);
    this->ListPlayerVec::getPlayer(playerNumber).setCards(enemyCard);

    Ability::setUsingAbility(true);

    cout << "Kartumu sekarang adalah : "<<endl;
    ListPlayerVec::getPlayer(playerNumber).print();
}