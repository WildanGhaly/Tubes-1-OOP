#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Card/CardList.hpp"

class Combination : public Valueable<float> {
    public:
        Combination();
        Combination(CardList<Card>);
        Combination(const Combination&);
        ~Combination();

        CardList<Card> getCards() const;
        Card getCard(int) const;
        float getValue() const;

        void setCards(CardList<Card>);
        void setCard(int, Card);
        void setPoint(float);
        virtual void computeScore() = 0;

        bool operator==(const Combination&) const;
        bool operator!=(const Combination&) const;
        bool operator<(const Combination&) const;
        bool operator>(const Combination&) const;
        bool operator<=(const Combination&) const;
        bool operator>=(const Combination&) const;

        Combination& operator=(const Combination&);
        Combination& operator<<(const Card&);
        Combination& operator>>(Card&);

    protected:
        CardList<Card> cards;
        float point;
};

#endif