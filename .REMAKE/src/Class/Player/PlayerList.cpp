#include "PlayerList.hpp"

PlayerList::PlayerList() {
    this->players = vector<Player>();
}

PlayerList::PlayerList(int totalPlayer) {
    this->players = vector<Player>(totalPlayer);
}

PlayerList::PlayerList(string name) {
    this->players = vector<Player>(1, Player(name));
}

PlayerList::PlayerList(const PlayerList& playerList) {
    this->players = playerList.players;
}

PlayerList::~PlayerList() {
    // Nothing to do
}

int PlayerList::getTotalPlayer() const {
    return this->players.size();
}

Player PlayerList::getPlayer(int index) const {
    return this->players[index];
}

vector<Player> PlayerList::getPlayers() const {
    return this->players;
}

PlayerList PlayerList::getPlayerss() const {
    return *this;
}

void PlayerList::setPlayers(vector<Player> players) {
    this->players = players;
}

void PlayerList::setPlayer(int index, Player player) {
    this->players[index] = player;
}

void PlayerList::addPlayer(Player player) {
    this->players.push_back(player);
}

void PlayerList::removePlayer(Player player) {
    for (int i = 0; i < this->players.size(); i++) {
        if (this->players[i] == player) {
            this->players.erase(this->players.begin() + i);
            break;
        }
    }
}

void PlayerList::removePlayer(int index) {
    this->players.erase(this->players.begin() + index);
}

void PlayerList::sortByScore() {
    for (int i = 0; i < this->players.size(); i++) {
        for (int j = i + 1; j < this->players.size(); j++) {
            if (this->players[i].getValue() > this->players[j].getValue()) {
                Player temp = this->players[i];
                this->players[i] = this->players[j];
                this->players[j] = temp;
            }
        }
    }
}

void PlayerList::sortByScoreDesc() {
    for (int i = 0; i < this->players.size(); i++) {
        for (int j = i + 1; j < this->players.size(); j++) {
            if (this->players[i].getValue() < this->players[j].getValue()) {
                Player temp = this->players[i];
                this->players[i] = this->players[j];
                this->players[j] = temp;
            }
        }
    }
}

void PlayerList::print() const {
    for (int i = 0; i < this->players.size(); i++) {
        cout << this->players[i].getName() << " " << this->players[i].getValue() << endl;
        cout << "   Cards:\n";
        this->players[i].getHand().print();
    }
}

bool PlayerList::operator==(const PlayerList& playerList) const {
    return this->players == playerList.players;
}

bool PlayerList::operator!=(const PlayerList& playerList) const {
    return this->players != playerList.players;
}

Player& PlayerList::operator[](int index) {
    return this->players[index];
}

PlayerList& PlayerList::operator=(const PlayerList& playerList) {
    this->players = playerList.players;
    return *this;
}

PlayerList& PlayerList::operator<<(const Player& player) {
    this->players.push_back(player);
    return *this;
}

PlayerList& PlayerList::operator>>(Player& player) {
    for (int i = 0; i < this->players.size(); i++) {
        if (this->players[i] == player) {
            this->players.erase(this->players.begin() + i);
            break;
        }
    }
    return *this;
}



