#ifndef LECTUREHALL_H_
#define LECTUREHALL_H_

#include <string>

#include "Room.h"

using namespace std;

class LectureHall: public Room {

public:
	//=========================================================================
	// VARIABLES
	//=========================================================================
	int chairs;
	//=========================================================================
	// CONSTRUCTOR
	//=========================================================================
	LectureHall(string pName, double pArea, int pDoors, Position pPosition,
			int pChairs);
	//=========================================================================
	// PRINT ITSELF
	//=========================================================================
	virtual void printRoom();
	//=========================================================================
	// DESTRCUTOR
	//=========================================================================
	virtual ~LectureHall() {
	}
	//=========================================================================
	// GETTERS and SETTERS
	//=========================================================================
	int getChairs() const {
		return chairs;
	}

	void setChairs(int chairs) {
		this->chairs = chairs;
	}
};

#endif /* LECTUREHALL_H_ */
