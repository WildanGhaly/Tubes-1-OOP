#include "Reroll.hpp"
using namespace std;

Reroll::Reroll() : Ability::Ability(1) {

}

void Reroll::useAbility(){
    for (int i = 0; i < 2; i++){
        PlayerVec::removeCard(i);
    }
    Ability::setUsingAbility(true);
}