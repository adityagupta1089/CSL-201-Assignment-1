/*
 * LectureHall.h
 *
 *  Created on: 11-Aug-2016
 *      Author: aditya
 */

#ifndef LECTUREHALL_H_
#define LECTUREHALL_H_

#include <string>

#include "Room.h"

using namespace std;

class LectureHall: public Room {
public:
	int chairs;
	LectureHall(string pName, double pArea, int pDoors, Position pPosition,
			int pChairs);
	virtual void printRoom();
	virtual ~LectureHall();
};

#endif /* LECTUREHALL_H_ */
