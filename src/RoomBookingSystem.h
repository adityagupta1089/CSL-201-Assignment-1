#ifndef ROOMBOOKINGSYSTEM_H_
#define ROOMBOOKINGSYSTEM_H_

#include <string>
#include <vector>

#include "Room.h"

using namespace std;
//TODO add Operator overloading
//TODO Function templates
//TODO make readme
class RoomBookingSystem {
	//=========================================================================
	// FUNCTION TO PARSE READ DATA FROM FILE / CONSTRUCTOR HELPER FUNCTION
	//=========================================================================
	void parse(vector<vector<string> > roomDetails, int type);

public:
	//=========================================================================
	// CONSTRCUTOR AND DESTRUCTOR
	//=========================================================================
	RoomBookingSystem();
	~RoomBookingSystem();
	//=========================================================================
	// FUNCTIONS TO ADD ROOMS/LABS/LECTURE HALLS
	//=========================================================================
	void addRoom(string pName, double pArea, int pDoors, int pX, int pY);
	void addLab(string pName, double pArea, int pDoors, int pX, int pY,
			int pComputers);
	void addLectureHall(string pName, double pArea, int pDoors, int pX, int pY,
			int pChairs);
	//=========================================================================
	// FUNCTIONS TO REMOVE ROOMS
	//=========================================================================
	void removeRoom(Room& r);
	//=========================================================================
	// FUNCTIONS TO BOOK/UNBOOK ROOMS
	//=========================================================================
	void bookRoom(Room &r);
	void unbookRoom(Room &r);
	//=========================================================================
	// FUCNTIONS TO GET ROOMS/LECTURE HALLS/LABS
	//=========================================================================
	Room getRoom(string pName);
	Room getRoom(int pX, int pY);
	vector<Room> getRoom(int pRequiredArea);
	Room getLectureHall(int pRequiredChairs);
	Room getLab(double pRequiredLabDensity);
	void getNearestRoom(int pX, int pY);
	//=========================================================================
	// MISCELLANEOUS FUCNTIONS
	//=========================================================================
	void printAll();
	void print(vector<Room>& vec, string pDescriptor);
};

#endif /* ROOMBOOKINGSYSTEM_H_ */
