#include "Switch.hpp"
#include <iostream>

using namespace std;

Switch::Switch() : Ability::Ability(6){
    
}


bool Switch::useAbility(Game<Card>& game, int playerAbility, int playerNumber){
    if (playerAbility == 6 || playerAbility == 0 || playerAbility == -1){
        if (playerAbility == 6){
            cout << game.getPlayer(playerNumber).getName() << " melakukan Switch" << endl;
            cout << "Kartumu sekarang adalah : "<<endl;
            game.getPlayer(playerNumber).printHand();
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
            int count=1;
            for(int i=0;i<game.getPlayers().size();i++){
                if(i != playerNumber){
                    cout<< i+1 <<"." << game.getPlayer(i).getName()<<endl;
                }
            }
            cout<<">";
            int enemyNumber;
            InputEs(enemyNumber);
            enemyNumber--;
            
            cout<<"Kedua kartu " << game.getPlayer(playerNumber).getName() <<" telah ditukar dengan "<< game.getPlayer(enemyNumber).getName()<<"!"<<endl;

            CardList<Card> enemyCard,playerCard;
            enemyCard = game.getPlayer(enemyNumber).getHand();
            playerCard = game.getPlayer(playerNumber).getHand();

            Player player,enemy;
            player = game.getPlayer(playerNumber);
            enemy = game.getPlayer(enemyNumber);
            enemy.setHand(playerCard);
            player.setHand(enemyCard);
            player.setAbility(-1);
            game.setPlayer(playerNumber,player);
            game.setPlayer(enemyNumber,enemy);

            cout << "Kartumu sekarang adalah : "<<endl;
            game.getPlayer(playerNumber).printHand();
            Ability::setUsingAbility(true);
            return true;
        } else if(playerAbility ==-1){
            printPesan2("SWITCH");
        }else if(playerAbility ==0){
            printPesan3("SWITCH");
        }
    } else {
        printPesan("SWITCH");
    }
    return false;
}