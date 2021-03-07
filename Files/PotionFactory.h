#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H

#include "Potion.h"

// Forward declarations

// class RH;
// class BA;
// class BD;
// class PH;
// class WA;
// class WD;

#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"

Potion* PotionFactory(int potId) {
	Potion* somePotion;
	if(potId == 0) { 
		somePotion = new RH(); //RESTORE HEALTH
	}
	else if(potId == 1) {
		somePotion = new BA(); //BOOST ATTACK
	}
	else if (potId == 2) {
		somePotion = new BD(); //BOOST DEFENCE
	}
	else if (potId == 3) {
		somePotion = new PH(); //POISON HEALTH
	}
	else if (potId == 4) {
		somePotion = new WA(); //WOUND ATTACK
	}
	else if (potId == 5) {
		somePotion = new WD(); //WOUND DEFENCE
	}
	else {
		somePotion = nullptr;
		std::cerr << "End of ctrl flow. PotionFactory.h" << std::endl;
	}
	return somePotion;
}

// Original Code

//Potion* PotionFactory(int potId) {
//	if(potId == 0) {
//		return new RH(); //RESTORE HEALTH
//	}
//	else if(potId == 1) {
//		return new BA(); //BOOST ATTACK
//	}
//	else if (potId == 2) {
//		return new BD(); //BOOST DEFENCE
//	}
//	else if (potId == 3) {
//		return new PH(); //POISON HEALTH
//	}
//	else if (potId == 4) {
//		return new WA(); //WOUND ATTACK
//	}
//	else if (potId == 5) {
//		return new WD(); //WOUND DEFENCE
//	}
//}



#endif
