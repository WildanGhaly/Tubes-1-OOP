#include "Quadruple.hpp"
using namespace std;


Quadruple::Quadruple() : Ability::Ability(2) {
    
}

bool Quadruple::useAbility(Game<Card>& game, int playerAbility, int player){
    Player players;
    if (playerAbility == 2 || playerAbility == 0 || playerAbility == -2){
        if (playerAbility == 2){
            game.setReward(game.getValue() * 4);
            players = game.getPlayer(player);
            players.setAbility(-2);
            game.setPlayer(player, players);
            Ability::setUsingAbility(true);
            
            return true;
        } else if(playerAbility ==-2){
            printPesan2("QUADRUPLE");
        }else if(playerAbility == 0){
            printPesan2("QUADRUPLE");
        }
    } else {
        printPesan("QUADRUPLE");
    }
    return false;
}
