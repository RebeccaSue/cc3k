#include "Potion.h"

using namespace std;

Potion::Potion(string type): Item('P'), type{type} {} 

Potion::~Potion() {}

std::string Potion::getType() {
	return type;
}
