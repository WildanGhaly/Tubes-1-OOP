#ifndef _ABILITY_HPP
#define _ABILITY_HPP
#include <iostream>
#include <cstring>



class Ability {
    public:
        Ability(int);
        int getAbility() const;
        void setAbility(int);
        bool isUsingAbility() const;
        void setUsingAbility(bool);
        virtual void useAbility() = 0;

    private:
        int ability_id;
        bool usingAbility;

};

#endif