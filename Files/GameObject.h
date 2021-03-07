#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Cell.h"
class Cell; // need Floor to be defined, before Cell can be defined

class GameObject {
protected: // gives subclasses access to fields
	const char objectSymbol; // symbol displayed on Floor's Cell
	Cell* position; // where GameObject is located, shared_ptr?

public:
	GameObject(const char objectSymbol);
	virtual ~GameObject()=0;

	virtual void setPosition(Cell *pos);
	virtual Cell* getPosition();
	virtual char getObjectSymbol();
};

#endif
