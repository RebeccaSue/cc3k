#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>

#include "Cell.h"
#include "Player.h"
#include "Chamber.h"
#include "Potion.h"

class Floor {
	std::string floorFile;
	std::vector<std::vector<Cell*>> board; // representation of Floor grid, unique_ptr?
	std::string race;
	Player* thePlayer; // tracks Player Character interactions unique_ptr??
	int stairsExceptionId; // since Player spawned here, stairs CANNOT
	std::vector<Chamber*> theChamber; // Chamber: {0,1,2,3,4}


	std::vector<Enemy*> theEnemies; // for movement
	

public:
	Floor(std::string floorFile, Player *thePlayer);
	~Floor();
	void setFloorFromFile(); // sends textfile to board (representation of Floor grid), inits the cells
	void printFloor(); // prints the cells from board
	void generateChambers(); // initializes the 5 Chambers
	void spawn(); // spawn object order: Player, Stair, Potion, Gold, Enemy
	void generatePlayer(); // takes Player object and randomly sets it on board
	void generateStair(); // spawns a Stair object and randomly sets it on board
	void generatePotions(); // spawns 10 Potion objects and randomly sets it on board
	void generateGold(); // spawns 10 Gold objects and randomly sets it on board
	void generateEnemies(); // randomly spawns 20 Enemy objects and randomly sets it on board
	char getSymbolAt(int x, int y); // returns symbol at (x,y) coordinate on board

	std::string movePlayer(int dx, int dy);
	void nextTurn();
};

#endif
