#include "GameVec.hpp"

int GameVec::totalGame = 0;

GameVec::GameVec() : ListPlayerVec(), Table(), CardDeckVec(){
    // this->players = ListPlayerVec();
    // this->deck = CardDeckVec();
    // this->table = Table();
}

GameVec::GameVec(int totalPlayer) : ListPlayerVec(totalPlayer), Table(), CardDeckVec(){
    // this->players = ListPlayerVec(totalPlayer);
    // this->deck = CardDeckVec();
    // this->table = Table();
}

GameVec::GameVec(const GameVec& g) /* :ListPlayerVec(.getPlayers()), Table(), CardDeckVec()*/  {
    // this->players = g.players;
    // this->deck = g.deck;
    // this->table = g.table;
}

GameVec::~GameVec() {
    // nothing to do
}

// gini??
// ListPlayerVec GameVec::getPlayers() const {
//     // return this->players;
//     tapi ini constructor 
//     return ListPlayerVec(this->players);
// } 
// bukann maksudnya jadi ini semua get diilangin aja kan ujung ujungnya pake method induk
// iya gasi?
// kayaknya iya dah
// owhhh iya sihh diapus aja nih semua berarti?



// gak ngerti


// CardDeckVec GameVec::getDeck() const {
//     return this->deck;
// }

// int GameVec::getTotalCard() const {
//     return this->deck.getTotalCard();
// }

// int GameVec::getTotalPlayer() const {
//     return this->players.getTotalPlayer();
// }

// int GameVec::getTotalGame() {
//     return totalGame;
// }

// int GameVec::getTotalTableCard() const {
//     return this->table.getTotalCard();
// }

// int GameVec::getID() const {
//     return this->ID;
// }

// Card GameVec::getCard(int index) const {
//     return this->deck.getCard(index);
// }

// PlayerVec GameVec::getPlayer(int index) const {
//     return this->players.getPlayer(index);
// }

// Table GameVec::getTable() const {
//     return this->table;
// }

// dar berarti atributnya parent ganti jadi protected??, biar bisa diakses di class anaknya
// ato pake getter setter aja?
// keknya getter setter aja dah
// void GameVec::setPlayers(ListPlayerVec players) {
//     this->players = players;
// }

// void GameVec::setDeck(CardDeckVec deck) {
//     this->deck = deck;
// }

// void GameVec::setTable(Table table) {
//     this->table = table;
// }

void GameVec::print() const {
    ListPlayerVec::print();
    CardDeckVec::print();
    std::cout << "\nTABLE CARD: \n" << std::endl;
    Table::print();

    
}

void GameVec::start() {
    CardDeckVec::shuffle();
    for (int i = 0; i < ListPlayerVec::getTotalPlayer(); i++) {
        ListPlayerVec::getPlayer(i).addCard(CardDeckVec::getCard(0));
        CardDeckVec::removeCard(0);
    }
}

void GameVec::start(int totalCard) {
    CardDeckVec::shuffle();
    ListPlayerVec::addCard(this->deck, totalCard);
}

void GameVec::start(int totalCard, int totalPlayer) {
    CardDeckVec::shuffle();
    for (int i = 0; i < totalPlayer; i++) {
        for (int j = 0; j < totalCard; j++) {
            ListPlayerVec::getPlayer(i).addCard(CardDeckVec::getCard(0));
            CardDeckVec::removeCard(0);
        }
    }
}

void GameVec::nextRound() {
    CardDeckVec::shuffle();
    Table::nextRound(this->deck);
}

// bool GameVec::operator==(const GameVec& g) const {
//     return this->players == g.players && this->deck == g.deck && this->table == g.table;
// }

// bool GameVec::operator!=(const GameVec& g) const {
//     return !(*this == g);
// }

// GameVec& GameVec::operator=(const GameVec& g) {
//     this->players = g.players;
//     this->deck = g.deck;
//     this->table = g.table;
//     return *this;
// }
