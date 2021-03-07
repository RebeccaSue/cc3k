#include <cmath>

#include "Character.h"

using namespace std;

Character::Character(int HP, int Atk, int Def, char symbol, string race): GameObject(symbol), HP(HP), Atk(Atk), Def(Def), race(race) {}

/* RECALL:
GameObject::GameObject(char objectSymbol): objectSymbol{objectSymbol} {
	position = nullptr;
}
*/

Character::~Character() {}

void Character::getAttackBy(Character& attacker) {
	// TODO (next line for temporary compilation purposes)
	cerr << "cCharacter::getAttackBy not yet implemented" << std::endl;

}

void Character::attackSomeone(Character& defender) {
	// TODO (next line for temporary compilation purposes)
	cerr << "Character::attackSomeone not yet implemented" << std::endl;
}

std::string Character::getRace() const {
	return race;
}

/*
// combat

void character::getAttackedBy(Character& attacker) {
}

void character::attackSomeone(Character& defender) {
}

int Character::calcDamage(const Character& defender) {
	int atk = this->getCurAtk();
	int def = defender.getCurDef();
	return ceil((100/(100+def))*atk);
}

void Character::decreaseHP(int n) {
	curHP = curHP - n;
	if (curHP < 0) {curHP = 0;}
}

void Character::increaseHP(int n) {
	curHP = curHP + n;
	if (charName != "vampire") {
		if (curHP > initialHP) {
			curHP = initialHP;
		}
	}
}
*/
