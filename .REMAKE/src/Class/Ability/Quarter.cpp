#include "Quarter.hpp"
using namespace std;

template <class T>
Quarter<T>::Quarter() : Ability::Ability(3){

}

template <class T>
T Quarter<T>::useAbility(T score){
    Ability::setUsingAbility(true);
    return score / 4;
}