#ifndef _DOUBLEVALUE_HPP_
#define _DOUBLEVALUE_HPP_

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
bool DoubleValue(vector<T> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if ((arr[i] == arr[j]) && (i != j)) {
                return true;
            }
        }
    }
    return false;
}

#endif