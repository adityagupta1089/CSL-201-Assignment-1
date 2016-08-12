#include "RoomBookingSystem.h"

#include <stdlib.h>
#include <algorithm>//algorithm
#include <iostream>
#include <iterator>

#include "Lab.h"
#include "LectureHall.h"
#include "Position.h"
#include "Reader.h"

//=========================================================================
// MACROS TO HELP DEFINE ROOM-TYPES
//=========================================================================
#define ROOMS 0
#define LABS 1
#define LECTURE_HALLS 2
//=========================================================================
// MACRO TO EXPAND ROOM-DETAILS' ITERATOR TO DETAILS AND CAST TO SPECIFIC
// DATA TYPES
//=========================================================================
#define expand_it (*it)[0], atof((*it)[1].c_str()), atoi((*it)[2].c_str()),\
	Position(atoi((*it)[3].c_str()), atoi((*it)[4].c_str()))
//=========================================================================
// MACRO TO HELP WHILE PRINTING DETAILS
//=========================================================================
#define print_separator cout<<string(84,'=')<<endl;

using namespace std;
//=========================================================================
// DATA STORAGE VECTORS
//=========================================================================
vector<Room> rooms;
vector<Room> labss; //labs = long abs value function
vector<Room> lectureHalls;
//=========================================================================
// CONSTRUCTOR AND DESTRUCTOR
//=========================================================================
RoomBookingSystem::RoomBookingSystem() {
	vector<vector<string> > roomDetails = Reader::read("data/ROOM.txt", 5);
	vector<vector<string> > labDetails = Reader::read("data/LAB.txt", 6);
	vector<vector<string> > lectureHallDetails = Reader::read("data/LEC.txt",
			6);
	parse(roomDetails, ROOMS);
	parse(labDetails, LABS);
	parse(lectureHallDetails, LECTURE_HALLS);
}

RoomBookingSystem::~RoomBookingSystem() {
	//TODO write to output file
}

//=========================================================================
// CONSTRUCTOR-HELPER FUNCTION
//=========================================================================
void RoomBookingSystem::parse(vector<vector<string> > roomDetails, int type) {
	vector<vector<string> >::iterator it = roomDetails.begin();
	while (it != roomDetails.end()) {
		switch (type) {
		case ROOMS:
			rooms.push_back(*new Room(expand_it));
			break;
			case LABS:
			labss.push_back( *new Lab(expand_it,atoi((*it)[5].c_str())));
			break;
			case LECTURE_HALLS:
			lectureHalls.push_back( *new LectureHall(expand_it,atoi((*it)[5].c_str())));
			break;
		}
		it++;
	}
}
//=========================================================================
// FUNCTIONS TO BOOK/UNBOOK ROOM
//=========================================================================
void bookRoom(Room &r) {
	r.book();
}
void unbookRoom(Room &r) {
	r.unbook();
}
//=========================================================================
// MISCELLANEOUS FUNCTIONS
//=========================================================================
void RoomBookingSystem::printAll() {
	print(rooms, "Rooms");
	print(labss, "Labs");
	print(lectureHalls, "Lecture Halls");
}
void RoomBookingSystem::print(vector<Room>& vec, string pDescriptor) {
	print_separator
	cout << "These are currently " << vec.size() << " " << pDescriptor << ": "
			<< endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		vec[i].printRoom();
	}
	print_separator
}
//=========================================================================
// FUNCTIONS TO ADD ROOMS/LABS/LECTURE HALLS
//=========================================================================
void RoomBookingSystem::addRoom(string pName, double pArea, int pDoors, int pX,
		int pY) {
	rooms.push_back(*new Room(pName, pArea, pDoors, Position(pX, pY)));
}
void RoomBookingSystem::addLab(string pName, double pArea, int pDoors, int pX,
		int pY, int pComputers) {
	rooms.push_back(
			*new Lab(pName, pArea, pDoors, Position(pX, pY), pComputers));
}
void RoomBookingSystem::addLectureHall(string pName, double pArea, int pDoors,
		int pX, int pY, int pChairs) {
	rooms.push_back(
			*new LectureHall(pName, pArea, pDoors, Position(pX, pY), pChairs));
}
//=========================================================================
// FUNCTIONS TO GET ROOM/LAB/LECTURE HALL
//=========================================================================
Room getRoom(string pName) { //TODO get room by name

}

Room getRoom(int pX, int pY) { //TODO get room by location

}
vector<Room> getRoom(int pRequiredArea) { //TODO get rooms by area to sleep

}
Room getLectureHall(int pRequiredChairs) { //TODO get lecture hall by chairs

}
Room getLab(double pRequiredLabDensity) { //TODO get labs by density

}
Room getNearestRoom(int pX,int pYFS){//TODO get nearest room

}
//=========================================================================
// FUNCTIONS TO REMOVE ROOM
//=========================================================================
void RoomBookingSystem::removeRoom(Room& r) {
	//TODO remove room
}
