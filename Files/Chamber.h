#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include <cstdlib>

class Floor;

class Chamber {
	int chamberId;
	int topRow; // topRow/leftCol tracks the upper-left corner position of chamber
	int leftCol;
	int rowSpan; // row/colSpan tracks the spanning distance of spawn points inside chamber
	int colSpan;
	Floor* theFloor;

public:
	Chamber(int chamberId, Floor* theFloor);
	~Chamber();
	int getChamberId();
	int getTopRow();
	int getLeftCol();
	int getRowSpan();
	int getColSpan();
	bool isValid(int x, int y); // checks of Cell symbol at (x,y) is a '.'
	std::vector<int> generatePosition(); // returns valid random coordinates
};

#endif
