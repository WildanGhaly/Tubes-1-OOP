#include "AbilityLess.hpp"


Abilityless::Abilityless() : Ability::Ability(7){

}
void Abilityless::useAbility(){
    
    Ability::setUsingAbility(true);
}