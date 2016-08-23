#include "Client.h"

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Lab.h"
#include "LectureHall.h"

#define NAME 1
#define POSITION 2

#define BOOK 1
#define UNBOOK 2

#define CIN_IGNORE_MAX 512

using namespace std;

void Client::printChoices() {
	cout << "Press the corresponding keys for these operations:" << endl;
	cout << "1. Add Room/Lab/Lecture Hall." << endl;
	cout << "2. Remove Room/Lab/Lecture Hall." << endl;
	cout << "3. Book/Unbook a Room/Lab/Lecture Hall." << endl;
	cout << "4. Get minimum number of rooms to accommodate given number of persons." << endl;
	cout << "5. Get smallest lecture hall to accommodate given number of students." << endl;
	cout << "6. Get lab with least equipment density or change lab equipment quantities." << endl;
	cout << "7. Find a room nearest to a location." << endl;
	cout << "8. Print Room/Lab/Lecture Hall details." << endl;
	cout << "9. Exit." << endl;
}
Client::Client() {
	rbs = new RoomBookingSystem();
}
Client::~Client() {
	delete rbs;
}
int Client::getRoomType() {
	cout << ROOMS << ". Room." << endl;
	cout << LABS << ". Lab." << endl;
	cout << LECTURE_HALLS << ". Lecture Hall." << endl;
	int choice = -1;
	while ((choice = input<int>("Enter Choice:")) < ROOMS || choice > LECTURE_HALLS)
		cout << "Please enter valid option." << endl;
	return choice;
}

int Client::getRoomByWhat() {
	cout << "Choose:" << endl;
	cout << NAME << ". By Name." << endl;
	cout << POSITION << ". By Position." << endl;
	int choice = -1;
	while ((choice = input<int>("Enter Choice:")) < NAME || choice > POSITION)
		cout << "Please enter valid option." << endl;
	return choice;
}

void Client::addRoom() {
	int roomType = getRoomType();
	string name = input<string>("Enter Name: ");
	double area = input<double>("Enter Area: ");
	int doors = input<int>("Enter Doors: ");
	int x = input<int>("Enter Position X: ");
	int y = input<int>("Enter Position Y: ");
	switch (roomType) {
		case ROOMS:
			rbs->addRoom(name, area, doors, x, y);
			cout << "Room Added." << endl;
			break;

		case LABS: {
			int computers = input<int>("Enter Computers: ");
			rbs->addLab(name, area, doors, x, y, computers);
		}
			cout << "Lab Added." << endl;
			break;
		case LECTURE_HALLS: {
			int chairs = input<int>("Enter Chairs: ");
			rbs->addLectureHall(name, area, doors, x, y, chairs);
		}
			cout << "Lecture Hall Added." << endl;
			break;
	}
}

void Client::removeRoom() {
	int roomType = getRoomType();
	Room* r = getRoom(roomType);
	if (rbs->removeRoom(roomType, r))
		cout << "Room removed successfully." << endl;
	else
		cout << "Room not removed." << endl;
}

Room* Client::getRoom(int type) {
	switch (getRoomByWhat()) {
		case NAME: {
			string name = input<string>("Enter Name.");
			return rbs->getRoom(name, type);
		}
		case POSITION: {
			int x = input<int>("Enter Position X.");
			int y = input<int>("Enter Position Y.");
			return rbs->getRoom(x, y, type);
		}
	}
	return NULL;
}
void Client::bookUnbook() {
	Room* r = getRoom(getRoomType());
	cout << "This room is " << ((r->isBooked()) ? "booked" : "un-booked") << ". Do you want to " << ((r->isBooked()) ? "un-book" : "book") << " it?" << endl;
	char toggleBook = 'z';
	while (toggleBook != 'y' && toggleBook != 'n') {
		cout << "Enter.(y/n)" << endl;
		cin >> toggleBook;
	}
	if (toggleBook == 'y') {
		if (!r->isBooked()) {
			r->book();
		} else {
			r->unbook();
		}
		cout << "Room successfully " << ((r->isBooked()) ? "booked." : "un-booked.") << endl;
	} else {
		cout << "OK." << endl;
	}
}
void Client::getMinimumRoomsofArea() {
	double area;
	while ((area = input<double>("Enter Area(>0): ")) <= 0)
		;
	vector<Room*> v = rbs->getMinimumRoomsOfArea(area);
	if (v.size() == 0) {
		cout << "Not Enough Rooms." << endl;
		return;
	}
	cout << "You may use these " << v.size() << " un-booked rooms." << endl;
	for (vector<Room*>::iterator it = v.begin(); it != v.end(); it++)
		(*it)->printRoom();
}
void Client::printRoom() {
	int choice = -1;
	while ((choice = input<int>("Enter 1 for specific Room/Lab/Lecture Hall and 2 for all.")) < 1 || choice > 2)
		;
	switch (choice) {
		case 1: {
			int type = getRoomType();
			Room* r = getRoom(type);
			if (type == LABS) {
				((Lab*) r)->printRoom();
			} else if (type == LECTURE_HALLS) {
				((LectureHall*) r)->printRoom();
			} else {
				r->printRoom();
			}
			break;
		}
		case 2:
			rbs->printAll();
			break;
	}
}

void Client::getSmallestLectureHallForGivenStudents() {
	int students;
	while ((students = input<int>("Enter Students (>0): ")) <= 0)
		;
	LectureHall* r = rbs->getSmallestLectureHallByStudents(students);
	if (r->getChairs() > 0) {
		cout << "The required Lecture Hall is:" << endl;
		r->printRoom();
	} else {
		cout << "No such Lecture Hall." << endl;
	}
}
void Client::getLeastEquipmentDensityLab() {
	int choice = -1;
	while ((choice = input<int>("Enter 1 to get the lab with least equipment density and 2 to increase equipment density of a lab.")) < 1 || choice > 2)
		;
	switch (choice) {
		case 1: {
			Room* r = rbs->getLabByLeastEquipmentDensity();
			if (r->getArea() > 0) {
				r->printRoom();
			} else {
				cout << "No such Labs." << endl;
			}
		}
			break;
		case 2: {
			Lab* l = (Lab*) getRoom(LABS);
			cout << "The selected lab is:" << endl;
			l->printRoom();
			int newEqu = -1;
			while ((newEqu = input<int>("Enter the new Lab Equipments.")) < 0)
				;
			l->setComputers(newEqu);
			break;
		}
	}
}
void Client::getNearestRoom() {
	int x = input<int>("Enter Position X:"), y = input<int>("Enter Position Y:");
	Room* r = rbs->getNearestRoom(x, y);
	if (r->getArea() > 0) {
		r->printRoom();
	} else {
		cout << "No such Labs." << endl;
	}
}

template<typename T> T Client::input(const string& s) const {
	T x;
	do {
		cout << s << endl;
		cin >> x;
		if (!cin) {
			cout << "Please enter valid option." << endl;
			cin.clear();
			cin.ignore(CIN_IGNORE_MAX, '\n');
		} else
			break;
	} while (true);
	return x;
}

int main(int argc, char **argv) {
	Client* client = new Client();
	while (true) {
		client->printChoices();
		int choice;
		while (!(cin >> choice) || choice < 1 || choice > 9) {
			cout << "Please choose from 1-9" << endl;
			cin.clear();
			cin.ignore(CIN_IGNORE_MAX, '\n');
		}
		switch (choice) {
			case 1:
				client->addRoom();
				break;
			case 2:
				client->removeRoom();
				break;
			case 3:
				client->bookUnbook();
				break;
			case 4:
				client->getMinimumRoomsofArea();
				break;
			case 5:
				client->getSmallestLectureHallForGivenStudents();
				break;
			case 6:
				client->getLeastEquipmentDensityLab();
				break;
			case 7:
				client->getNearestRoom();
				break;
			case 8:
				client->printRoom();
				break;
			case 9:
				delete client;
				cout << "Exited." << endl;
				exit(0);
				break;
		}
		char cont = 'z';
		while (cont != 'y' && cont != 'n') {
			cout << "Continue?(y/n)" << endl;
			cin >> cont;
		}
		if (cont == 'n') {
			cout << "Exited." << endl;
			delete client;
			exit(0);
			break;
		}

	}
}
