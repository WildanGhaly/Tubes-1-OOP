#ifndef _DOUBLEVALUE_HPP_
#define _DOUBLEVALUE_HPP_

#include <vector>
#include <iostream>
#include "../Class/Card/Card.hpp"
#include "../Class/Card/CardList.hpp"
using namespace std;

// template <typename T>
bool DoubleValue(CardList<Card> arr) {
    for (int i = 0; i < arr.getTotalCard() ; i++) {
        for (int j = i + 1; j < arr.getTotalCard(); j++) {
            if( (i != j)){
            if ((arr[i] == arr[j])) {
                return true;
            }
            }
        }
    }
    return false;
}

#endif