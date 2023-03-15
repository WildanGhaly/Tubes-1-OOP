#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Card/CardList.hpp"
// #include "../Ability/Ability.hpp"
using namespace std;

class Player : public Valueable<long long int> {
    public:
        Player();
        Player(string);
        Player(const Player&);
        ~Player();

        string getName() const;
        long long int getValue() const;
        int getHandSize() const;
        CardList<Card> getHand() const;
        Card getHand(int) const;
        int getAbility() const;
    
        void setName(string);
        void setScore(long long int);
        void setHand(CardList<Card>);
        void setAbility(int);
        void addHand(Card);
        void addScore(long long int);
        void removeHand(Card);
        void removeHand(int);
        void printHand();
        void printCapsa() const;
        void swapCardPosition(int, int);
        void removeHand() {};

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
        long long int score;
        CardList<Card> hand;
        int ability;
};

#endif