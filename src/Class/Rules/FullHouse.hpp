#ifndef _FULL_HOUSE_HPP_
#define _FULL_HOUSE_HPP_

#include "Rules.hpp"

class FullHouse : public Rules {
    public:
        /* ctor cctor dtor */
        FullHouse();
        FullHouse(const FullHouse&);
        ~FullHouse();

        /* Getter */
        int getID() const;
        std::string getName() const;
        
        /* Setter */
        void setID(int);
        void setName(std::string);

        /* Method */
        void addScore(float);
        void computeScore();
        bool isFullHouse(std::vector<Card>, int&, int&);

        /* Operator */
        bool operator==(const FullHouse&) const;
        bool operator!=(const FullHouse&) const;
        FullHouse& operator=(const FullHouse&);

    private:
        int ID;
        std::string name;
};

#endif