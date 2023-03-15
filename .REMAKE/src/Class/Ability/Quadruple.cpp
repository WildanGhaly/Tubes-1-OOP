#include "Quadruple.hpp"
using namespace std;


Quadruple::Quadruple() : Ability::Ability(2) {
    
}

bool Quadruple::useAbility(Game<Card>& game, int playerAbility, int player){
    if (playerAbility == 2){
        if (Quadruple::isUsingAbility() == false){
            game.setReward(game.getValue() * 4);
            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan("QUADRUPLE");
        }
    } else {
        printPesan2("QUADRUPLE");
    }
    return false;
}
