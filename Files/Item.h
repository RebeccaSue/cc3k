#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "GameObject.h"

#include "Player.h" // Might need forward declaration instead. Might be a cycle.

class Item: public GameObject {
public:
	Item(char symbol);
	~Item();
	// TEMPORARY
	// virtual void useBy(Player *pc)=0;
};

#endif
