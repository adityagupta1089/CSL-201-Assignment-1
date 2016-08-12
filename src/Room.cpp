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

