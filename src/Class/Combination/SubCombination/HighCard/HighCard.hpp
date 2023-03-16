#ifndef _HIGH_CARD_HPP_
#define _HIGH_CARD_HPP_

#include "../../Combination.hpp"

class HighCard : public Combination {
    public:
        HighCard();
        HighCard(CardList<Card>);
        HighCard(const HighCard&);
        ~HighCard();

        void computeScore();
};

#endif
