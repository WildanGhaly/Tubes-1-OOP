#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Card/CardList.cpp"

#define LEFT 0
#define RIGHT 1

class Player {
    static int totalPlayer;
    public:
        Player();
        Player(std::string);
        Player(const Player&);
        ~Player();

        /* Getter */
        int getID() const;
        int getPoint() const;
        int getAbility() const;
        int getIsTurn() const;
        int getCardCount() const;
        Card getCard(int) const;
        std::string getName() const;

        /* Setter */
        void setID(int);
        void setPoint(int);
        void setAbility(int);
        void setIsTurn(int);
        // void setName(std::string); 
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);

        /* Operator */
        bool operator==(const Player&) const;
        bool operator!=(const Player&) const;
        bool operator>(const Player&) const;
        bool operator<(const Player&) const;
        bool operator>=(const Player&) const;
        bool operator<=(const Player&) const;
        Player& operator=(const Player&);

        void print();
    
    
    private:
        Card* cards;
        int ID;
        // std::string name;
        int point;
        int ability; // pecah
        bool isTurn;
        int cardCount;
};

#endif