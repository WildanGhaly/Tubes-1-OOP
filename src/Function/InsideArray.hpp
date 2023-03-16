#ifndef _INSIDE_ARRAYS_HPP_
#define _INSIDE_ARRAYS_HPP_

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
bool insideArray(vector<T> arr, T val) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
};


#endif