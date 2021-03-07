#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <string>

//class Character; // need Cell to be defined before Chararacter, GameObject can be defined
#include "Character.h"

class Player : public Character {
	// recall: GameObject(charSymbol, position), Character(HP, Atk, Def)
	const int maxHP;
	int curGold;
	std::string action;
	// might need: fields to track temporary stats (i.e. temporary potion de/buffs)

public:
	Player(int maxHP, int HP, int Atk, int Def, std::string race); // Player is initialized in Game.cc ctor
	virtual ~Player()=0;
	// TODO Auto-generated getters and setters
	int getCurGold() const;
	void setCurGold(int curGold);

	// might need:
	// usePotion
	// getAction()
	// setAction;
};

#endif
