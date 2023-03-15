#ifndef _CARD_LIST_HPP_
#define _CARD_LIST_HPP_

#include "Card.hpp"
#include "../../Exception/Exception.h"

template <class T>
class CardList {
    public:
        /* ctor cctor dtor */
        CardList();
        CardList(int);
        CardList(string);
        CardList(const CardList<T>, const CardList<T>);

        CardList(const CardList&);
        ~CardList();

        /* Getter */
        int getTotalCard() const;
        T getCard(int) const;
        vector<T> getCards() const;

        /* Setter */

        void setCard(int, T);
        void setCards(vector<T>);
        void setCards(CardList<T>);
        void setCardsList(CardList<T>, CardList<T>);


        /* Method */
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);
        void shuffle();
        void sortByNumber();
        void sortByNumberDesc();
        void sortByColor();
        void sortByColorDesc();
        void sortByNumberAndColor();
        void sortByNumberAndColorDesc();
        void sortByColorAndNumber();
        void sortByColorAndNumberDesc();
        void print();

        /* Operator */
        bool operator==(const CardList&) const;
        bool operator!=(const CardList&) const;
        const Card& operator[](int) const;
        CardList& operator=(const CardList&);
        CardList& operator<<(const Card&);
        CardList& operator>>(Card&);

    private:
        vector<T> cards;
};

#endif