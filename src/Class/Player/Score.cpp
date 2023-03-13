#include "Score.hpp"
using namespace std;

Score::Score(){
    this -> score = 0;
    this -> give_score = 64;
}

float Score::getScore() const {
    return this -> score;
}
void Score::setDefaultgs(){
    this -> give_score = 64;
}
void Score::setScore(float score){
    this -> score = score;
}

void Score::Double(){
    this -> give_score *= 2;
}
void Score::Half(){
    this -> give_score / 2;
}
