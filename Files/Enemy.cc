#include "Enemy.h"

using namespace std;

Enemy::Enemy(int HP, int Atk, int Def, char symbol, string race): Character(HP, Atk, Def, symbol, race) {
	hostile = true;
}

Enemy::~Enemy() {}

void Enemy::dropGold() {
	//TODO Does nothing for now. For compilation...
}

// Human: 140 HP, 20 Atk, 20 Def, drops 2 normal piles of gold
Human::Human() : Enemy(140, 20, 20, 'H', "Human") {}
Human::~Human() {}

// Dwarf: 100 HP, 20 Atk, 30 Def, Vampire -5 HP upon attacking instead of gaining +5 HP
Dwarf::Dwarf() : Enemy(100, 20, 30, 'W', "Drawf") {}
Dwarf::~Dwarf() {}

// Elf: 140 HP, 30 Atk, 10 Def, attack PC twice except Drow
Elf::Elf() : Enemy(140, 30, 10, 'E', "Elf") {} 
Elf::~Elf() {}

// Orc: 180 HP, 30 Atk, 25 Def, 50% more damage to Goblin
Orc::Orc() : Enemy(180, 30, 25, 'O', "Orc") {}
Orc::~Orc() {}

// Merchant: 30 HP, 70 Atk, 5 Def, defaultly not hostile 
Merchant::Merchant() : Enemy(30, 70, 5, 'M', "Merchant") {}
Merchant::~Merchant() {}

// Halfing: 100 HP, 15 Atk, 20 Def, causes 50% chance to miss when PC attacks
Halfling::Halfling() : Enemy(100, 15, 20, 'L', "Halfling") {}
Halfling::~Halfling() {}

// Dragon: 150 HP, 20 Atk, 20 Def, stationary, spawn when dragon hoard is spawned
Dragon::Dragon() : Enemy(150, 20, 20, 'D', "Dragon") {}
Dragon::~Dragon() {}
