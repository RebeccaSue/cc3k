#ifndef CELL_H
#define CELL_H
#include <iostream>

#include "GameObject.h"
class GameObject;

class Cell {
	int x; // ACROSS the row (x-coordinate)
	int y; // DOWN the column (y-coordinate)
	char symbol; // CELLS STORE DISPLAYED SYMBOL, since Floor representation of board is a 2d-vector of CELLS
	bool occupied; // is there a GameObject occupying the cell?
	GameObject* gameObject; // if occupied, a GameObject occupies the Cell, shared_ptr: getGameObject?
	// note: GameObject stores the symbol

public:
	Cell(int x, int y, char symbol);
	int getX();
	int getY();
	char getSymbol();
	bool getIsOccupied();
	void setGameObject(GameObject *occupier); // places a GameObject at current Cell
	GameObject* getGameObject();


	bool invalidPlayerMove();
};

#endif
