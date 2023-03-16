#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Card/CardList.hpp"
// #include "../Ability/Ability.hpp"
using namespace std;

template <typename T>
map<T, string>create_player_ability(T a){
    map<T, string> abilityName;
    abilityName[0 + a] = "telah dimatikan";
    abilityName[1 + a] = "Reroll";
    abilityName[2 + a] = "Quadruple";
    abilityName[3 + a] = "Quarter";
    abilityName[4 + a] = "Reverse Direction";
    abilityName[5 + a] = "Swap Card";
    abilityName[6 + a] = "Switch";
    abilityName[7 + a] = "Abilityless";
    abilityName[-1 + a] = "Reroll telah digunakan";
    abilityName[-2 + a] = "Quadruple telah digunakan";
    abilityName[-3 + a] = "Quarter telah digunakan";
    abilityName[-4 + a] = "Reverse Direction telah digunakan";
    abilityName[-5 + a] = "Swap Card telah digunakan";
    abilityName[-6 + a] = "Switch telah digunakan";
    abilityName[-7 + a] = "Abilityless telah digunakan";
    return abilityName;
}

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
        string getAbilityName() const;
    
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
        map<int, string> abilityName;
};

#endif