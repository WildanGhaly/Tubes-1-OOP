#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "../Card/CardList.hpp"

template <class V>
class Table : public Valueable<long long int> {
    public:
        Table();
        Table(CardList<V>, int);
        Table(string);
        Table(const Table&);
        ~Table();

        /* Getter */
        CardList<V> getCards() const;
        CardList<V> getDeck() const;
        int getTotalCard() const;
        V getCard(int) const;
        int getRound() const;
        long long int getValue() const;

        /* Setter */
        void setDeck(CardList<V>);
        void setCards(CardList<V>);
        int setRound(int);
        long long int setReward(long long int);

        /* Method */
        void print();
        void addCard(V);
        void addRound();
        void nextRound();
        void removeCard(V);
        void removeCard(int);
        void removeCards();
        void shuffle();
        void removeDeckFirst();

        /* Operator */
        bool operator==(const Table&) const;
        bool operator!=(const Table&) const;
        Table& operator=(const Table&);
        Table& operator<<(const V&);
        Table& operator>>(V&);

    protected:
        int round;
        long long int reward;
        CardList<V> cards;
        CardList<V> deck;
};

#endif