/*
 * Lab.h
 *
 *  Created on: 11-Aug-2016
 *      Author: aditya
 */

#ifndef LAB_H_
#define LAB_H_

#include "Room.h"

using namespace std;

class Lab: public Room {
public:
	int computers;
	Lab(string pName, double pArea, int pDoors, Position pPosition,
			int pComputers);
	virtual void printRoom();
	virtual ~Lab();
};

#endif /* LAB_H_ */
