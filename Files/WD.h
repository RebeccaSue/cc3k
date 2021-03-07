#ifndef WD_H
#define WD_H

#include "Potion.h"

class WD: public Potion{
	static bool isUsed;
public:
	WD();
	~WD();
	// TEMPORARY
	// void useBy(Player *pc) override;
};

#endif
