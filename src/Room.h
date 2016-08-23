#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <iomanip>

#include "Position.h"

#define expand_self "Name: "<<name<<"\tArea: "<<setprecision(4)<<area<<"\tDoors: "<<doors<<"\tPosition: ("<<position.x<<","<<position.y<<")\tBooked: "<<((booked)?"Yes":"No")

using namespace std;

class Room {

	protected:

		string name;
		double area;
		int doors;
		Position position;
		bool booked;

	public:

		Room(string pName, double pArea, int pDoors, Position pPosition);
		virtual void printRoom();
		virtual ~Room() {
		}
		bool operator==(const Room& b);
		double getArea() const;
		bool isBooked() const;
		void book();
		void unbook();
		int getDoors() const;
		const string& getName() const;
		Position getPosition() const;

		void setBooked(bool booked);
};

#endif /* ROOM_H_ */
