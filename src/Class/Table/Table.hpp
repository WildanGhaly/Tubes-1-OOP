#ifndef _TABLE_HPP_
#define _TABLE_HPP_

// #include "../Card/CardListVec.cpp"
#include <vector>
#include <algorithm>

class Table {
    public:
        /* ctor cctor dtor */
        Table();
        Table(CardDeckVec, int);
        Table(const Table&);
        ~Table();

        /* Getter */
        std::vector<Card> getCards() const;
        int getTotalCard() const;
        Card getCard(int) const;
        int getRound() const;

        /* Setter */
        void setCards(CardDeckVec);
        int setRound(int);

        /* Method */
        void print() const;
        void addCard(Card);
        void addRound();
        void nextRound(CardDeckVec&);
        void removeCard(Card);
        void removeCard(int);
        void shuffle();

        /* Operator */
        bool operator==(const Table&) const;
        bool operator!=(const Table&) const;
        Table& operator=(const Table&);

    private:
        std::vector<Card> cards;
        int round;
};

#endif