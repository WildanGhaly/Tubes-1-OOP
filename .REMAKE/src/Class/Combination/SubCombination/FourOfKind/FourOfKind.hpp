#ifndef _FOUR_OF_KIND_HPP_
#define _FOUR_OF_KIND_HPP_

// #include "../../Combination.cpp"

class FourOfKind : public Combination {
    public:
        FourOfKind();
        FourOfKind(CardList<Card>);
        FourOfKind(const FourOfKind&);
        ~FourOfKind();

        void computeScore();
};

#endif