#include "AbilityLess.hpp"


Abilityless::Abilityless() : Ability::Ability(7){

}
void Abilityless::useAbility(int playerNumber){
    cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: "<<endl;
    int count=1;
    for(int i=0;i<PlayerList::getPlayers().size();i++){
        if(i != playerNumber){
            cout<< count <<"." << PlayerList::getPlayer(i).getNickname();
            count++;
        }
    }

    cout<<">";
    int enemyNumber;
    cin >> enemyNumber;
    if()

    cout<<"Kartu ability " << PlayerList::getPlayer(enemyNumber).getNickname() <<" telah dimatikan."<<endl;

    Ability::setUsingAbility(true);
}