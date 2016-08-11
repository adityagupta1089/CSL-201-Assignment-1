/*
 * Lab.cpp
 *
 *  Created on: 11-Aug-2016
 *      Author: aditya
 */

#include "Lab.h"

#include <iostream>
#include <string>

#include "Position.h"

using namespace std;

Lab::Lab(string pName, double pArea, int pDoors, Position pPosition,
		int pComputers) :
		Room(pName, pArea, pDoors, pPosition) {
	computers = pComputers;
}

void Lab::printRoom() {
	cout << expand_self << ", Computers: " << computers << endl;
}

