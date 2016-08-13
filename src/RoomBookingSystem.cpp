#include "RoomBookingSystem.h"

#include <stdlib.h>
#include <cfloat>
#include <climits>
#include <iterator>
#include <algorithm> //don't remove

#include "Matchers.h"
#include "Reader.h"

//==============================================================================
// MACROS TO HELP DEFINE ROOM-TYPES
//==============================================================================
#define ROOMS 0
#define LABS 1
#define LECTURE_HALLS 2
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
vector<Room> rooms;
vector<Lab> labss; //labs = long abs value function
vector<LectureHall> lectureHalls;
//==============================================================================
// CONSTRUCTOR AND DESTRUCTOR
//==============================================================================
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

//==============================================================================
// CONSTRUCTOR-HELPER FUNCTION
//==============================================================================
void RoomBookingSystem::parse(vector<vector<string> > roomDetails, int type) {
	vector<vector<string> >::iterator it = roomDetails.begin();
	while (it != roomDetails.end()) {
		switch (type) {
		case ROOMS:
			rooms.push_back(*new Room(expand_it));
			break;
			case LABS:
			labss.push_back( *new Lab(expand_it, atoi((*it)[5].c_str())));
			break;
			case LECTURE_HALLS:
			lectureHalls.push_back( *new LectureHall(expand_it,
					atoi((*it)[5].c_str())));
			break;
		}
		it++;
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
	print(rooms, "Rooms");
	print(labss, "Labs");
	print(lectureHalls, "Lecture Halls");
}
template<typename T> void RoomBookingSystem::print(vector<T>& vec,
		const string& pDescriptor) {
	print_separator
	cout << "These are currently " << vec.size() << " " << pDescriptor << ": "
			<< endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		vec[i].printRoom();
	}
	print_separator
}
//==============================================================================
// FUNCTIONS TO ADD ROOMS/LABS/LECTURE HALLS
//==============================================================================
void RoomBookingSystem::addRoom(const string& pName, const double pArea,
		const int pDoors, const int pX, const int pY) {
	rooms.push_back(*new Room(pName, pArea, pDoors, Position(pX, pY)));
}
void RoomBookingSystem::addLab(const string& pName, const double pArea,
		const int pDoors, const int pX, int pY, int pComputers) {
	rooms.push_back(
			*new Lab(pName, pArea, pDoors, Position(pX, pY), pComputers));
}
void RoomBookingSystem::addLectureHall(const string& pName, const double pArea,
		const int pDoors, const
		int pX, const int pY, const int pChairs) {
	rooms.push_back(
			*new LectureHall(pName, pArea, pDoors, Position(pX, pY), pChairs));
}
//==============================================================================
// FUNCTIONS TO GET ROOM/LAB/LECTURE HALL
//==============================================================================
Room* RoomBookingSystem::getRoom(const string& pName) const {
	return getRoom<Room>(rooms, Matchers::MatchName(pName));
}
Lab* RoomBookingSystem::getLab(const string& pName) const {
	return getRoom<Lab>(labss, Matchers::MatchName(pName));
}
LectureHall* RoomBookingSystem::getLectureHall(const string& pName) const {
	return getRoom<LectureHall>(lectureHalls, Matchers::MatchName(pName));
}
//==============================================================================
Room* RoomBookingSystem::getRoom(const int pX, const int pY) const {
	return getRoom<Room>(rooms, Matchers::MatchPosition(pX, pY));
}
Lab* RoomBookingSystem::getLab(const int pX, const int pY) const {
	return getRoom<Lab>(labss, Matchers::MatchPosition(pX, pY));
}
LectureHall* RoomBookingSystem::getLectureHall(const int pX,
		const int pY) const {
	return getRoom<LectureHall>(lectureHalls, Matchers::MatchPosition(pX, pY));
}
//==============================================================================
vector<Room> RoomBookingSystem::getMinimumRoomsOfArea(
		const int pRequiredArea) const {
	vector<int> roomIndices;
	vector<Room> requiredRoom;
	for (unsigned i = 0; i < rooms.size(); i++)
		roomIndices.push_back(i);
	sort(roomIndices.begin(), roomIndices.end(), RoomComparator());
	double area = 0;
	for (unsigned i = 0;
			i < roomIndices.size() && area < pRequiredArea
					&& !rooms[roomIndices[i]].isBooked(); i++) {
		area += rooms[roomIndices[i]].getArea();
		requiredRoom.push_back(rooms[roomIndices[i]]);
	}
	if (area >= pRequiredArea)
		return requiredRoom;
	else
		cerr << "Not Enough Rooms." << endl;
	throw;
}
//=========================================================================
// COMPARES ROOM BASED ON AREA AND WHETHER THEY ARE BOOKED FOR
// `getMinimumRoomsOfArea`
//=========================================================================
bool RoomBookingSystem::RoomComparator::operator()(const int i, const int j) {
	bool b1 = rooms[i].isBooked();
	bool b2 = rooms[j].isBooked();
	if (b1 && !b2) {
		return i;
	} else if (!b1 && b2) {
		return j;
	} else {	//also included case !b1&&!b2
		return rooms[i].getArea() >= rooms[j].getArea();
	}
}

//==============================================================================
LectureHall* RoomBookingSystem::getSmallestLectureHallByChairs(
		const int pRequiredChairs) const {
	double minArea = DBL_MAX;
	LectureHall* requiredHall;
	for (vector<LectureHall>::iterator it = lectureHalls.begin();
			it != lectureHalls.end(); it++) {
		if (it->getChairs() >= pRequiredChairs && !it->isBooked()) {
			if (it->getArea() < minArea) {
				requiredHall = &*it;
				minArea = requiredHall->getArea();
			}
		}
	}
	return requiredHall;
}
Lab* RoomBookingSystem::getLabByLeastEquipmentDensity() const {
	double minDensity = DBL_MAX;
	Lab* requiredLab;
	for (vector<Lab>::iterator it = labss.begin(); it != labss.end(); it++) {
		if (it->getEquipmentDensity() < minDensity && !it->isBooked()) {
			requiredLab = &*it;
			minDensity = requiredLab->getEquipmentDensity();
		}
	}
	return requiredLab;
}
Room* RoomBookingSystem::getNearestRoom(const int pX, const int pY) const {
	long minDistanceSquared = LONG_MAX;
	Room* requiredRoom;
	for (vector<Room>::iterator it = rooms.begin(); it != rooms.end(); it++) {
		long distanceSquared = sq(
				it->getPosition().x - pX) + sq(it->getPosition().y - pY);
		if (distanceSquared < minDistanceSquared && !it->isBooked()) {
			requiredRoom = &*it;
			minDistanceSquared = distanceSquared;
		}
	}
	return requiredRoom;
}
//==============================================================================
template<typename T, typename U> T* RoomBookingSystem::getRoom(vector<T>& vec,
		const U matcher) const {
	typename vector<T>::iterator r = find_if(vec.begin(), vec.end(), matcher);
	if (r != vec.end())
		return &*r;
	else
		cerr << "Room not found" << endl;
	throw;
}
//==============================================================================
// FUNCTIONS TO REMOVE ROOM
//==============================================================================
void RoomBookingSystem::removeRoom(const Room& r) {
	remove<Room>(rooms, r);
}
//==============================================================================
void RoomBookingSystem::removeLab(const Lab& r) {
	remove<Lab>(labss, r);
}
void RoomBookingSystem::removeLectureHall(const LectureHall& r) {
	remove<LectureHall>(lectureHalls, r);
}
//==============================================================================
template<typename T> void RoomBookingSystem::remove(vector<T>& vec,
		const T& t) {
	vec.erase(std::remove(vec.begin(), vec.end(), t), vec.end());
}
