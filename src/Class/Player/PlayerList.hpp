#ifndef _PLAYER_LIST_HPP_
#define _PLAYER_LIST_HPP_

#include "Player.hpp"

class PlayerList {
    public:
        /* ctor cctor dtor */
        PlayerList();
        PlayerList(int);
        PlayerList(string);

        PlayerList(const PlayerList&);
        ~PlayerList();

        /* Getter */
        int getTotalPlayer() const;
        Player getPlayer(int) const;
        vector<Player> getPlayers() const;
        PlayerList getPlayerss() const;

        /* Setter */
        void setPlayers(vector<Player>);
        void setPlayer(int, Player);
        
        /* Method */
        void addPlayer(Player);
        void removePlayer(Player);
        void removePlayer(int);
        void sortByScore();
        void sortByScoreDesc();
        void print() const;

        /* Operator */
        bool operator==(const PlayerList&) const;
        bool operator!=(const PlayerList&) const;
        Player& operator[](int);
        PlayerList& operator=(const PlayerList&);
        PlayerList& operator<<(const Player&);
        PlayerList& operator>>(Player&);

    protected:
        vector<Player> players;
};

#endif