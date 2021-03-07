#ifndef TROLL_H
#define TROLL_H

#include "Player.h"

class Troll: public Player { // gains 5HP every turn, has limit on maxHP
public:
	Troll();
	~Troll();
};

#endif
