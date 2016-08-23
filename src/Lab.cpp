#include "Lab.h"

#include <iostream>
#include <string>

#include "Position.h"

using namespace std;
//=========================================================================
// CONSTRUCTOR
//=========================================================================
Lab::Lab(string pName, double pArea, int pDoors, Position pPosition, int pComputers) :
		Room(pName, pArea, pDoors, pPosition) {
	computers = pComputers;
}
void Lab::printRoom() {
	cout << expand_self << "\tComputers: " << computers << endl;
}
int Lab::getComputers() const {
	return computers;
}

void Lab::setComputers(int computers) {
	this->computers = computers;
}

double Lab::getEquipmentDensity() {
	return computers / area;
}
