// class Card(id, color, number)
// class deskCard(listOfCard)
// class player(listOfCard, playerId, name, point, ability, isTurn)
// class listOfPlayer(listOfPlayer, boolean isReverse, firstLastPlayer)
// class game(pair, listofplayer, listOfCard, round, match, constant 2^32, long)
// generic function -> list circular

#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <string>
#include <iostream>

#define GREEN 0
#define BLUE 1
#define YELLOW 2
#define RED 3

class Card {
    static int IDCounter;
    public:
        /* ctor cctor dtor */
        Card();
        Card(int, int);
        Card(const Card&);
        ~Card();
        
        /* Setter */
        void setNumber(int);
        void setColor(int);
        void setColor(std::string);

        /* getter */
        int getNumber() const;
        int getColor() const;
        int getID() const;
        void input();
        std::string getColorAsString() const;
        std::string getCardNumberAsString() const;
        std::string toString() const;

        /* operator */
        Card &operator=(const Card&);
        bool operator==(const Card&) const;
        bool operator!=(const Card&) const;
        // bool operator<(const Card&) const;
        // bool operator>(const Card&) const;
        // bool operator<=(const Card&) const;
        // bool operator>=(const Card&) const;
        // Card& operator=(const Card&);

        /* method */
        void print() const;

    private:
        int number;
        int color;
        int IDCard;
};

#endif