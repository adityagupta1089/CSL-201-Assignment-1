#include "LectureHall.h"

#include <iostream>

#include "Position.h"

using namespace std;

LectureHall::LectureHall(string pName, double pArea, int pDoors, Position pPosition, int pChairs) :
		Room(pName, pArea, pDoors, pPosition) {
	chairs = pChairs;
}

void LectureHall::printRoom() {
	cout << expand_self << "\tChairs: "  << chairs << endl;
}

int LectureHall::getChairs() const {
	return chairs;
}

void LectureHall::setChairs(int chairs) {
	this->chairs = chairs;
}

