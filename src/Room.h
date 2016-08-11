/*
 * Room.h
 *
 *  Created on: 07-Aug-2016
 *      Author: aditya
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <string>

#include "Position.h"

using namespace std;
class Room {
public:
	string name;
	double area;
	int doors;
	Position position;
	Room(string pName, double pArea, int pDoors, Position pPosition);
};

#endif /* ROOM_H_ */
