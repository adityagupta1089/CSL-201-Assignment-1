#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <iomanip>

#include "Position.h"
//=========================================================================
// MACRO TO HELP WHILE PRINTING ITSELF
//=========================================================================
#define expand_self "Name: " << setw(10) << name\
	<< ", Area: " << setw(8) << area\
	<< ", Doors: " << setw(3) << doors\
	<< ", Position: (" <<setw(4) << position.x\
	<< "," << setw(4) << position.y << ")"\
	<< ", Booked: "<< ((booked)?"Yes":"No")

using namespace std;

class Room {

protected:

	//=========================================================================
	// VARIABLES
	//=========================================================================
	string name;
	double area;
	int doors;
	Position position;
	bool booked;

public:

	//=========================================================================
	// CONSTRUCTOR
	//=========================================================================
	Room(string pName, double pArea, int pDoors, Position pPosition);
	//=========================================================================
	// PRINT ITSELF
	//=========================================================================
	virtual void printRoom();
	//=========================================================================
	// DESTRCUTOR
	//=========================================================================
	virtual ~Room() {
	}
	//=========================================================================
	// COMPARATOR
	//=========================================================================
	bool operator==(const Room& r);
	//=========================================================================
	// GETTERS and SETTERS
	//=========================================================================
	double getArea() const;
	bool isBooked() const;
	void book();
	void unbook();
	int getDoors() const;
	const string& getName() const;
	Position getPosition() const;
};

#endif /* ROOM_H_ */
