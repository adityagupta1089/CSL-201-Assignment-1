#include <string>

#include "Lab.h"
#include "LectureHall.h"
#include "RoomBookingSystem.h"

using namespace std;

int main(int argc, char **argv) {
	//printAll();
	RoomBookingSystem rbs = *new RoomBookingSystem();
	vector<Room> v = rbs.getMinimumRoomsOfArea(50000);
	for (vector<Room>::iterator it = v.begin(); it != v.end(); it++)
		it->printRoom();
}
