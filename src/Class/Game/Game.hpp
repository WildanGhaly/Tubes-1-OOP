#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "../Player/ListPlayer.cpp"

class Game {
    public:
        /* ctor cctor dtor */
        Game();
        Game(int);
        Game(const Game&);
        ~Game();

        /* Getter */
        ListPlayer getPlayers() const;
        CardDeck getDeck() const;
        int getTotalCard() const;

        /* Setter */
        void setPlayers(ListPlayer);
        void setDeck(CardDeck);

        /* Method */
        void print() const;
        // void addPlayer(Player);
        // void removePlayer(Player);
        // void removePlayer(int);
        // void addCard(Card);
        // void removeCard(Card);
        // void removeCard(int);
        // void shuffle();
        void start();
        void start(int);
        
        /* Operator */
        bool operator==(const Game&) const;
        bool operator!=(const Game&) const;
        Game& operator=(const Game&);

    private:
        ListPlayer players;
        CardDeck deck;
};
#endif