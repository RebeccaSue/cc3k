#ifndef GOBLIN_H
#define GOBLIN_H

#include "Player.h"

class Goblin: public Player { // gains 5 Gold for every Enemy slain, Orcs deal 50% more damage to Goblin
public:
	Goblin();
	~Goblin();
};

#endif
