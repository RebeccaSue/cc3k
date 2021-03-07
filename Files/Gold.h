#ifndef GOLD_H
#define GOLD_H
#include <string>

#include "Item.h"

class Gold: public Item {
	int value;
	std::string type;
	bool pickable;
public:
	Gold(int value, std::string type, bool pickable);
	virtual ~Gold()=0;
	// TEMPORARY
	// void useBy(Player *pc) override;
};

#endif

class smallHoard: public Gold {
public:
	smallHoard();
	~smallHoard();
};

class normalHoard: public Gold {
public:
	normalHoard();
	~normalHoard();
};

class merchantHoard: public Gold { // upon death of Merchant
public:
	merchantHoard();
	~merchantHoard();
};

class humanHoard: public Gold { // upon death of Human
public:
	humanHoard();
	~humanHoard();
};

class dragonHoard: public Gold {
public:
	dragonHoard();
	~dragonHoard();
};
