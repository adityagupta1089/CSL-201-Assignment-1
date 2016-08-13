#ifndef ROOMBOOKINGSYSTEM_H_
#define ROOMBOOKINGSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>

#include "Position.h"
#include "Room.h"
#include "Lab.h"
#include "LectureHall.h"

class Lab;
class LectureHall;

using namespace std;
//TODO make readme
class RoomBookingSystem {

	//=========================================================================
	// FUNCTION TO PARSE READ DATA FROM FILE / CONSTRUCTOR HELPER FUNCTION
	//=========================================================================
	void parse(vector<vector<string> > roomDetails, int type);
	//=========================================================================
	// FUNCTION TO FIND ROOM
	//=========================================================================
	template<typename T, typename U> T* getRoom(vector<T>& vec,
			const U matcher) const;
	//=========================================================================
	// FUNCTION TO REMOVE ROOM
	//=========================================================================
	template<typename T> void remove(vector<T>& vec, const T& t);
	//=========================================================================
	// FUNCTION TO PRINT
	//=========================================================================
	template<typename T> void print(vector<T>& vec, const string& pDescriptor);
	struct RoomComparator {
		bool operator()(const int i, const int j);
	};
public:

	//=========================================================================
	// CONSTRCUTOR AND DESTRUCTOR
	//=========================================================================
	RoomBookingSystem();
	~RoomBookingSystem();
	//=========================================================================
	// FUNCTIONS TO ADD ROOMS/LABS/LECTURE HALLS
	//=========================================================================
	void addRoom(const string& pName, const double pArea, const int pDoors,
			const int pX, const int pY);
	void addLab(const string& pName, const double pArea, const int pDoors,
			const int pX, const int pY, int pComputers);
	void addLectureHall(const string& pName, const double pArea,
			const int pDoors, const int pX, const int pY, const int pChairs);
	//=========================================================================
	// FUNCTIONS TO REMOVE ROOMS
	//=========================================================================
	void removeRoom(const Room& r);
	void removeLab(const Lab& r);
	void removeLectureHall(const LectureHall& r);
	//=========================================================================
	// FUNCTIONS TO BOOK/UNBOOK ROOMS
	//=========================================================================
	void bookRoom(const Room &r);
	void unbookRoom(const Room &r);
	//=========================================================================
	// FUCNTIONS TO GET ROOMS/LECTURE HALLS/LABS
	//=========================================================================
	Room*getRoom(const string& pName) const;
	Lab* getLab(const string& pName) const;
	LectureHall* getLectureHall(const string& pName) const;
	//=========================================================================
	Room* getRoom(const int pX, const int pY) const;
	Lab* getLab(const int pX, const int pY) const;
	LectureHall* getLectureHall(const int pX, const int pY) const;
	//=========================================================================
	vector<Room>* getMinimumRoomsOfArea(const int pRequiredArea) const;
	LectureHall* getSmallestLectureHallByChairs(
			const int pRequiredChairs) const;
	Lab* getLabByLeastEquipmentDensity() const;
	Room* getNearestRoom(const int pX, const int pY) const;
	//=========================================================================
	// PRINTING FUCNTIONS
	//=========================================================================
	void printAll();

};

#endif /* ROOMBOOKINGSYSTEM_H_ */
