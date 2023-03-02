#include "GameVec.hpp"

int GameVec::totalGame = 0;

GameVec::GameVec() : ID(totalGame++) {
    this->players = ListPlayerVec();
    this->deck = CardDeckVec();
    this->table = Table();
}

GameVec::GameVec(int totalPlayer) : ID(totalGame++) {
    this->players = ListPlayerVec(totalPlayer);
    this->deck = CardDeckVec();
    this->table = Table();
}

GameVec::GameVec(const GameVec& g) {
    this->players = g.players;
    this->deck = g.deck;
    this->table = g.table;
}

GameVec::~GameVec() {
    // nothing to do
}

ListPlayerVec GameVec::getPlayers() const {
    return this->players;
}

CardDeckVec GameVec::getDeck() const {
    return this->deck;
}

int GameVec::getTotalCard() const {
    return this->deck.getTotalCard();
}

int GameVec::getID() const {
    return this->ID;
}

Card GameVec::getCard(int index) const {
    return this->deck.getCard(index);
}

PlayerVec GameVec::getPlayer(int index) const {
    return this->players.getPlayer(index);
}

Table GameVec::getTable() const {
    return this->table;
}

void GameVec::setPlayers(ListPlayerVec players) {
    this->players = players;
}

void GameVec::setDeck(CardDeckVec deck) {
    this->deck = deck;
}

void GameVec::setTable(Table table) {
    this->table = table;
}

void GameVec::print() const {
    this->players.print();
    this->deck.print();
    std::cout << "\nTABLE CARD: \n" << std::endl;
    this->table.print();
}

void GameVec::start() {
    this->deck.shuffle();
    for (int i = 0; i < this->players.getTotalPlayer(); i++) {
        this->players.getPlayer(i).addCard(this->deck.getCard(0));
        this->deck.removeCard(0);
    }
}

void GameVec::start(int totalCard) {
    this->deck.shuffle();
    this->players.addCard(this->deck, totalCard);
}

void GameVec::start(int totalCard, int totalPlayer) {
    this->deck.shuffle();
    for (int i = 0; i < totalPlayer; i++) {
        for (int j = 0; j < totalCard; j++) {
            this->players.getPlayer(i).addCard(this->deck.getCard(0));
            this->deck.removeCard(0);
        }
    }
}

void GameVec::nextRound() {
    this->deck.shuffle();
    table.nextRound(this->deck);
}

bool GameVec::operator==(const GameVec& g) const {
    return this->players == g.players && this->deck == g.deck && this->table == g.table;
}

bool GameVec::operator!=(const GameVec& g) const {
    return !(*this == g);
}

GameVec& GameVec::operator=(const GameVec& g) {
    this->players = g.players;
    this->deck = g.deck;
    this->table = g.table;
    return *this;
}
