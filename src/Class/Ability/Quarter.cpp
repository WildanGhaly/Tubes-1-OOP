#include "Quarter.hpp"
using namespace std;

Quarter::Quarter(){
    this -> usingQuarter = false;
}

bool Quarter::isQuarter() const {
    return this -> usingQuarter;
}

void Quarter::setQuarter(bool status){
    this -> usingQuarter = status;
}