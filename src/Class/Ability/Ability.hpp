#ifndef _ABILITY_HPP
#define _ABILITY_HPP
#include <iostream>
#include <cstring>
#include <string>

#include "../Game/Game.hpp"

class Ability{
    public:
        Ability();
        Ability(int);
        Ability(const Ability&);
        bool isUsingAbility() const;
        void setUsingAbility(bool);
        // virtual void useAbility() = 0;
        virtual bool useAbility(Game<Card>&, int, int) = 0;
        void printPesan(std::string);
        void printPesan2(std::string);
        void printPesan3(std::string);

    protected:
        bool usingAbility;
        

};

#endif