#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>
#include <string>
#include <cstring>
#include <random>
#include <map>
#include <iomanip>
#include "../../Exception/Exception.h"
#include "../Valueable/Valueable.hpp"
using namespace std;

template <typename T>
map<string, T>create_color_map(T a) {
    map<string, T> colors;
    colors["Green"] = a + 0;
    colors["Blue"] = a + 1;
    colors["Yellow"] = a + 2;
    colors["Red"] = a + 3;
    return colors;
}
class Card : public Valueable<float> {
    public:
        Card();
        Card(int, int);
        Card(string, int);
        Card(const Card&);
        ~Card();

        int getColor() const;
        int getNumber() const;
        string getColorString() const;
        string getNumberString() const;
        map<string, int> getColorMap() const;
        pair<int, string> getNumberPair() const;
        float getValue() const;

        void setColor(int);
        void setNumber(int);
        void setColorString(string);
        void setNumberString(string);
        void setColorMap(map<string, int>);
        void setNumberPair(pair<int, string>);

        void print();
        vector<string> setToPrint(vector<string>);

        bool isColorValid(string);
        bool isNumberValid(string);
        bool operator==(const Card&) const;
        bool operator!=(const Card&) const;
        bool operator>(const Card&) const;
        bool operator<(const Card&) const;
        bool operator>=(const Card&) const;
        bool operator<=(const Card&) const;
        Card& operator=(const Card&);
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
        
    private:
        map<string, int> colors;
        int color;
        pair<int, string> number;
};

#endif
