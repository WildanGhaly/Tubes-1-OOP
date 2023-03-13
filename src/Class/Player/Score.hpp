#ifndef _SCORE_HPP
#define _SCORE_HPP

#include <iostream>

class Score {
    public :
        Score();
        float getScore() const;
        void setScore(float);
        void setDefaultgs();
        void Double();
        void Half();
    
    private :
        float score;
        float give_score;
};


#endif