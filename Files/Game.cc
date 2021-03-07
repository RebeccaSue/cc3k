

#include "Game.h"
#include "Shade.h"
#include "Drow.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Troll.h"

using namespace std;

Game::Game(string floorFile, string race): floorFile{floorFile}, race{race} { // initializes game: print floor and spawn PC
	initPlayer();
	theFloor = new Floor{floorFile, thePlayer}; // floor is initialized with file layout and Player ptr
}

Game::~Game() {
	delete theFloor;
	delete thePlayer;
}
void Game::print() {
	cerr << "reach HERE?" << endl;
	theFloor->printFloor();
	cout << "DONE PRINTING" << endl;
}

void Game::initPlayer() {
	if (race == "s") {
		thePlayer = new Shade();
	} 
	else if (race == "d") {
		thePlayer = new Drow();
	}
	else if (race == "v") {
		thePlayer = new Vampire();
	}
	else if (race == "t") {
		thePlayer = new Troll();
	}
	else {
		thePlayer = new Goblin();
	}
}

void Game::move(string direction) {
	int dx; // dx = change across x axis (going horizontally across row)
	int dy; // dy = change down y axis (going vertically down col)
	if (direction == "no") { // north
		dx = 0;
		dy = -1;
	} 
	else if (direction == "so") { // south
		dx = 0;
		dy = 1;
	}
	else if (direction == "ea") { // east
		dx = 1;
		dy = 0;
	}
	else if (direction == "we") { // west
		dx = -1;
		dy = 0;
	}
	else if (direction == "ne") { // north-east
		dx = 1;
		dy = -1;
	}
	else if (direction == "se") { // south-east
		dx = 1;
		dy = 1;
	}
	else if (direction == "sw") { // south-west
		dx = -1;
		dy = 1;
	}
	else { // north-west
		dx = -1;
		dy = -1;
	}
	theFloor->movePlayer(dx, dy);
}
