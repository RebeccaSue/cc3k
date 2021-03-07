#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <cstdlib>

// class GameObject; // need Cell to be defined before GameObject can be defined
#include "GameObject.h"

class Character : public GameObject {
	// char objectSymbol and Cell *position defined in GameObject
protected:
	int HP;
	int Atk;
	int Def;
	std::string race;
public:
	Character(int HP, int Atk, int Def, char symbol, std::string race);
	virtual ~Character()=0; // class is abstract;

	// combat
	virtual void getAttackBy(Character& attacker); // No longer PV
	virtual void attackSomeone(Character& defender); //Pass reference to attackee
	int calcDamage(const Character& defender);
	void decreaseHP(int n); //decrease HP by arbitrary amount (down to 0).
	void increaseHP(int n); //increase HP by arbitrary amount upto initial HP except for vampire.

	// setters/getters
	int getHp() const;
	int getAtk() const;
	int getDef() const;
	std::string getRace() const;
	void setHp(int curHp);
	void setAtk(int curAtk);
	void setDef(int curDef);
	// objectSymbol interactions done in GameObject class and Cell class
};

#endif
