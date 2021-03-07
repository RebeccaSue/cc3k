
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream>
#include <ctime>
#include "Game.h"


using namespace std;
class Game;

int main(int argc, char* argv[]) {
	srand(time(NULL));

	// ask for input necessary to set up Game

	// setting floor board
	string floorFile = "floor.txt";
	if (argc > 1) {
		floorFile = argv[1]; // non-default filename gets loaded
	}

	// race prompt: setting race for Player Character
	string race;
	cout << "Select a race from the following or quit/EOF:" << endl;
	cout << "s (Shade), d (Drawf), v (Vampire), g (Goblin), t (Troll)" << endl;
	cin >> race;
	if (race == "q" || cin.eof()) { // program will terminate
		cout << "Exiting...goodbye!" << endl;
		return 1;
	}

	// starting Game
	Game *g = new Game{floorFile, race};
	g->print();
	delete g;
}

