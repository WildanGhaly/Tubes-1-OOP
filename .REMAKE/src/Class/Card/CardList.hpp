#ifndef _CARD_LIST_HPP_
#define _CARD_LIST_HPP_

#include "Card.cpp"

template <class T>
class CardList {
    public:
        /* ctor cctor dtor */
        CardList();
        CardList(int);
        CardList(string);

        CardList(const CardList&);
        ~CardList();

        /* Getter */
        int getTotalCard() const;
        T getCard(int) const;
        vector<T> getCards() const;

        /* Method */
        void addCard(T);
        void removeCard(T);
        void removeCard(int);
        void shuffle();
        void sortByNumber();
        void sortByNumberDesc();
        void sortByColor();
        void print() const;

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