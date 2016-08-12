#include "Lab.h"

#include <iostream>
#include <string>

#include "Position.h"

using namespace std;
//=========================================================================
// CONSTRUCTOR
//=========================================================================
Lab::Lab(string pName, double pArea, int pDoors, Position pPosition,
		int pComputers) :
		Room(pName, pArea, pDoors, pPosition) {
	computers = pComputers;
}
//=========================================================================
// PRINT ITSELF
//=========================================================================
void Lab::printRoom() {
	cout << expand_self << ", Computers: " << setw(4) << computers << endl;
}

