#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Card/CardList.cpp"

class Player {
    public:
        Player();
        Player(string);
        Player(const Player&);
        ~Player();

        string getName() const;
        int getScore() const;
        int getHandSize() const;
        CardList<Card> getHand() const;
        Card getHand(int) const;
    
        void setName(string);
        void setScore(int);
        void setHand(CardList<Card>);
        void addHand(Card);
        void removeHand(Card);
        void removeHand(int);
        void printHand() const;

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
        int score;
        CardList<Card> hand;
};

#endif