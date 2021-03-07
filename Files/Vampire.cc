#include <string>
#include "Vampire.h"

using namespace std;

Vampire::Vampire(): Player(-1, 50, 25, 25, "Vampire") {} // gains 5HP every attack, no limit on maxHP (-1)

Vampire::~Vampire(){}
