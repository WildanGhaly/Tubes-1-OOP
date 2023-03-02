#ifndef _GAME_VEC_HPP_
#define _GAME_VEC_HPP_

#include "../Player/ListPlayerVec.cpp"
#include "../Table/Table.cpp"

class GameVec {
    static int totalGame;
    public:
        /* ctor cctor dtor */
        GameVec();
        GameVec(int);
        GameVec(const GameVec&);
        ~GameVec();

        /* Getter */
        ListPlayerVec getPlayers() const;
        CardDeckVec getDeck() const;
        int getTotalCard() const;
        int getID() const;
        Card getCard(int) const;
        PlayerVec getPlayer(int) const;
        Table getTable() const;
    
        /* Setter */
        void setPlayers(ListPlayerVec);
        void setDeck(CardDeckVec);
        void setTable(Table);
    
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
        void start(int, int);
        // void nextTurn();
        void nextRound();
    
        /* Operator */
        bool operator==(const GameVec&) const;
        bool operator!=(const GameVec&) const;
        GameVec& operator=(const GameVec&);
    
    private:
        ListPlayerVec players;
        CardDeckVec deck;
        Table table;
        int ID;

};

#endif