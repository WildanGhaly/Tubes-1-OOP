#include "Quarter.hpp"
using namespace std;


Quarter::Quarter() : Ability::Ability(3){

}

bool Quarter::useAbility(Game<Card>& game, int playerAbility, int player){
    if (playerAbility == 3){
        if (Quarter::isUsingAbility() == false){
            game.setReward(game.getValue() / 4);
            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan("QUARTER");
        }
    } else {
        printPesan2("QUARTER");
    }
    return false;
}