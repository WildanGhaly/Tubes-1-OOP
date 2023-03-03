#ifndef _GENERIC_RULES_HPP
#define _GENERIC_RULES_HPP

#include <iostream>
#include <vector>

template <typename T, typename U>
std::vector<int> countElements(T arr, U size, U max) {
    std::vector<int> count(max + 1);
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    return count;
}

#endif