#include <iostream>

#include "Chamber.h"
#include "Floor.h"

using namespace std;

Chamber::Chamber(int chamberId, Floor* theFloor): chamberId{chamberId}, theFloor{theFloor} {
	switch(chamberId) {
		case 0:	//Top left chamber
            topRow = 3;
            leftCol = 3;
            rowSpan = 26;
            colSpan = 4;
            break;
        case 1:	//Top right chamber
        	topRow = 3;
            leftCol = 39;
            rowSpan = 37;
            colSpan = 10;
            break;
        case 2: //Middle chamber
            topRow = 10;
            leftCol = 38;
            rowSpan = 12;
            colSpan = 3;
            break;
        case 3:	// Bottom left chamber
            topRow = 15;
            leftCol = 4;
            rowSpan = 21;
            colSpan = 7;
            break;
        case 4:	//Bottom right chamber
            topRow = 16;
            leftCol = 37;
            rowSpan = 39;
            colSpan = 6;
            break;
	}
}

Chamber::~Chamber() {}

int Chamber::getChamberId() {
    return chamberId;
}

int Chamber::getTopRow() {
    return topRow;
}

int Chamber::getLeftCol(){
    return leftCol;
}

int Chamber::getRowSpan() {
    return rowSpan;
}

int Chamber::getColSpan(){
    return colSpan;
}

bool Chamber::isValid(int x, int y) {
	char symbol = theFloor->getSymbolAt(x,y); 
	if(symbol == '.'){
		return true;
	}
	return false;
}

vector<int> Chamber::generatePosition() {
	int x = rand() % rowSpan + leftCol; 
	int y = rand() % colSpan + topRow;
	if (chamberId == 1) { // special handling: potential for spawning outsude of chamber 1
		while (x>=39 && x<=49 && y>=10 && y<=12 || !(isValid(x,y))) { // coordinate is NOT in chamber 2 (middle) or ISNT valid
			x = (rand() % rowSpan) + leftCol; // x = (# % 37) + 39, i.e. 39 <= x <= 75
			y = (rand() % colSpan) + topRow; // y = (# % 10) + 3, i.e. 3 <= y <= 12
		}
 	}
	else { // ensure position we spawn on is '.' Cell
		while (!(isValid(x,y))) {
			x = rand() % rowSpan + leftCol;
        	y = rand() % colSpan + topRow;
		}
	}
	vector<int> pos;
	pos.emplace_back(x);
	pos.emplace_back(y);
	return pos;
}
