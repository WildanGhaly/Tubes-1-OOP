#include "Reroll.hpp"
using namespace std;

Reroll::Reroll() {
    for (int i = 0; i < 2; i++) {
        PlayerVec::removeCard(i);
    }
    for (int i = 0; i < 2; i++){
        PlayerVec::addCard(GameVec::getDeck().getCard(i));
        GameVec::getDeck().removeCard(0);
    }
    

}