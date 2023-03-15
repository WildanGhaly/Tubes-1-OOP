#ifndef _STRAIGHT_FLUSH_HPP_
#define _STRAIGHT_FLUSH_HPP_

// #include "../../Combination.cpp"

class StraightFlush : public Combination {
    public:
        StraightFlush();
        StraightFlush(CardList<Card>);
        StraightFlush(const StraightFlush&);
        ~StraightFlush();

        void computeScore();
};

#endif