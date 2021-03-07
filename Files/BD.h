#ifndef BD_H
#define BD_H

#include "Potion.h"

class BD: public Potion{
	static bool isUsed;
public:
	BD();
	~BD();
	// TEMPORARY
//	void useBy(Player *pc) override;
};

#endif
