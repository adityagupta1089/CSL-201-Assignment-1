#include "RoomBookingSystem.h"

#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <fstream>
#include <iterator>
#include <string.h>

#include "Matchers.h"

#define expand_it (*it)[0], atof((*it)[1].c_str()), atoi((*it)[2].c_str()), Position(atoi((*it)[3].c_str()), atoi((*it)[4].c_str()))
#define print_separator cout<<string(100,'=')<<endl;
#define sq(x) (x)*(x)
using namespace std;

#define ROOM_FILE_LOC "data/ROOM.txt"
#define LAB_FILE_LOC "data/LAB.txt"
#define LECTURE_HALL_FILE_LOC "data/LEC.txt"

#define ROOM_BOOK_LOC "data/ROOM_BOOK.txt"
#define LAB_BOOK_LOC "data/LAB_BOOK.txt"
#define LECTURE_HALL_BOOK_LOC "data/LEC_BOOK.txt"

vector<Room*> rooms;
vector<Room*> labss;
vector<Room*> lectureHalls;

RoomBookingSystem::RoomBookingSystem() {
        vector<vector<string> > roomDetails = read(ROOM_FILE_LOC, 5);
        vector<vector<string> > labDetails = read(LAB_FILE_LOC, 6);
        vector<vector<string> > lectureHallDetails = read(LECTURE_HALL_FILE_LOC, 6);
        vector<vector<string> > roomBookDetails = read(ROOM_BOOK_LOC, 1);
        vector<vector<string> > labBookDetails = read(LAB_BOOK_LOC, 1);
        vector<vector<string> > lectureHallBookDetails = read(LECTURE_HALL_BOOK_LOC, 1);
        parse(roomDetails, ROOMS);
        parse(labDetails, LABS);
        parse(lectureHallDetails, LECTURE_HALLS);
        loadstate(roomBookDetails, ROOMS);
        loadstate(labBookDetails, LABS);
        loadstate(lectureHallBookDetails, LECTURE_HALLS);
}

RoomBookingSystem::~RoomBookingSystem() {
        saveRooms(rooms, ROOM_FILE_LOC, ROOM_BOOK_LOC);
        saveRooms(labss, LAB_FILE_LOC, LAB_BOOK_LOC);
        saveRooms(lectureHalls, LECTURE_HALL_FILE_LOC, LECTURE_HALL_BOOK_LOC);
}
vector<vector<string> > RoomBookingSystem::read(const char* pFilename, const int pColumns) {
        ifstream inputStream;
        vector<vector<string> > rooms_list;
        inputStream.open(pFilename);
        if (inputStream.is_open()) {
                while (!inputStream.eof()) {
                        vector<string> roomDetails;
                        for (int i = 0; i < pColumns; i++) {
                                string detail;
                                inputStream >> detail;
                                roomDetails.push_back(detail);
                        }
                        rooms_list.push_back(roomDetails);
                }
        }
        inputStream.close();
        return rooms_list;
}
void RoomBookingSystem::saveRooms(vector<Room*>& vec, const char* loc, const char* bookloc) {
        ofstream outputStream;
        ofstream outputStream2;
        outputStream.open(loc);
        outputStream2.open(bookloc);
        string s = string(loc);
        if (outputStream.is_open() && outputStream2.is_open()) {
                for (unsigned i = 0; i < vec.size(); i++) {
                        Room* r = vec[i];
                        outputStream << r->getName() << "\t" << fixed << setprecision(4) << r->getArea() << "\t" << r->getDoors() << "\t" << r->getPosition().x << "\t" << r->getPosition().y;
                        if (s.compare(LAB_FILE_LOC) == 0) {
                                outputStream << "\t" << ((Lab*) r)->getComputers();
                        } else if (s.compare(LECTURE_HALL_FILE_LOC) == 0) {
                                outputStream << "\t" << ((LectureHall*) r)->getChairs();
                        }
                        outputStream2 << ((vec[i]->isBooked()) ? "1" : "0");
                        if (i != vec.size() - 1) {
                                outputStream << endl;
                                outputStream2 << endl;
                        }
                }
        }
        outputStream.close();
        outputStream2.close();
}
vector<Room*>* RoomBookingSystem::getList(int type) {
        switch (type) {
        case ROOMS:
                return &rooms;
        case LABS:
                return &labss;
        case LECTURE_HALLS:
                return &lectureHalls;
        }
        return NULL;
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
        return NULL;
}

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
void RoomBookingSystem::loadstate(vector<vector<string> > bookstatus, int type) {
        vector<Room*>* vec = getList(type);
        for (unsigned i = 0; i < vec->size(); i++) {
                ((*vec)[i])->setBooked(atoi(bookstatus[i][0].c_str()) == 1);
        }
}

void bookRoom(Room &r) {
        r.book();
}
void unbookRoom(Room &r) {
        r.unbook();
}
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
void RoomBookingSystem::addRoom(const string& pName, const double pArea, const int pDoors, const int pX, const int pY) {
        rooms.push_back(new Room(pName, pArea, pDoors, Position(pX, pY)));
}
void RoomBookingSystem::addLab(const string& pName, const double pArea, const int pDoors, const int pX, int pY, int pComputers) {
        labss.push_back(new Lab(pName, pArea, pDoors, Position(pX, pY), pComputers));
}
void RoomBookingSystem::addLectureHall(const string& pName, const double pArea, const int pDoors, const int pX, const int pY, const int pChairs) {
        lectureHalls.push_back(new LectureHall(pName, pArea, pDoors, Position(pX, pY), pChairs));
}
Room* RoomBookingSystem::getRoom(const string& pName, int type) const {
        return getRoom(type, Matchers::MatchName(pName));
}
Room* RoomBookingSystem::getRoom(const int pX, const int pY, int type) const {
        return getRoom(type, Matchers::MatchPosition(pX, pY));
}
bool RoomBookingSystem::RoomComparator::operator()(const int i, const int j) {
        bool b1 = rooms[i]->isBooked();
        bool b2 = rooms[j]->isBooked();
        if (b1 && !b2) {
                return i;
        } else if (!b1 && b2) {
                return j;
        } else {
                return rooms[i]->getArea() >= rooms[j]->getArea();
        }
}
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
Lab* RoomBookingSystem::getLabByLeastEquipmentDensity() const {
        double minDensity = DBL_MAX;
        Lab* requiredLab = new Lab("", 0, 0, Position(0, 0), 0);
        for (vector<Room*>::iterator it = labss.begin(); it != labss.end(); it++) {
                if (((Lab*) *it)->getEquipmentDensity() < minDensity && !(*it)->isBooked()) {
                        requiredLab = (Lab*) *it;
                        minDensity = requiredLab->getEquipmentDensity();
                }
        }
        return requiredLab;
}

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

template<class T> Room* RoomBookingSystem::getRoom(int type, const T matcher) const {
        vector<Room*>* vec = getConstList(type);
        vector<Room*>::iterator r = find_if(vec->begin(), vec->end(), matcher);
        return *r;
}

bool RoomBookingSystem::removeRoom(int type, Room* r) {
        vector<Room*>* vec = getList(type);
        if (r != *vec->end()) {
                vec->erase(std::remove(vec->begin(), vec->end(), r), vec->end());
                return true;
        } else
                return false;
}
