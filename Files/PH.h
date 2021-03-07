#ifndef PH_H
#define PH_H

#include "Potion.h"

class PH: public Potion{
	static bool isUsed;
public:
	PH();
	~PH();
	// TEMPORARY
	// void useBy(Player *pc) override;
};

#endif
