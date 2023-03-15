#ifndef __HIGHCARD_HPP__
#define __HIGHCARD_HPP__

#include "Rules.hpp"
#include "GenericRules.hpp"
class HighCard : public Rules {
    static int IDcounter;
    public:
        HighCard();
        HighCard(Table, PlayerVec);
        HighCard(const HighCard& hc);
        ~HighCard();

        /* Getter */
        int getID() const;
        float getScore() const;
        std::string getName() const;
        const float getMin() const;

        /* Setter */
        void setID(int);
        void setScore(float);
        
        /* Method */
        void addScore(float);
        void computeScore();

        /* Operator */
        bool operator==(const HighCard&) const;
        bool operator!=(const HighCard&) const;
        HighCard& operator=(const HighCard&);
    
    private:
        const int min = 0; // unknown yet
        int ID;
        std::string name;
};

#endif