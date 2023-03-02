#include "Ability.hpp"
using namespace std;

Ability::Ability(char* ability){
    this->Ability_name = new char[strlen(ability)];
    strcpy(this->Ability_name, ability);
}
Ability::Ability(const Ability& Ability){
    this -> Ability_name = new char[strlen(Ability.Ability_name)];
    this -> Ability_name = Ability.Ability_name;
}
char* Ability::getAbility() const{
    return this-> Ability_name;
}
void Ability::setAbility(char* ability){
    strcpy(this -> Ability_name, ability);
}