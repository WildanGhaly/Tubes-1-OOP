#include "Reroll.hpp"
using namespace std;

Reroll::Reroll() : Ability::Ability(1) {

}

bool Reroll::useAbility(Game<Card>& game, int playerAbility, int player){
    Player player;
    if (playerAbility == 1){
        if (Reroll::isUsingAbility() == false){
            player = game->getPlayer(player);
            for (int i = 0; i < 2; i++){
                player.removeCard(i);
            }
            for (int i = 0; i < 2; i++){
                player.addCard(game->Table<Card>::getDeck()[0]);
                game->Table<Card>::removeCard(0);
            }
            game->setPlayer(i,player);
            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan("RE-ROLL");
        }
    } else {
        printPesan2("RE-ROLL");
    }
    return false;
}