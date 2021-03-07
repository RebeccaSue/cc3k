#ifndef BA_H
#define BA_H

#include "Potion.h"

class BA: public Potion{
	static bool isUsed;
public:
	BA();
	~BA();
	// TEMPORARY
//	void useBy(Player *pc) override;
};

#endif
