#ifndef _THREE_OF_KIND_HPP_
#define _THREE_OF_KIND_HPP_

#include "../../Combination.hpp"

class ThreeOfKind : public Combination {
    public:
        ThreeOfKind();
        ThreeOfKind(CardList<Card>);
        ThreeOfKind(const ThreeOfKind&);
        ~ThreeOfKind();

        void computeScore();
};

#endif