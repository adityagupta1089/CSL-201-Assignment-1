#ifndef LECTUREHALL_H_
#define LECTUREHALL_H_

#include <string>

#include "Room.h"

using namespace std;

class LectureHall: public Room {

		int chairs;
	public:
		LectureHall(string pName, double pArea, int pDoors, Position pPosition, int pChairs);
		virtual void printRoom();
		virtual ~LectureHall() {
		}
		int getChairs() const;
		void setChairs(int chairs);
};

#endif /* LECTUREHALL_H_ */
