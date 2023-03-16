#include "Quarter.hpp"
using namespace std;


Quarter::Quarter() : Ability::Ability(3){

}

bool Quarter::useAbility(Game<Card>& game, int playerAbility, int player){
    Player players;
    if (playerAbility == 3 || playerAbility == 0 || playerAbility == -3){
        if (playerAbility == 3){
            game.setReward(game.getValue() / 4);
            players = game.getPlayer(player);
            players.setAbility(-3);
            game.setPlayer(player, players);
            // if(game.getValue()<=1){
            //     game.setReward(1);
            // }
            Ability::setUsingAbility(true);
            return true;
        } else if(playerAbility ==-3){
            printPesan2("QUARTER");
        }else if(playerAbility ==0){
            printPesan3("QUARTER");
        }
    } else {
        printPesan("QUARTER");
    }
    return false;
}