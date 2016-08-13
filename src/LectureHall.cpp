#include "LectureHall.h"

#include <iostream>

#include "Position.h"

using namespace std;
//=========================================================================
// CONSTRUCTOR
//=========================================================================
LectureHall::LectureHall(string pName, double pArea, int pDoors,
		Position pPosition, int pChairs) :
		Room(pName, pArea, pDoors, pPosition) {
	chairs = pChairs;
}
//=========================================================================
// PRINT ITSELF
//=========================================================================
void LectureHall::printRoom() {
	cout << expand_self << ", Chairs: " << setw(4) << chairs << endl;
}
//=========================================================================
// GETTERS and SETTERS
//=========================================================================
int LectureHall::getChairs() const {
	return chairs;
}

void LectureHall::setChairs(int chairs) {
	this->chairs = chairs;
}

