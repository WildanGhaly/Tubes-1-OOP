#ifndef __FOUROFKIND_HPP__
#define __FOUROFKIND_HPP__

#include "Rules.hpp"
#include "GenericRules.hpp"
class FourOfKind: public Rules{
    static int IDcounter;
    public:
        FourOfKind();
        FourOfKind(Table, PlayerVec);
        FourOfKind(const FourOfKind& hc);
        ~FourOfKind();

        /* Getter */
        int getID() const;
        float getScore() const;
        std::string getName() const;

        /* Setter */
        void setID(int);
        void setScore(float);
        
        /* Method */
        void computeScore();
        bool isFourOfKind(std::vector<Card>, int&, int&);
    private:
        int ID;
        std::string name;
};


#endif 