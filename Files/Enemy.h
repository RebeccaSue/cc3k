#ifndef ENEMY_H
#define ENEMY_H


#include "Character.h"
#include <string>

class DragonHoard;

class Enemy: public Character {
private:
	bool hostile;
public: 
	Enemy(int HP, int Atk, int Def, char symbol, std::string type); 
	virtual ~Enemy() = 0;
	bool isHostile();
	virtual void dropGold();
};


// Human: 140 HP, 20 Atk, 20 Def, 2 golds * 2
class Human : public Enemy{
	public:
		Human();
		~Human();
		// TEMPORARY
		// void dropGold() override;
};

// Dwarf: 100 HP, 20 Atk, 30 Def, Vampire -5 HP upon attacking
class Dwarf : public Enemy{
	public:
		Dwarf();
		~Dwarf();
};

// Elf: 140 HP, 30 Atk, 10 Def, attack twice except Drow
class Elf : public Enemy{
	public:
		Elf();
		~Elf();

};

// Orc: 180 HP, 30 Atk, 25 Def, 50% more dmg to goblin
class Orc : public Enemy{
	public:
		Orc();
		~Orc();
};

// Merchant: 30 HP, 70 Ark, 5 Def, defaultly not hostile 
class Merchant : public Enemy{
	static bool hostile;
	public:
		Merchant();
		~Merchant();
		bool isHostile();
		// TEMPORARY
		// void dropGold() override;
};

// Halfing: 100 HP, 15 Ark, 20 Def, player have 50% chance to miss
class Halfling : public Enemy{
	public:
		Halfling();
		~Halfling();
};

// Dragon: 150 HP, 20 Atk, 20 Def, stationary, spawn when dragon hoard is spawned
class Dragon : public Enemy{
	private:
		DragonHoard* hoard;
	public:
		Dragon();
		Dragon(DragonHoard* hoard);
		~Dragon();
		DragonHoard* getHoard();
		void setHoard(DragonHoard* hd);
		// TEMPORARY
		// void dropGold();
};
#endif
