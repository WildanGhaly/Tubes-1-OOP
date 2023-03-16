#ifndef _FLUSH_HPP_
#define _FLUSH_HPP_

#include "../../Combination.hpp"

class Flush : public Combination {
    public:
        Flush();
        Flush(CardList<Card>);
        Flush(const Flush&);
        ~Flush();

        void computeScore();
};

#endif