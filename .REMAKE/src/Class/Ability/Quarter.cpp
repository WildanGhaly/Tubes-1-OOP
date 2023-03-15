#include "Quarter.hpp"
using namespace std;


Quarter::Quarter() : Ability::Ability(3){

}

bool Quarter::useAbility(Game<Card>& game, int playerAbility, int player){
    Player players;
    if (playerAbility == 3){
        if (Quarter::isUsingAbility() == false){
            game.setReward(game.getValue() / 4);
            players = game.getPlayer(player);
            players.setAbility(-1);
            game.setPlayer(player, players);
            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan2("QUARTER");
        }
    } else {
        printPesan("QUARTER");
    }
    return false;
}