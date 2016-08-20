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
//==============================================================================
// MACROS TO HELP DEFINE ROOM-TYPES
//==============================================================================
#define ROOMS 1
#define LABS 2
#define LECTURE_HALLS 3

//TODO make readme
class RoomBookingSystem {

		//=========================================================================
		// INTERNAL FUNCTIONS
		//=========================================================================
		void parse(vector<vector<string> > roomDetails, int type);
		vector<Room*>* getList(int type);
		vector<Room*>* getConstList(int type) const;
		template<typename T> Room* getRoom(int type, const T matcher) const;
		template<typename T> void print(vector<Room*>& vec, const string& pDescriptor);
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
		void addRoom(const string& pName, const double pArea, const int pDoors, const int pX, const int pY);
		void addLab(const string& pName, const double pArea, const int pDoors, const int pX, const int pY, int pComputers);
		void addLectureHall(const string& pName, const double pArea, const int pDoors, const int pX, const int pY, const int pChairs);
		//=========================================================================
		// FUNCTION TO REMOVE ROOMS
		//=========================================================================
		bool removeRoom(int type, Room* r);
		//=========================================================================
		// FUCNTIONS TO GET ROOMS/LECTURE HALLS/LABS
		//=========================================================================
		Room* getRoom(const string& pName, int type) const;
		//=========================================================================
		Room* getRoom(const int pX, const int pY, int type) const;
		//=========================================================================
		vector<Room*> getMinimumRoomsOfArea(const int pRequiredArea) const;
		LectureHall* getSmallestLectureHallByStudents(const int pRequiredChairs) const;
		Lab* getLabByLeastEquipmentDensity() const;
		Room* getNearestRoom(const int pX, const int pY) const;
		//=========================================================================
		// PRINTING FUCNTIONS
		//=========================================================================
		void printAll();

};

#endif /* ROOMBOOKINGSYSTEM_H_ */
