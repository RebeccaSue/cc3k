#ifndef POTION_H
#define POTION_H

#include <string>
#include "Item.h"

class Potion : public Item {
	std::string type;
public:
	Potion(std::string type);
	~Potion();
	// TEMPORARY
	//virtual void useBy(Player *pc)=0;
	std::string getType();
};

#endif
