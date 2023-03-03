#ifndef __THREEOFKIND_HPP__
#define __THREEOFKIND_HPP__

#include "Rules.hpp"
#include "GenericRules.hpp"

class ThreeOfKind : public Rules{
    static int IDcounter;
    public:
        ThreeOfKind();
        ThreeOfKind(Table, PlayerVec);
        ThreeOfKind(const ThreeOfKind& hc);
        ~ThreeOfKind();

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
        bool isThreeOfKind(std::vector<Card>, int&, int&);
    
    private:
        int ID;
        std::string name;
};

#endif