#include "Room.h"

#include <iostream>

using namespace std;
//=========================================================================
// CONSTRUCTOR
//=========================================================================
Room::Room(string pName, double pArea, int pDoors, Position pPosition) :
		name(pName), area(pArea), doors(pDoors), position(pPosition), booked(
				false) {
}
//=========================================================================
// PRINT ITSELF
//=========================================================================
void Room::printRoom() {
	cout << expand_self << endl;
}
//=========================================================================
// COMPARATOR
//=========================================================================
bool Room::operator==(const Room& r) {
	return name == r.name && position.x == r.position.x
			&& position.y == r.position.y;
}
//=========================================================================
// GETTERS and SETTERS
//=========================================================================
double Room::getArea() const {
	return area;
}

bool Room::isBooked() const {
	return booked;
}

void Room::book() {
	this->booked = true;
}
void Room::unbook() {
	this->booked = false;
}

int Room::getDoors() const {
	return doors;
}

const string& Room::getName() const {
	return name;
}

Position Room::getPosition() const {
	return position;
}

