/*
 * LectureHall.cpp
 *
 *  Created on: 11-Aug-2016
 *      Author: aditya
 */

#include "LectureHall.h"

#include <iostream>

#include "Position.h"

using namespace std;

LectureHall::LectureHall(string pName, double pArea, int pDoors,
		Position pPosition, int pChairs) :
		Room(pName, pArea, pDoors, pPosition) {
	chairs = pChairs;
}

void LectureHall::printRoom() {
	cout << expand_self << " Chairs: " << chairs << endl;
}

