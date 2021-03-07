#include "GameObject.h"

using namespace std;

GameObject::GameObject(const char objectSymbol): objectSymbol(objectSymbol) {
	position = nullptr;
}

GameObject::~GameObject() {}

void GameObject::setPosition(Cell *pos) {
	position = pos;
}

Cell* GameObject::getPosition() {
	return position;
}

char GameObject::getObjectSymbol() {
    return objectSymbol;
}
