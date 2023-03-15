#include "Ability.hpp"
using namespace std;

Ability::Ability(int ability_id){
    this -> ability_id = ability_id;
    this -> usingAbility = false;
}

Ability::Ability(const Ability& Ability){
    this -> ability_id = Ability.ability_id;
    this -> usingAbility = Ability.usingAbility;
}
int Ability::getAbility() const{
    return this-> ability_id;
}
void Ability::setAbility(int ability_id){
    this -> ability_id = ability_id;
}
bool Ability::isUsingAbility() const {
    return this -> usingAbility;
}
        
void Ability::setUsingAbility(bool usingAbility){
    this -> usingAbility = usingAbility;
}