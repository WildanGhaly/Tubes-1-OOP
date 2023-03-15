#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Card/CardList.hpp"
#include "../Ability/Ability.hpp"
using namespace std;

class Player : public Valueable<long int>, public Ability {
    public:
        Player();
        Player(string);
        Player(const Player&);
        ~Player();

        string getName() const;
        long int getValue() const;
        int getHandSize() const;
        CardList<Card> getHand() const;
        Card getHand(int) const;
    
        void setName(string);
        void setScore(long int);
        void setHand(CardList<Card>);
        void addHand(Card);
        void addScore(long int);
        void removeHand(Card);
        void removeHand(int);
        void printHand();
        void printCapsa() const;
        void swapCardPosition(int, int);
        void useAbility();
        void removeHand();

        bool operator==(const Player&) const;
        bool operator!=(const Player&) const;
        bool operator<(const Player&) const;
        bool operator>(const Player&) const;
        bool operator<=(const Player&) const;
        bool operator>=(const Player&) const;

        Player& operator=(const Player&);
        Player& operator<<(const Card&);
        Player& operator>>(Card&);

    private:
        string name;
        long int score;
        CardList<Card> hand;
};

#endif