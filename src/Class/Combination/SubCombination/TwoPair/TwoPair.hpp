#ifndef _TWO_PAIR_HPP_
#define _TWO_PAIR_HPP_

#include "../../Combination.hpp"

class TwoPair : public Combination {
    public:
        TwoPair();
        TwoPair(CardList<Card>);
        TwoPair(const TwoPair&);
        ~TwoPair();

        void computeScore();
};

#endif