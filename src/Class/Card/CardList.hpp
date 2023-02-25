#ifndef _CARD_LIST_HPP_
#define _CARD_LIST_HPP_

#include "Card.cpp"

class CardDeck {
    static int totalDeck;
    public:
        /* ctor cctor dtor */
        CardDeck();
        CardDeck(int);
        CardDeck(const CardDeck&);
        ~CardDeck();

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
        bool operator==(const CardDeck&) const;
        bool operator!=(const CardDeck&) const;
        Card& operator[](int) const;
        CardDeck& operator=(const CardDeck&);

    private:
        Card* cards;
        int totalCard;
        int ID;
};

#endif