// Halo ges pakabar?
// Ini adalah main.cpp
#include <windows.h>
#include <cstring>
#include <time.h>
#include <math.h>
#include "Class/Game/Game.cpp"
#include "Function/MaxMinAvg.hpp"
#include "Class/Valueable/Valueable.hpp"
#include "Class/Player/PlayerList.cpp"
#include "Class/Player/Player.cpp"
#include "Class/Card/CardList.cpp"
#include "Class/Card/Card.cpp"
#include "Class/Table/Table.cpp"
#include "Class/Ability/Ability.cpp"
#include "Class/Ability/Quadruple.cpp"
// #include "Class/Ability/Quarter.cpp"
// #include "Class/Ability/Reroll.cpp"
// #include "Class/Ability/SwapCard.cpp"
// #include "Class/Ability/Switch.cpp"
// #include "Class/Ability/ReverseDirection.cpp"
// #include "Class/Ability/Abilityless.cpp"
#include "Class/Combination/Combination.cpp"
#include "Class/Combination/SubCombination/HighCard/HighCard.cpp"
#include "Class/Combination/SubCombination/Pair/Pair.cpp"
#include "Class/Combination/SubCombination/TwoPair/TwoPair.cpp"
#include "Class/Combination/SubCombination/ThreeOfKind/ThreeOfKind.cpp"
#include "Class/Combination/SubCombination/Straight/Straight.cpp"
#include "Class/Combination/SubCombination/Flush/Flush.cpp"
#include "Class/Combination/SubCombination/FullHouse/FullHouse.cpp"
#include "Class/Combination/SubCombination/FourOfKind/FourOfKind.cpp"
#include "Class/Combination/SubCombination/StraightFlush/StraightFlush.cpp"

#include <vector>
#include <iostream>
using namespace std;


int main(){
    Player tempPlayer;
    Game<Card> *game = new Game<Card>(4, "POKER");
    vector<int> abilityId;


    abilityId.push_back(1);
    abilityId.push_back(2);
    abilityId.push_back(3);
    abilityId.push_back(4);
    abilityId.push_back(5);
    abilityId.push_back(6);
    abilityId.push_back(7);

    game->start(2);

    game->nextRound();
    game->nextRound();

    game->print();

    tempPlayer = game->getPlayer(0);
    cout << "Ability: " << tempPlayer.ability << endl;
    game->setPlayer(0, tempPlayer);

    Quadruple quadruple;
    Ability *ability = &quadruple;
    ability->useAbilitys(*game, 2);

    game->print();





    return 0;
}