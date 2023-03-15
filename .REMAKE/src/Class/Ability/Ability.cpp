#include "Ability.hpp"
using namespace std;


Ability::Ability(){
    this -> ability_id = 0;
    this -> usingAbility = false;
}


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

void Ability::printPesan(string ability){
    std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability "<<ability<<"."<<std::endl;
    std::cout<< "Silahkan lakukan perintah lain."<<std::endl;
}

void Ability::printPesan2(string ability){
    std::cout << "Oops, kartu ability"<< ability << "mu telah dimatikan sebelumnya:(."<<std::endl;
    std::cout<< "Silahkan lakukan perintah lain."<<std::endl;
}