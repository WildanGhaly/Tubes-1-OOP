#include "Quadruple.hpp"
using namespace std;

Quadruple::Quadruple(){
    this -> usingQuadruple = false;
}

bool Quadruple::isQuadruple() const {
    return this -> usingQuadruple;
}

void Quadruple::setQuadruple(bool status){
    this -> usingQuadruple = status;
}