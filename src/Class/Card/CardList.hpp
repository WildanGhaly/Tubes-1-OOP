#ifndef _CARD_LIST_HPP_
#define _CARD_LIST_HPP_

#include "Card.hpp"

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
        void shuffle();
        void sortByNumber();
        void sortByColor();
        void sortByID();

        /* Operator */
        bool operator==(const CardDeck&) const;
        bool operator!=(const CardDeck&) const;

    private:
        Card* cards;
        int totalCard;
        int ID;
};

#endif