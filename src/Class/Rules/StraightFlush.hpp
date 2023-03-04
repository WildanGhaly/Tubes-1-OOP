#ifndef __STRAIGHTFLUSH_HPP__
#define __STRAIGHTFLUSH_HPP__

#include "Rules.hpp"
#include "GenericRules.hpp"

/* Class StraightFlush */
class StraightFlush : public Rules {
    static int IDcounter;
    public:
        StraightFlush();
        StraightFlush(Table, PlayerVec);
        StraightFlush(const StraightFlush& hc);
        ~StraightFlush();

        /* Getter */
        int getID() const;
        int getScore() const;
        std::string getName() const;

        /* Setter */
        void setID(int);
        void setScore(float);
        
        /* Method */
        void addScore(float);
        void computeScore();
        bool isStraightFlush(std::vector<Card>, int&, int&);
    
    private:
        int ID;
        std::string name;
};

#endif