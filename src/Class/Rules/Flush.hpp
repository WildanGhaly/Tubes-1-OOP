#ifndef __FLUSH_HPP__
#define __FLUSH_HPP__

#include "Rules.hpp"
#include "GenericRules.hpp"

/* Class Flush */
class Flush : public Rules{
    static int IDcounter;
    public:
        Flush();
        Flush(Table, PlayerVec);
        Flush(const Flush& hc);
        ~Flush();

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
        bool isFlush(std::vector<Card>, int&, int&);
        
    
    private:
        int ID;
        std::string name;
};
#endif