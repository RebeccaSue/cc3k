#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "Enemy.h"

Enemy* EnemyFactory(int enemyId) {
	// I think "return new ..." always returns 1 upon successful heap allocation
	Enemy* aEnemy = nullptr;
	if (enemyId <= 3) { // 4/18
		aEnemy = new Human();
	}
	else if (enemyId <= 6) { // 3/18
		aEnemy = new Dwarf();
	}
	else if (enemyId <= 11) { // 5/18
		aEnemy = new Halfling();
	}
	else if (enemyId <= 13) { // 2/18
		aEnemy = new Elf();
	}
	else if (enemyId <= 15) { // 2/18
		aEnemy = new Orc();
	}
	else { // 2/18
		aEnemy = new Merchant();
	}
	return aEnemy;
}

// Old code

//Enemy* EnemyFactory(int enemyId) {
//	if (enemyId <= 3) { // 4/18
//		return new Human();
//	}
//	else if (enemyId <= 6) { // 3/18
//		return  new Drawf();
//	}
//	else if (enemyId <= 11) { // 5/18
//		return new Halfling();
//	}
//	else if (enemyId <= 13) { // 2/18
//		return new Elf();
//	}
//	else if (enemyId <= 15) { // 2/18
//		return new Orc();
//	} else { // 2/18
//		return new Merchant();
//	}
//}

#endif
