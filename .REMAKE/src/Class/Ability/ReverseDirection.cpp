#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : Ability::Ability(4){

}

bool ReverseDirection::useAbility(Game<Card>& game, int playerAbility, int players){
    Player player;
    vector<Player> playerList;
    if (playerAbility == 4){
        cout << "masuk" << endl;
        if (ReverseDirection::isUsingAbility() == false){
            player = game.getPlayer(players);
            player.setAbility(-1);
            playerList = game.getPlayers();
            cout << "masuk" << endl;
            reverse(playerList.begin() + players + 1, playerList.end());
            cout << "masuk" << endl;
            game.setPlayers(playerList);
            cout << "masuk" << endl;
            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan2("REVERSE DIRECTION");
            return false;
        }
    } else {
        printPesan("REVERSE DIRECTION");
        return false;
    }
}