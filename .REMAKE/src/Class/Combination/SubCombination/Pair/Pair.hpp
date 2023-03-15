#ifndef _PAIR_HPP_
#define _PAIR_HPP_

// #include "../../Combination.cpp"

class Pair : public Combination {
    public:
        Pair();
        Pair(CardList<Card>);
        Pair(const Pair&);
        ~Pair();

        void computeScore();
};

#endif