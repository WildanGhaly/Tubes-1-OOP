#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : Ability::Ability(4){

}

bool ReverseDirection::useAbility(Game<Card>& game, int playerAbility, int players){
    Player player;
    vector<Player> playerList;
    if (playerAbility == 4 || playerAbility == 0 || playerAbility == -4){
        if (playerAbility == 4){
            player = game.getPlayer(players);
            player.setAbility(-4);
            playerList = game.getPlayers();
            reverse(playerList.begin() + players + 1, playerList.end());
            game.setPlayers(playerList);
            game.setPlayer(players, player);
            Ability::setUsingAbility(true);
            return true;
        } else if(playerAbility ==-4){
            printPesan2("REVERSE DIRECTION");
        }else if(playerAbility == 0){
            printPesan3("REVERSE DIRECTION");
        }
    } else {
        printPesan("REVERSE DIRECTION");
    }
    return false;
}