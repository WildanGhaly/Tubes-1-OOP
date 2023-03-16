#include "Ability.hpp"
using namespace std;


Ability::Ability(){
    this -> usingAbility = false;
}


Ability::Ability(int ability_id){
    this -> usingAbility = false;
    
}

Ability::Ability(const Ability& Ability){
    this -> usingAbility = Ability.usingAbility;
    
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
    std::cout << "Oops, kartu ability "<< ability << " mu telah digunakan sebelumnya:(."<<std::endl;
    std::cout<< "Silahkan lakukan perintah lain."<<std::endl;
}

void Ability::printPesan3(string ability){
    std::cout << "Oops, kartu ability "<< ability << " mu telah dimatikan :(."<<std::endl;
    std::cout<< "Silahkan lakukan perintah lain."<<std::endl;
}