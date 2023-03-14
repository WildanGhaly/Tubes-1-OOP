// #include "../Card/CardList.cpp"
#include "../Valueable/Valueable.hpp"
#include "../Player/PlayerList.cpp"
#include "../Table/Table.cpp"
#include "Game.cpp"

int main(){
    Game<Card> game(7, "POKER");
    cout << "MASUK\n";
    game.start(2);

    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();

    game.print();

    return 0;
}