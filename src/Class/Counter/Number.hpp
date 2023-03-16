#ifndef _NUMBER_HPP_
#define _NUMBER_HPP_

#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
vector<int> countElements (T arr, U size, U max){
    vector<int> count (max + 1);
    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }
}

#endif