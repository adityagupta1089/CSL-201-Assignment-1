#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <iomanip>

#include "Position.h"
//=========================================================================
// MACRO TO HELP WHILE PRINTING ITSELF
//=========================================================================

#define expand_self "Name: "<<name<<"\tArea: "<<area<<"\tDoors: "<<doors<<"\tPosition: ("<<position.x<<","<<position.y<<")\tBooked: "<<((booked)?"Yes":"No")

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
		bool operator==(const Room& b);
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
