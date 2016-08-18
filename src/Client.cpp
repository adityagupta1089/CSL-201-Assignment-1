#include "Client.h"

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Lab.h"
#include "LectureHall.h"

using namespace std;

//=========================================================================
// UI
//=========================================================================

void Client::printChoices() {
	cout << "Press the corresponding keys for these operations:" << endl;
	cout << "1. Add Room/Lab/Lecture Hall." << endl;
	cout << "2. Remove Room/Lab/Lecture Hall." << endl;
	cout << "3. Book/Unbook a Room/Lab/Lecture Hall." << endl;
	cout
			<< "4. Get minimum number of rooms to accommodate given number of persons."
			<< endl;
	cout
			<< "5. Get smallest lecture hall to accommodate given number of students."
			<< endl;
	cout << "6. Get lab with least equipment density." << endl;
	cout << "7. Find a room nearest to a location." << endl;
	cout << "8. Print all details." << endl;
	cout << "9. Exit." << endl;
}
//=========================================================================
// CONSTRUCTOR
//=========================================================================
Client::Client() {
	rbs = *new RoomBookingSystem();
}
//=========================================================================
// HELPER FUNCTIONS
//=========================================================================
int Client::getRoomType() {
	cout << "Choose:" << endl;
	cout << "1. Room." << endl;
	cout << "2. Lab." << endl;
	cout << "3. Lecture Hall." << endl;
	int choice;
	cin >> choice;
	return choice;
}

int Client::getRoomByWhat() {
	cout << "Choose:" << endl;
	cout << "1. By Name." << endl;
	cout << "2. By Position." << endl;
	int choice;
	cin >> choice;
	return choice;
}

void Client::addRoom() {
	int roomType = getRoomType();

	string name;
	double area;
	int doors;
	int x, y;
	cout << " Enter Name:" << endl;
	cin >> name;
	cout << " Enter Area:" << endl;
	cin >> area;
	cout << " Enter Doors:" << endl;
	cin >> doors;
	cout << " Enter Position X:" << endl;
	cin >> x;
	cout << " Enter Position Y:" << endl;
	cin >> y;
	switch (roomType) {
	case 1:
		rbs.addRoom(name, area, doors, x, y);
		break;
	case 2:
		int computers;
		cin >> computers;
		rbs.addLab(name, area, doors, x, y, computers);
		break;
	case 3:
		int chairs;
		cin >> chairs;
		rbs.addLab(name, area, doors, x, y, chairs);
		break;
	}
}

template<typename T> void Client::removeRoom() {
//	int roomType = getRoomType();
//	int getRoomBy = getRoomByWhat();
//	T r = getRoom(roomType);
//	switch (roomType) {
//	case 1:
//		if (getRoomBy == 1)
//			rbs.removeRoom(r);
//		break;
//	case 2:
//		if (getRoomBy == 1)
//			rbs.removeLab(r);
//		break;
//	case 3:
//		if (getRoomBy == 1)
//			rbs.removeLectureHall(r);
//		break;
//	}
}

template<typename T> T& Client::getRoom(int type) {
	string name;
	int x, y;
	switch (getRoomByWhat()) {
	case 1:
		cout << "Enter Name." << endl;
		cin >> name;
		switch (type) {
		case 1:
			return rbs.getRoom(name);
		case 2:
			return rbs.getLab(name);
		case 3:
			return rbs.getLectureHall(name);
		}
		break;
	case 2:
		cout << "Enter Position X." << endl;
		cin >> x;
		cout << "Enter Position Y." << endl;
		cin >> y;
		switch (type) {
		case 1:
			return rbs.getRoom(x, y);
		case 2:
			return rbs.getLab(x, y);
		case 3:
			return rbs.getLectureHall(x, y);
		}
		break;
	}

}
template<typename T> void Client::bookUnbook() {
	int roomType = getRoomType();
	cout << "Choose:" << endl;
	cout << "1.Book." << endl;
	cout << "2.UnBook." << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
	} else {

	}
}
void Client::getMinimumRoomsofArea() {
	double area;
	cout << "Enter Area:" << endl;
	cin >> area;
	vector<Room> v = rbs.getMinimumRoomsOfArea(area);
	for (vector<Room>::iterator it = v.begin(); it != v.end(); it++)
		it->printRoom();
}
void Client::printAll() {
	rbs.printAll();
}
void Client::getSmallestLectureHallForGivenStudents() {
	int students;
	cout << "Enter Students:" << endl;
	cin >> students;
	LectureHall lh = *rbs.getSmallestLectureHallByStudents(students);
	lh.printRoom();
}
void Client::getNearestRoom() {
	int x, y;
	cout << "Enter Position X:" << endl;
	cin >> x;
	cout << "Enter Position Y:" << endl;
	cin >> y;
	Room r = *rbs.getNearestRoom(x, y);
	r.printRoom();
}
//=========================================================================
// MAIN
//=========================================================================
//TODO add checks
//TODO testing
int main(int argc, char **argv) {
	Client client = *new Client();
	while (true) {
		client.printChoices();
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			client.addRoom();
			break;
		case 2:
			//client.removeRoom(); TODO remove room
			break;
		case 3:
			//client.bookUnbook(); TODO book/unbook room
			break;
		case 4:
			client.getMinimumRoomsofArea();
			break;
		case 5:
			client.getSmallestLectureHallForGivenStudents();
			break;
		case 6:
			client.getMinimumRoomsofArea();
			break;
		case 7:
			client.getNearestRoom();
			break;
		case 8:
			client.printAll();
			break;
		case 9:
			exit(0);
			break;
		}
		cout << "Continue?(y/n)" << endl;
		char cont;
		cin >> cont;
		if (cont == 'n')
			break;
	}
}
