#ifndef _FULL_HOUSE_HPP_
#define _FULL_HOUSE_HPP_

#include "../../Combination.hpp"

class FullHouse : public Combination {
    public:
        FullHouse();
        FullHouse(CardList<Card>);
        FullHouse(const FullHouse&);
        ~FullHouse();

        void computeScore();
};

#endif