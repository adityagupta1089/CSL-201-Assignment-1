#ifndef LAB_H_
#define LAB_H_

#include "Room.h"

using namespace std;

class Lab: public Room {

		int computers;

	public:

		Lab(string pName, double pArea, int pDoors, Position pPosition, int pComputers);
		virtual void printRoom();
		virtual ~Lab() {
		}
		int getComputers() const;
		void setComputers(int computers);
		double getEquipmentDensity();
};

#endif /* LAB_H_ */
