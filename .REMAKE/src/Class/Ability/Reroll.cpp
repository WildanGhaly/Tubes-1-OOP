#include "Reroll.hpp"
using namespace std;

Reroll::Reroll() : Ability::Ability(1) {

}

bool Reroll::useAbility(Game<Card>& game, int playerAbility, int players){
    Player player;
    if (playerAbility == 1 || playerAbility == 0 || playerAbility == -1){
        if (playerAbility == 1){
            player = game.getPlayer(players);
            for (int i = 0; i < 2; i++){
                player.removeHand(0);
            }
            for (int i = 0; i < 2; i++){
                player.addHand(game.getDeck().getCard(0));
                game.removeDeckFirst();
            }
            player.setAbility(-1);
            game.setPlayer(players,player);
            Ability::setUsingAbility(true);
            return true;
        } else if(playerAbility ==-1){
            printPesan2("RE-ROLL");
        }else if(playerAbility == 0){
            printPesan3("RE-ROLL");
        }
    } else {
        printPesan("RE-ROLL");
    }
    return false;
}