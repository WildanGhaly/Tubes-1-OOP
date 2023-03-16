#!/bin/bash

# Compile every class
g++ -c ./Class/Card/Card.cpp -o                                                 \
    ../bin/Card/Card.o
g++ -c ./Class/Card/CardList.cpp -o                                             \
    ../bin/Card/CardList.o          

g++ -c ./Class/Table/Table.cpp -o                                               \
    ../bin/Table/Table.o

g++ -c ./Class/Player/Player.cpp -o                                             \
    ../bin/Player/Player.o
g++ -c ./Class/Player/PlayerList.cpp -o                                         \
    ../bin/Player/PlayerList.o

g++ -c ./Class/Combination/Combination.cpp -o                                   \
    ../bin/Combination/Combination.o
g++ -c ./Class/Combination/SubCombination/HighCard/HighCard.cpp -o              \
    ../bin/Combination/HighCard.o
g++ -c ./Class/Combination/SubCombination/Pair/Pair.cpp -o                      \
    ../bin/Combination/Pair.o
g++ -c ./Class/Combination/SubCombination/TwoPair/TwoPair.cpp -o                \
    ../bin/Combination/TwoPair.o
g++ -c ./Class/Combination/SubCombination/ThreeOfKind/ThreeOfKind.cpp -o        \
    ../bin/Combination/ThreeOfKind.o
g++ -c ./Class/Combination/SubCombination/Straight/Straight.cpp -o              \
    ../bin/Combination/Straight.o
g++ -c ./Class/Combination/SubCombination/Flush/Flush.cpp -o                    \
    ../bin/Combination/Flush.o
g++ -c ./Class/Combination/SubCombination/FullHouse/FullHouse.cpp -o            \
    ../bin/Combination/FullHouse.o
g++ -c ./Class/Combination/SubCombination/FourOfKind/FourOfKind.cpp -o          \
    ../bin/Combination/FourOfKind.o
g++ -c ./Class/Combination/SubCombination/StraightFlush/StraightFlush.cpp -o    \
    ../bin/Combination/StraightFlush.o

g++ -c ./Class/Game/Game.cpp -o                                                 \
    ../bin/Game/Game.o

g++ -c ./Class/Ability/Ability.cpp -o                                           \
    ../bin/Ability/Ability.o
g++ -c ./Class/Ability/Abilityless.cpp -o                                       \
    ../bin/Ability/Abilityless.o
g++ -c ./Class/Ability/Quadruple.cpp -o                                         \
    ../bin/Ability/Quadruple.o
g++ -c ./Class/Ability/Quarter.cpp -o                                           \
    ../bin/Ability/Quarter.o
g++ -c ./Class/Ability/Reroll.cpp -o                                            \
    ../bin/Ability/Reroll.o
g++ -c ./Class/Ability/ReverseDirection.cpp -o                                  \
    ../bin/Ability/ReverseDirection.o
g++ -c ./Class/Ability/SwapCard.cpp -o                                          \
    ../bin/Ability/SwapCard.o
g++ -c ./Class/Ability/Switch.cpp -o                                            \
    ../bin/Ability/Switch.o

# Compile main with linker
g++ main.cpp                          \
    ../bin/Card/Card.o                      \
    ../bin/Card/CardList.o                  \
    ../bin/Player/Player.o                  \
    ../bin/Player/PlayerList.o              \
    ../bin/Table/Table.o                    \
    ../bin/Game/Game.o                      \
    ../bin/Ability/Ability.o                \
    ../bin/Ability/Abilityless.o            \
    ../bin/Ability/Quadruple.o              \
    ../bin/Ability/Quarter.o                \
    ../bin/Ability/Reroll.o                 \
    ../bin/Ability/ReverseDirection.o       \
    ../bin/Ability/SwapCard.o               \
    ../bin/Ability/Switch.o                 \
    ../bin/Combination/Combination.o        \
    ../bin/Combination/HighCard.o           \
    ../bin/Combination/Pair.o               \
    ../bin/Combination/TwoPair.o            \
    ../bin/Combination/ThreeOfKind.o        \
    ../bin/Combination/Straight.o           \
    ../bin/Combination/Flush.o              \
    ../bin/Combination/FullHouse.o          \
    ../bin/Combination/FourOfKind.o         \
    ../bin/Combination/StraightFlush.o      \
    -o main.o

# Run the program
./main.o