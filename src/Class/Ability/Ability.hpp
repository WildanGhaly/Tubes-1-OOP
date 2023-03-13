#ifndef _ABILITY_HPP
#define _ABILITY_HPP
#include <iostream>
#include <cstring>
#include "Reroll.hpp"
#include "Quadruple.hpp"
#include "Quarter.hpp"
#include "Switch.hpp"
#include "ReverseDirection.hpp"
#include "SwapCard.hpp"


class Ability : public Reroll, public Quadruple, public Quarter, public Switch, public ReverseDirection, public SwapCard  {
    public:
        Ability(char*);
        Ability(const Ability&);
        
        char* getAbility() const;

        void setAbility(char*);
        

    private:
        char* Ability_name;


};

#endif