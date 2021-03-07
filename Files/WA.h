#ifndef WA_H
#define WA_H

#include "Potion.h"

class WA: public Potion{
	static bool isUsed;
public:
	WA();
	~WA();
	// TEMPORARY
	// void useBy(Player *pc) override;
};

#endif
