#ifndef __STRAIGHT_HPP__
#define __STRAIGHT_HPP__

#include "Rules.hpp"

/* Class Straight */
class Straight : public Rules{
    static int IDcounter;
    public:
        Straight();
        Straight(Table, PlayerVec);
        Straight(const Straight& hc);
        ~Straight();

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
        bool isStraight(std::vector<Card>, int&);
    
    private:
        int ID;
        std::string name;
};

#endif