#ifndef _PLAYER_VEC_HPP_
#define _PLAYER_VEC_HPP_

#include "../Card/CardListVec.cpp"

class PlayerVec {
    static int totalPlayer;
    public:
        /* ctor cctor dtor */
        PlayerVec();
        PlayerVec(int);
        PlayerVec(const PlayerVec&);
        ~PlayerVec();

        /* Getter */
        int getID() const;
        float getScore() const;
        std::vector<Card> getCards() const;
        int getTotalCard() const;
        Card getCard(int) const;

        /* Setter */
        void setID(int);
        void setScore(int);
        void setCards(std::vector<Card>);

        /* Method */
        void print() const;
        void print(int) const;
        void print(int, int) const;
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);
        void addScore(int);

        /* Operator */
        bool operator==(const PlayerVec&) const;
        bool operator!=(const PlayerVec&) const;
        PlayerVec& operator=(const PlayerVec&);

    private:
        int ID;
        float score;
        std::vector<Card> cards;
        // std::string name; BISA PAKAI MAPPING NANTI
};

#endif