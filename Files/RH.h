#ifndef RH_H
#define RH_H

#include "Potion.h"

class RH: public Potion{
	static bool isUsed;
public:
	RH();
	~RH();
	// TEMPORARY
	// void useBy(Player *pc) override;
};

#endif
