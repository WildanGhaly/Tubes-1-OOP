#ifndef __MAXMINAVG_HPP__
#define __MAXMINAVG_HPP__

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T find_max(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T find_min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T find_avg(T a, T b) {
    return (a + b) / 2;
}

template<typename T>
T find_max(T arg) {
    return arg;
}

template<typename T, typename... Args>
T find_max(T arg, Args... args) {
    return max(arg, find_max(args...));
}

template<typename T>
T find_min(T arg) {
    return arg;
}

template<typename T, typename... Args>
T find_min(T arg, Args... args) {
    return min(arg, find_min(args...));
}

template<typename T>
T find_avg(T arg) {
    return arg;
}

template<typename T, typename... Args>
T find_avg(T arg, Args... args) {
    return (arg + find_avg(args...)) / 2;
}

#endif