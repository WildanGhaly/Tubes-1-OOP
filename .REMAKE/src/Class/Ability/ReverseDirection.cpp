#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : Ability::Ability(4){

}

bool ReverseDirection::useAbility(Game<Card>& game, int playerAbility, int players){
    Player player;
    vector<Player> playerList;
    if (playerAbility == 4 || playerAbility == 0 || playerAbility == -1){
        cout << "masuk" << endl;
        if (playerAbility == 4){
            player = game.getPlayer(players);
            player.setAbility(-1);
            playerList = game.getPlayers();
            cout << "masuk" << endl;
            reverse(playerList.begin() + players + 1, playerList.end());
            cout << "masuk" << endl;
            game.setPlayers(playerList);
            game.setPlayer(players, player);
            cout << "masuk" << endl;
            Ability::setUsingAbility(true);
            return true;
        } else if(playerAbility ==-1){
            printPesan2("REVERSE DIRECTION");
        }else if(playerAbility == 0){
            printPesan3("REVERSE DIRECTION");
        }
    } else {
        printPesan("REVERSE DIRECTION");
    }
    return false;
}