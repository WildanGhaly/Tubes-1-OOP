#include "Quadruple.hpp"
using namespace std;

Quadruple::Quadruple() : Ability::Ability(2) {
    
}
void Quadruple::useAbility(){
    Table::setScore(Table::getScore() * 4);
    Ability::setUsingAbility(true);
}

