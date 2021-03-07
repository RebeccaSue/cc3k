#include "Player.h"

using namespace std;

Player::Player(int maxHP, int HP, int Atk, int Def, std::string race): Character(HP, Atk, Def, '@', race), maxHP(maxHP) {
	curGold = 0;
	action = "Player has spawned.";
}

/* RECALL:
Character::Character(int HP, int Atk, int Def, char objectSymbol): Object(objectSymbol), HP{HP}, Atk{Atk}, Def{Def} {
}

GameObject::GameObject(char objectSymbol): objectSymbol{objectSymbol} {
	position = nullptr;
}
*/

Player::~Player() {}

/*
// TODO Auto-generated getters and setters
int players::getCurGold() const {
	return curGold;
}
void players::setCurGold(int curGold) {
	this->curGold = curGold;
}
*/
