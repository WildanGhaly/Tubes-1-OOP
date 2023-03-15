#include "Quadruple.hpp"
using namespace std;


Quadruple::Quadruple() : Ability::Ability(2) {
    
}
void Quadruple::useAbility(){
    // Table<Card>::setReward(Table<Card>::getValue() * 4);
    // Ability::setUsingAbility(true);
}

void Quadruple::useAbilitys(Game<Card>& game, int playerAbility){
    if (playerAbility == 2){
        cout << "Ability berhasil digunakan" << endl;
        game.setReward(game.getValue() * 4);
        Ability::setUsingAbility(true);
    } else {
        cout << "Ability gagal digunakan" << endl;
    }
}
