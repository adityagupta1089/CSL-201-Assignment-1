#ifndef CLIENT_H_
#define CLIENT_H_

#include "RoomBookingSystem.h"

using namespace std;

class Client {

	RoomBookingSystem rbs;
public:
	Client();
	void printChoices();
	int getRoomType();
	int getRoomByWhat();
	void addRoom();
	void getMinimumRoomsofArea();
	void printAll();
	void getSmallestLectureHallForGivenStudents();
	void getNearestRoom();
	template<typename T> void removeRoom();
	template<typename T> void bookUnbook();
	template<typename T> T& getRoom(int type);
};

#endif /* CLIENT_H_ */
