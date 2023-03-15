#ifndef __RULES_HPP__
#define __RULES_HPP__

#include "../Game/GameVec.hpp"
#include "GenericRules.hpp"

class Rules {
    static int IDcounter;
    const int combination = 7;
    public:
        Rules();
        Rules(Table, PlayerVec);
        Rules(const Rules&);
        ~Rules();

        /* Getter */
        int getID() const;
        float getScore() const;
        PlayerVec getPlayer() const;
        std::vector<Card> getCards() const;
        Card getCard(int) const;
        int getCombination() const;

        /* Setter */
        void setID(int);
        void setScore(float);
        void setPlayer(PlayerVec);
        void setCards(vector<Card> cards);

        /* Method */
        void print() const;
        void print(int) const;
        void print(int, int) const;
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);
        void addScore(float);
        virtual void computeScore();

        /* Operator */
        bool operator==(const Rules&) const;
        bool operator!=(const Rules&) const;
        Rules& operator=(const Rules&);

    private:
        int ID;
        float score;
        PlayerVec player;
        std::vector<Card> cards;
};

#endif