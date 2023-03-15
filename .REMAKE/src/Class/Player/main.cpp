#include "PlayerList.cpp"

int main(){
    PlayerList playerList = PlayerList("POKER");

    playerList.addPlayer(Player("A"));
    playerList.addPlayer(Player("B"));
    playerList.addPlayer(Player("C"));
    playerList.addPlayer(Player("D"));
    playerList.addPlayer(Player("E"));
    playerList.addPlayer(Player("F"));
    playerList.addPlayer(Player("G"));

    Card card1 = Card(1, 1);
    Card card2 = Card(2, 2);
    Card card3 = Card(3, 3);
    Card card4 = Card(0, 4);
    Card card5 = Card(1, 5);

    playerList[0] << card1;
    playerList[0] << card2;

    playerList[1] << card3;
    playerList[1] << card4;

    playerList[2] << card5;
    playerList[2] << card1;

    playerList[3] << card2;
    playerList[3] << card3;

    playerList[4] << card4;
    playerList[4] << card5;

    playerList[5] << card1;
    playerList[5] << card2;

    playerList[6] << card3;
    playerList[6] << card4;

    playerList.print();

    return 0;
}