#include "Quadruple.hpp"
using namespace std;


Quadruple::Quadruple() : Ability::Ability(2) {
    
}

bool Quadruple::useAbility(Game<Card>& game, int playerAbility, int player){
    Player players;
    if (playerAbility == 2){
        if (Quadruple::isUsingAbility() == false){
            game.setReward(game.getValue() * 4);
            players = game.getPlayer(player);
            players.setAbility(-1);
            game.setPlayer(player, players);
            Ability::setUsingAbility(true);
            
            return true;
        } else {
            printPesan2("QUADRUPLE");
        }
    } else {
        printPesan("QUADRUPLE");
    }
    return false;
}
