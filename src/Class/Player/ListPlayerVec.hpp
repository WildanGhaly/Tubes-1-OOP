#ifndef _LIST_PLAYER_VEC_HPP_
#define _LIST_PLAYER_VEC_HPP_

#include "PlayerVec.cpp"

class ListPlayerVec {
    static int totalListPlayer;
    public:
        /* ctor cctor dtor */
        ListPlayerVec();
        ListPlayerVec(int);
        ListPlayerVec(const ListPlayerVec&);
        ~ListPlayerVec();

        /* Getter */
        int getTotalPlayer() const;
        int getID() const;
        std::vector<PlayerVec> getPlayers() const;
        int getTotalCard() const;
        PlayerVec getPlayer(int) const;

        /* Setter */
        void setPlayers(std::vector<PlayerVec>);
        void setPlayer(int, PlayerVec);

        /* Method */
        void print() const;
        void print(int) const;
        void print(int, int) const;
        void addCard(Card); // add same card to all player
        void addCard(Card, int); // add card to specific player
        void addCard(CardDeckVec&, int); // add card from deck to specific player
        void removeCard(Card); // remove same card from all player
        void removeCard(Card, int); // remove card from specific player
        void removeCard(int); // remove card from all player in index int
        void addScore(int); // add score to all player
        void addScore(int, int); // add score to specific player

        /* Operator */
        bool operator==(const ListPlayerVec&) const;
        bool operator!=(const ListPlayerVec&) const;
        ListPlayerVec& operator=(const ListPlayerVec&);

    protected:
        int ID;
        std::vector<PlayerVec> players;
        // std::string name; BISA PAKAI MAPPING NANTI
};

#endif