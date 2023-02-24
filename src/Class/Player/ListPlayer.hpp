#ifndef _LIST_PLAYER_HPP_
#define _LIST_PLAYER_HPP_

#include "Player.hpp"

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
        Player getPlayer(int) const;

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

        /* Operator */
        bool operator==(const ListPlayer&) const;
        bool operator!=(const ListPlayer&) const;

    private:
        Player* players;
        int totalPlayer;
        int firstLastPlayer;
        bool isReverse;
};

#endif