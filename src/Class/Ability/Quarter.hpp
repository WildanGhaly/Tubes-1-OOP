#ifndef _QUARTER_HPP
#define _QUARTER_HPP

#include <iostream>
#include "../Player/Score.hpp"

class Quarter : public Score  {
    public :
        Quarter();
        bool isQuarter() const;
        void setQuarter(bool);
    
    private :
        bool usingQuarter;
};


#endif