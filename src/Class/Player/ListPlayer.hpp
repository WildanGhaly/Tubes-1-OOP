#ifndef _LIST_PLAYER_HPP_
#define _LIST_PLAYER_HPP_

#include "Player.cpp"

class ListPlayer {
    public:
        /* ctor cctor dtor */
        ListPlayer();
        ListPlayer(int);
        ListPlayer(const ListPlayer&);
        ~ListPlayer();

        /* Getter */
        int getTotalPlayer() const;
        int getFirstLastPlayer() const;
        bool getIsReverse() const;
        Player getPlayer(int);

        /* Setter */
        void setTotalPlayer(int);
        void setFirstLastPlayer(int);
        void setPlayer(int, Player);
        void setIsReverse(bool);

        /* Method */
        void addPlayer(Player);
        void removePlayer(Player);
        void removePlayer(int);
        void sortByPoint();
        void print() const ;
        void addCard(CardDeck&, int);

        /* Operator */
        bool operator==(const ListPlayer&) const;
        bool operator!=(const ListPlayer&) const;
        Player& operator[](int);
        ListPlayer& operator=(const ListPlayer&);

        friend class Game;
    private:
        Player* players;
        int totalPlayer;
        int firstLastPlayer;
        bool isReverse;
};

#endif