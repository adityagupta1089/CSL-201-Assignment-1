#ifndef CLIENT_H_
#define CLIENT_H_

#include "RoomBookingSystem.h"

using namespace std;

class Client {

		RoomBookingSystem* rbs;

		int getRoomType();
		int getRoomByWhat();
		Room* getRoom(int type);
		template<typename T> T input(const string& s) const;

	public:

		Client();
		~Client();
		void printChoices();
		void addRoom();
		void getMinimumRoomsofArea();
		void printRoom();
		void getSmallestLectureHallForGivenStudents();
		void getLeastEquipmentDensityLab();
		void getNearestRoom();
		void removeRoom();
		void bookUnbook();
};

#endif /* CLIENT_H_ */
