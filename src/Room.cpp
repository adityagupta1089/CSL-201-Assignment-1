/*
 * Room.cpp
 *
 *  Created on: 07-Aug-2016
 *      Author: aditya
 */

#include "Room.h"

#include <iostream>

using namespace std;

Room::Room(string pName, double pArea, int pDoors, Position pPosition) :
		name(pName), area(pArea), doors(pDoors), position(pPosition) {
}

void Room::printRoom() {
	cout << expand_self << endl;
}

