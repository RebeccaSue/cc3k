#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y, char symbol): x{x}, y{y}, symbol{symbol} {
	occupied = false;
	gameObject = nullptr;
}

int Cell::getX() {
	return x;
}

int Cell::getY() {
	return y;
}

char Cell::getSymbol() { // used for printing Floor from file
	return this->symbol;
}

bool Cell::getIsOccupied() {
	return this->occupied;
}

void Cell::setGameObject(GameObject *occupier) {
	// symbol = gameObject->getObjectSymbol(); 
	// when a GameObject is occupies current Cell, the previous Cell symbol (floor) '.' --> GameObject symbol '@, P, etc.'
	occupied = true;
	gameObject = occupier; // Cell has a GameObject ptr
	gameObject->setPosition(this); // GameObject has a Cell position
}

GameObject* Cell::getGameObject() {
	return this->gameObject;
}





bool Cell::invalidPlayerMove() {
	if(occupied && gameObject->getObjectSymbol() == 'G') { // special case
		return true;
	}
	if(symbol == ' ' || symbol == '-' || symbol == '|' || occupied) {
		// move destination cell CANNOT be whitespace, wall, or occupied by another Object
		// NOTE: NEED TO ENSURE THAT GOLD OBJECT ON A CELL SETS OCCUPIED TO FALSE
		return false;
	} 
	else {
		return true;
	}
}
