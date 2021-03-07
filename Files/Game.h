#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "Floor.h"
#include "Player.h"

// Game: acts as command interpreter
// initializes Player and Floor
// reprints state of Game (Floor) every time a command is passed from main
class Game {
	std::string floorFile; 
	std::string race;
	Floor* theFloor; // unique_ptr?
	Player* thePlayer; // unique_ptr?
	std::string action;

public:
	Game(std::string floorFile, std::string race);
	~Game();
	void print();
	void initPlayer(); // initialzies thePlayer pointer to a Player of corresponding race
	
	// Player movement
	void move(std::string direction); // converts string direction to coordinates to Floor
	void usePotion();
	void attackEnemy();
	void freeze();
	void restart();
	void quit();
};

#endif
