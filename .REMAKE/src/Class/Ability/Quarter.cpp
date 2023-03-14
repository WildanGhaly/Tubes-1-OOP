#include "Quarter.hpp"
using namespace std;

Quarter::Quarter() : Ability::Ability(3){

}

void Quarter::useAbility(){
    Table::setScore(Table::getScore() / 4);
    Ability::setUsingAbility(true);
}