#ifndef _ABILITY_HPP
#define _ABILITY_HPP
#include <iostream>
#include <cstring>
#include <string>

class Ability {
    public:
        Ability();
        Ability(int);
        Ability(const Ability&);
        int getAbility() const;
        void setAbility(int);
        bool isUsingAbility() const;
        void setUsingAbility(bool);
        virtual void useAbility() = 0;
        void printPesan(std::string);
        void printPesan2(std::string);

    private:
        int ability_id;
        bool usingAbility;

};

#endif