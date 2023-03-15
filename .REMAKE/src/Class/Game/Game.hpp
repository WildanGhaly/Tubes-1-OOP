#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "../Player/PlayerList.hpp"
#include "../Table/Table.hpp"

template <class W>
class Game : public PlayerList, public Table<W> {
    // static int totalGame;
    public:
        /* ctor cctor dtor */
        Game();
        Game(int);
        Game(int, string);
        Game(const Game&);
        ~Game();

        // /* Getter */
        // PlayerList getPlayers() const;
        // CardList getDeck() const;
        // int getTotalCard() const;
        // int getTotalPlayer() const;
        // static int getTotalGame();
        // int getTotalTableCard() const;
        // int getID() const;
        // W getCard(int) const;
        // Player getPlayer(int) const;
        // Table getTable() const;
    
        /* Setter */
        void setPlayers(vector<Player>);
        void setPlayer(int, Player);
        void setDeck(CardList<W>);
        void setTable(CardList<W>);
        void setRound(int);
    
        /* Method */
        void print();
        // void addPlayer(Player);
        // void removePlayer(Player);
        // void removePlayer(int);
        // void addCard(W);
        // void removeCard(W);
        // void removeCard(int);
        // void shuffle();
        void start();
        void start(int);
        // void start(int, int);
        // void nextTurn();
        void nextRound();


        // /* Operator */
        // bool operator==(const Game&) const;
        // bool operator!=(const Game&) const;
        // Game& operator=(const Game&);

    // private:
    //     PlayerList players;
    //     CardList deck;
    //     Table table;
    //     int ID;
};

#endif