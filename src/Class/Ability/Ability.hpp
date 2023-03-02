#ifndef _ABILITY_HPP
#define _ABILITY_HPP
#include <iostream>
#include <cstring>
#include "Reroll.hpp"
#include "Quadruple.hpp"
#include "Quarter.hpp"


class Ability : public Reroll, public Quadruple, public Quarter  {
    public:
        Ability(char*);
        Ability(const Ability&);
        
        char* getAbility() const;

        void setAbility(char*);
        

    private:
        char* Ability_name;


};

#endif