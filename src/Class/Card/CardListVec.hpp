#ifndef _CARD_LIST_VEC_HPP_
#define _CARD_LIST_VEC_HPP_

#include "Card.cpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class CardDeckVec {
    static int totalDeck;
    public:
        /* ctor cctor dtor */
        CardDeckVec();
        CardDeckVec(int);
        CardDeckVec(const CardDeckVec&);
        ~CardDeckVec();

        /* Getter */
        int getTotalCard() const;
        int getID() const;
        Card getCard(int) const;

        /* Method */
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);
        void shuffle();
        void sortByNumber();
        void sortByColor();
        void sortByID();
        void print() const;

        /* Operator */
        bool operator==(const CardDeckVec&) const;
        bool operator!=(const CardDeckVec&) const;
        Card& operator[](int) const;
        CardDeckVec& operator=(const CardDeckVec&);

    private:
        vector<Card> cards;
        int totalCard;
        int ID;
};

#endif