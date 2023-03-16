#ifndef _STRAIGHT_HPP_
#define _STRAIGHT_HPP_

#include "../../Combination.hpp"

class Straight : public Combination {
    public:
        Straight();
        Straight(CardList<Card>);
        Straight(const Straight&);
        ~Straight();

        void computeScore();
};

#endif