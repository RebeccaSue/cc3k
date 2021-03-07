#include <fstream>
#include <utility>
#include "Floor.h"
#include "Chamber.h"
#include "Stair.h" // Forward Declaration?
#include "PotionFactory.h" // Forward Declaration?
#include "Gold.h" // Forward Declaration?
#include "EnemyFactory.h"
using namespace std;
const int FLOOR_ROWS = 25;
const int FLOOR_COLS = 79;

Floor::Floor(string floorFile, Player *thePlayer): floorFile{floorFile}, thePlayer{thePlayer} {
	setFloorFromFile();
	generateChambers();
	spawn();
}
Floor::~Floor() {}


void Floor::spawn() {
	
	generatePlayer();
	/*
	generateStair();
	generatePotions();
	generateGold();
	generateEnemies();
	*/
}


void Floor::setFloorFromFile() {
	ifstream file{floorFile};
	string s = "";
	int rowNum = 0;
	while (getline(file, s)) {
		// line <=> row, so we are essentially buildling a vector of cells row by row
		vector <Cell *> row; // a row is a vector of Cell ptrs
        int len = s.length();
        for (int i = 0; i < len; ++i) {
        	char symbol = s[i];
            row.emplace_back(new Cell{rowNum, i, symbol}); // add new Cell to row
        }
        board.emplace_back(row); // add row to board
        cerr << "COUNTING ROW INCREMENTS: " << rowNum << endl;
        rowNum++; // move onto next row
	}
}

void Floor::printFloor() {
	for (int i=0; i<FLOOR_ROWS; ++i) {
		for (int j=0; j<FLOOR_COLS; ++j) {
			cout << board[i][j]->getSymbol(); // fetches the character on txtfile
		}
		cout << endl; // next row
	}

}


void Floor::generateChambers() {
	for (int id=0; id<5; ++id) {
		Chamber *c = new Chamber{id, this};
		theChamber.emplace_back(c);
	}
}

void Floor::generatePlayer() { // need to ensure EQUAL chance in all chambers
	int chamberId = rand() % 5 ; // generates random # from {0, 1, 2, 3, 4} : {top-left, top-right, centre, bottom-left, bottom-right}	
	cerr << "RANDOM CHAMBERID IS: " << chamberId << endl;
	vector<int> pos = theChamber[chamberId]->generatePosition();
	cerr << "RANDOM POSITION IS: " << pos[0] << "," << pos[1] << endl;
	stairsExceptionId = chamberId;
	Cell* cellSpawn = board[pos[0]][pos[1]];
	cerr << "PLAYER SYMBOL: " << thePlayer->getObjectSymbol() << " is about to spawn..." << endl;
	cellSpawn->setGameObject(thePlayer); // sets thePlayer object as a GameObject at generated position Cell
	// calls: Cell->setGameObject(GameObject), now board[pos[0], pos[1]] should have a Player object
	// thePlayer->setPosition(board[pos[0]][pos[1]]); // done in setGameObject()
	cerr << "PLAYER RACE: " << thePlayer->getRace() << " HAS SPAWNED!" << endl;
}

void Floor::generateStair() {
	int chamberId = rand() % 5;
	if (chamberId == stairsExceptionId) {
		generateStair();
	} else { // NOT the same chamberId as Player object
		vector<int> pos = theChamber[chamberId]->generatePosition();
		Stair *stairs = new Stair();
		board[pos[0]][pos[1]]->setGameObject(stairs);
	}
}

void Floor::generatePotions() { // note: generatePosition() guarantees '.' Cell spawn point
	for (int i=0; i<10; ++i) { // 10 potions
		int chamberId = rand() % 5;
		vector<int> pos = theChamber[chamberId]->generatePosition();
		
		int potId = rand() % 6; // 6 types of Potions
		Potion *p = PotionFactory(potId);
		/*
		if (potId == 0) { 
			p = new RH(); //RESTORE HEALTH
		}
		else if (potId == 1) {
			p = new BA(); //BOOST ATTACK
		}
		else if (potId == 2) {
			p = new BD(); //BOOST DEFENCE
		}
		else if (potId == 3) {
			p = new PH(); //POISON HEALTH
		}
		else if (potId == 4) {
			p = new WA(); //WOUND ATTACK
		}
		else if (potId == 5) {
			p = new WD(); //WOUND DEFENCE
		}
		*/
		board[pos[0]][pos[1]]->setGameObject(p);
	}
}
 
void Floor::generateGold() {
	for (int i=0; i<10; ++i) { // 10 Gold
		int chamberId = rand() % 5;
		vector<int> pos = theChamber[chamberId]->generatePosition();
		int goldId = rand() % 8;
		Gold *g = nullptr;
		if (goldId == 0) { // need to spawn Dragon
			g = new dragonHoard();
			//SPAWN THE DRAGON
		} 
		else if (goldId == 1 || goldId == 2) {
			g = new smallHoard();
		}
		else {
			g = new normalHoard();
		}
		board[pos[0]][pos[1]]->setGameObject(g);
	} 
}

void Floor::generateEnemies() {
	for(int i=0; i<20; ++i) { // 20 Enemy
		int chamberId = rand() % 5;
		vector<int> pos = theChamber[chamberId]->generatePosition();
		int enemyId = rand() % 18;
		Enemy *e = EnemyFactory(enemyId);
		/*
		if (enemyId <= 3) { // 4/18
			e = new Human();
		}
		else if (enemyId <= 6) { // 3/18
			e = new Drawf();
		}
		else if (enemyId <= 11) { // 5/18
			e = new Halfling();
		}
		else if (enemeyId <= 13) { // 2/18
			e = new Elf();
		}
		else if (enemyId <= 15) { // 2/18
			e = new Orc();
		} else { // 2/18
			e = new Merchant();
		}
		*/
		board[pos[0]][pos[1]]->setGameObject(e);
		theEnemies.emplace_back(e);
	}
}

char Floor::getSymbolAt(int x, int y) {
	return board[x][y]->getSymbol();
}


///////////////// MOVEMENT
string Floor::movePlayer(int dx, int dy) {
	Cell* current = thePlayer->getPosition();
	int new_x = thePlayer->getPosition()->getX() + dx;
	int new_y = thePlayer->getPosition()->getY() + dy;
	Cell* newPos = board[new_x][new_y];

	if (newPos->invalidPlayerMove()) {
		return "Cannot move to target cell.";
	} 
	// check for Gold, valid Move
	else if (newPos->getSymbol() == 'G') {
		current->setObject(nullptr); // leave current Cell
		thePlayer->setPosition(newPos); // go to new Cell
		newPos->setGameObject(thePlayer);

		// check for Dragon, can we pick gold?
		return "Implement Item Class to use Items";
	}
	// no Gold, just move
	else {
		current->setObject(nullptr); // leave current Cell
		thePlayer->setPosition(newPos); // go to new Cell
		newPos->setGameObject(thePlayer);
		return "Succesful move!"
	}
}

Cell* Floor::randomMove() {
	int dx = rand() % 3 - 1;
	int dy = rand() % 3 - 1;
	int new_x = e->getPosition()->getX() + dx;
	int new_y = e->getPosition()->getY() + dy;
	Cell* newPos = board[new_x][new_y];
	return newPos;
}

void Floor::nextTurn() { // ENEMIES RANDOMLY MOVE
	for (auto &e : theEnemies) {
		Cell* current = e->getPosition();
		Cell* newPos = randomMove();
		while (newPos->getSymbol() != '.' || newPos->getIsOccupied()) {
			// require new Cell be '.' and NOT occupied
			newPos = randomMove();
		}
		current->setObject(nullptr); // leave current Cell
		e->setPosition(newPos); // go to new Cell
		newPos->setGameObject(e);
	}
}
