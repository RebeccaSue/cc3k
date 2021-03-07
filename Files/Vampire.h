#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Player.h"

class Vampire: public Player { // gains 5HP every attack, no limit on maxHP (-1)
	// LOSE 5HP upon attacking Drawf (instead of gain)
public:
	Vampire();
	~Vampire();
};

#endif
