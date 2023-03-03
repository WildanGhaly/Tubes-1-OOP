#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include "Rules.hpp"

class Pair : public Rules{
    static int IDcounter;
    public:
        Pair();
        Pair(Table, PlayerVec);
        Pair(const Pair& hc);
        ~Pair();

        /* Getter */
        int getID() const;
        float getScore() const;
        std::string getName() const;

        /* Setter */
        void setID(int);
        void setScore(float);
        
        /* Method */
        void addScore(float);
        void computeScore();
        bool isPairs(std::vector<Card>, int&);
    
    private:
        int ID;
        std::string name;
};

#endif