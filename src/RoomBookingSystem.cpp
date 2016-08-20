#include "RoomBookingSystem.h"

#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <iterator>

#include "Matchers.h"
#include "Reader.h"

//==============================================================================
// MACRO TO EXPAND ROOM-DETAILS' ITERATOR TO DETAILS AND CAST TO SPECIFIC
// DATA TYPES
//==============================================================================
#define expand_it (*it)[0], atof((*it)[1].c_str()), atoi((*it)[2].c_str()),\
	Position(atoi((*it)[3].c_str()), atoi((*it)[4].c_str()))
//==============================================================================
// MACRO TO HELP WHILE PRINTING DETAILS
//==============================================================================
#define print_separator cout<<string(100,'=')<<endl;
//==============================================================================
// MISCELLANEOUS MACROS
//==============================================================================
#define sq(x) (x)*(x)
//==============================================================================
// NAMESPACE
//==============================================================================
using namespace std;
//==============================================================================
// DATA STORAGE VECTORS
//==============================================================================
vector<Room*> rooms;
vector<Room*> labss; //labs = long abs value function
vector<Room*> lectureHalls;
//==============================================================================
// CONSTRUCTOR AND DESTRUCTOR
//==============================================================================
RoomBookingSystem::RoomBookingSystem() {
	vector<vector<string> > roomDetails = Reader::read("data/ROOM.txt", 5);
	vector<vector<string> > labDetails = Reader::read("data/LAB.txt", 6);
	vector<vector<string> > lectureHallDetails = Reader::read("data/LEC.txt", 6);
	parse(roomDetails, ROOMS);
	parse(labDetails, LABS);
	parse(lectureHallDetails, LECTURE_HALLS);
}

RoomBookingSystem::~RoomBookingSystem() {
	//TODO write to output file
}
//==============================================================================
// INT TO VECTOR
//==============================================================================
vector<Room*>* RoomBookingSystem::getList(int type) {
	switch (type) {
		case ROOMS:
			return &rooms;
		case LABS:
			return &labss;
		case LECTURE_HALLS:
			return &lectureHalls;
	}
}
vector<Room*>* RoomBookingSystem::getConstList(int type) const {
	switch (type) {
		case ROOMS:
			return &rooms;
		case LABS:
			return &labss;
		case LECTURE_HALLS:
			return &lectureHalls;
	}
}
//==============================================================================
// CONSTRUCTOR-HELPER FUNCTION
//==============================================================================
void RoomBookingSystem::parse(vector<vector<string> > roomDetails, int type) {
	for (vector<vector<string> >::iterator it = roomDetails.begin(); it != roomDetails.end(); it++) {
		switch (type) {
			case ROOMS:
				rooms.push_back(new Room(expand_it));
				break;
				case LABS:
				labss.push_back(new Lab(expand_it, atoi((*it)[5].c_str())));
				break;
				case LECTURE_HALLS:
				lectureHalls.push_back(new LectureHall(expand_it, atoi((*it)[5].c_str())));
				break;
			}
		}
	}
//==============================================================================
// FUNCTIONS TO BOOK/UNBOOK ROOM
//==============================================================================
void bookRoom(Room &r) {
	r.book();
}
void unbookRoom(Room &r) {
	r.unbook();
}
//==============================================================================
// MISCELLANEOUS FUNCTIONS
//==============================================================================
void RoomBookingSystem::printAll() {
	print<Room>(rooms, "Rooms");
	print<Lab>(labss, "Labs");
	print<LectureHall>(lectureHalls, "Lecture Halls");
}
template<typename T> void RoomBookingSystem::print(vector<Room*>& vec, const string& pDescriptor) {
	print_separator
	cout << "These are currently " << vec.size() << " " << pDescriptor << ": " << endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		((T*) vec[i])->printRoom();
	}
	print_separator
}
//==============================================================================
// FUNCTIONS TO ADD ROOMS/LABS/LECTURE HALLS
//==============================================================================
void RoomBookingSystem::addRoom(const string& pName, const double pArea, const int pDoors, const int pX, const int pY) {
	rooms.push_back(new Room(pName, pArea, pDoors, Position(pX, pY)));
}
void RoomBookingSystem::addLab(const string& pName, const double pArea, const int pDoors, const int pX, int pY, int pComputers) {
	labss.push_back(new Lab(pName, pArea, pDoors, Position(pX, pY), pComputers));
}
void RoomBookingSystem::addLectureHall(const string& pName, const double pArea, const int pDoors, const int pX, const int pY, const int pChairs) {
	lectureHalls.push_back(new LectureHall(pName, pArea, pDoors, Position(pX, pY), pChairs));
}
//==============================================================================
// FUNCTIONS TO GET ROOM/LAB/LECTURE HALL
//==============================================================================
Room* RoomBookingSystem::getRoom(const string& pName, int type) const {
	return getRoom(type, Matchers::MatchName(pName));
}
//==============================================================================
Room* RoomBookingSystem::getRoom(const int pX, const int pY, int type) const {
	return getRoom(type, Matchers::MatchPosition(pX, pY));
}
//=========================================================================
// COMPARES ROOM BASED ON AREA AND WHETHER THEY ARE BOOKED FOR
// `getMinimumRoomsOfArea`
//=========================================================================
bool RoomBookingSystem::RoomComparator::operator()(const int i, const int j) {
	bool b1 = rooms[i]->isBooked();
	bool b2 = rooms[j]->isBooked();
	if (b1 && !b2) {
		return i;
	} else if (!b1 && b2) {
		return j;
	} else {	//also included case !b1&&!b2
		return rooms[i]->getArea() >= rooms[j]->getArea();
	}
}
//=========================================================================
// OTHER get FUNCTIONS
//=========================================================================
vector<Room*> RoomBookingSystem::getMinimumRoomsOfArea(const int pRequiredArea) const {
	vector<int> roomIndices;
	vector<Room*> requiredRoom;
	for (unsigned i = 0; i < rooms.size(); i++)
		roomIndices.push_back(i);
	sort(roomIndices.begin(), roomIndices.end(), RoomComparator());
	double area = 0;
	for (unsigned i = 0; i < roomIndices.size() && area < pRequiredArea && !rooms[roomIndices[i]]->isBooked(); i++) {
		area += rooms[roomIndices[i]]->getArea();
		requiredRoom.push_back(rooms[roomIndices[i]]);
	}
	if (area >= pRequiredArea)
		return requiredRoom;
	else {
		vector<Room*> emptyVec;
		return emptyVec;
	}
}
//==============================================================================
LectureHall* RoomBookingSystem::getSmallestLectureHallByStudents(const int pRequiredChairs) const {
	double minArea = DBL_MAX;
	LectureHall* requiredHall = new LectureHall("", 0, 0, Position(0, 0), 0);
	for (vector<Room*>::iterator it = lectureHalls.begin(); it != lectureHalls.end(); it++) {
		if (((LectureHall*) *it)->getChairs() >= pRequiredChairs && !(*it)->isBooked() && (*it)->getArea() < minArea) {
			requiredHall = (LectureHall*) *it;
			minArea = requiredHall->getArea();
		}
	}
	return requiredHall;
}
//==============================================================================
Lab* RoomBookingSystem::getLabByLeastEquipmentDensity() const {
	double minDensity = DBL_MAX;
	Lab* requiredLab = new Lab("", 0, 0, Position(0, 0), 0);
	for (vector<Room*>::iterator it = labss.begin(); it != labss.end(); it++) {
		if (((Lab*) &(*it))->getEquipmentDensity() < minDensity && !(*it)->isBooked()) {
			requiredLab = (Lab*) *it;
			minDensity = requiredLab->getEquipmentDensity();
		}
	}
	return requiredLab;
}
//==============================================================================
Room* RoomBookingSystem::getNearestRoom(const int pX, const int pY) const {
	long minDistanceSquared = LONG_MAX;
	Room* requiredRoom = new Room("", 0, 0, Position(0, 0));
	for (vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++) {
		long distanceSquared = sq((*it)->getPosition().x - pX) + sq((*it)->getPosition().y - pY);
		if (distanceSquared < minDistanceSquared && !(*it)->isBooked()) {
			requiredRoom = *it;
			minDistanceSquared = distanceSquared;
		}
	}
	return requiredRoom;
}
//==============================================================================
template<class T> Room* RoomBookingSystem::getRoom(int type, const T matcher) const {
	vector<Room*>* vec = getConstList(type);
	vector<Room*>::iterator r = find_if(vec->begin(), vec->end(), matcher);
	return *r;
}
//==============================================================================
// FUNCTIONS TO REMOVE ROOM
//==============================================================================
bool RoomBookingSystem::removeRoom(int type, Room* r) {
	vector<Room*>* vec = getList(type);
	if (r != *vec->end()) {
		vec->erase(std::remove(vec->begin(), vec->end(), r), vec->end());
		return true;
	} else
		return false;
}
