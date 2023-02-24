#include "ListPlayer.hpp"

/* Default Constructor */
ListPlayer::ListPlayer() {
    this->totalPlayer = 0;
    this->players = new Player[0];
}

/* Constructor with total player */
ListPlayer::ListPlayer(int totalPlayer) {
    this->totalPlayer = totalPlayer;
    this->players = new Player[this->totalPlayer];
    for (int i = 0; i < this->totalPlayer; i++) {
        /* INI MASUKIN PLAYER */
    }
}

/* Copy Constructor */
ListPlayer::ListPlayer(const ListPlayer& lp) {
    this->totalPlayer = lp.totalPlayer;
    delete[] this->players;
    this->players = new Player[this->totalPlayer];
    for (int i = 0; i < this->totalPlayer; i++) {
        this->players[i] = lp.players[i];
    }
}

/* Destructor */
ListPlayer::~ListPlayer() {
    delete[] this->players;
}

/* Getter untuk total player */
int ListPlayer::getTotalPlayer() const {
    return this->totalPlayer;
}

/* Getter untuk firsLastPlayer */
int ListPlayer::getFirstLastPlayer() const {
    return this->firstLastPlayer;
}

/* Getter untuk isReverse */
bool ListPlayer::getIsReverse() const {
    return this->isReverse;
}

/* Getter untuk player */
Player ListPlayer::getPlayer(int index) const {
    return this->players[index];
}

/* Setter untuk isTotalPlayer */
void ListPlayer::setTotalPlayer(int totalPlayer) {
    this->totalPlayer = totalPlayer;
}

/* Setter untuk firstLastPlayer */
void ListPlayer::setFirstLastPlayer(int firstLastPlayer) {
    this->firstLastPlayer = firstLastPlayer;
}

/* Setter untuk player */
void ListPlayer::setPlayer(int index, Player p) {
    this->players[index] = p;
}

/* Setter untuk isReverse */
void ListPlayer::setIsReverse(bool isReverse) {
    this->isReverse = isReverse;
}

/* Add player to list */
void ListPlayer::addPlayer(Player p) {
    Player* temp = new Player[this->totalPlayer + 1];
    for (int i = 0; i < this->totalPlayer; i++) {
        temp[i] = this->players[i];
    }
    temp[this->totalPlayer] = p;
    delete[] this->players;
    this->players = temp;
    this->totalPlayer++;
}

/* Remove player from list */
void ListPlayer::removePlayer(Player p) {
    int index = -1;
    for (int i = 0; i < this->totalPlayer; i++) {
        if (this->players[i] == p) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Player* temp = new Player[this->totalPlayer - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->players[i];
        }
        for (int i = index + 1; i < this->totalPlayer; i++) {
            temp[i - 1] = this->players[i];
        }
        delete[] this->players;
        this->players = temp;
        this->totalPlayer--;
    }
}

/* Remove player from list */
void ListPlayer::removePlayer(int index) {
    if (index >= 0 && index < this->totalPlayer) {
        Player* temp = new Player[this->totalPlayer - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->players[i];
        }
        for (int i = index + 1; i < this->totalPlayer; i++) {
            temp[i - 1] = this->players[i];
        }
        delete[] this->players;
        this->players = temp;
        this->totalPlayer--;
    }
}

/* Sort by point */
void ListPlayer::sortByPoint() {
    for (int i = 0; i < this->totalPlayer - 1; i++) {
        for (int j = i + 1; j < this->totalPlayer; j++) {
            if (this->players[i].getPoint() < this->players[j].getPoint()) {
                Player temp = this->players[i];
                this->players[i] = this->players[j];
                this->players[j] = temp;
            }
        }
    }
}

/* Operator overloading */
bool ListPlayer::operator==(const ListPlayer& lp) const {
    if (this->totalPlayer != lp.totalPlayer) {
        return false;
    }
    for (int i = 0; i < this->totalPlayer; i++) {
        if (this->players[i] != lp.players[i]) {
            return false;
        }
    }
    return true;
}

bool ListPlayer::operator!=(const ListPlayer& lp) const {
    return !(*this == lp);
}