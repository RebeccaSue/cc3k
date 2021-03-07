#include "Gold.h"

using namespace std;

Gold::Gold(int value, string type, bool pickable): Item('G'), value{value}, type{type}, pickable{pickable} {}

Gold::~Gold() {}

// TEMPORARY
//void Gold::useBy(Player *pc) {
//	// TODO (next line for compilation purposes. Temporary)
//	std::cerr << "useBy in Gold.cc undefined" << std::endl;
//}

// methods:



smallHoard::smallHoard(): Gold(1, "Small", true) {}
smallHoard::~smallHoard(){}

normalHoard::normalHoard(): Gold(2, "Normal", true) {}
normalHoard::~normalHoard(){}

merchantHoard::merchantHoard(): Gold(4, "Merchant's", true) {}
merchantHoard::~merchantHoard(){}

humanHoard::humanHoard(): Gold(4, "Human's", true) {}
humanHoard::~humanHoard(){}

dragonHoard::dragonHoard(): Gold(6, "Dragon's", false){}
dragonHoard::~dragonHoard(){}

