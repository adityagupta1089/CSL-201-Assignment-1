#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Lab.h"
#include "LectureHall.h"
#include "Position.h"
#include "Reader.h"

#include "Functions.h"

#define ROOMS 0
#define LABS 1
#define LECTURE_HALLS 2

#define expand_it (*it)[0], atof((*it)[1].c_str()), atoi((*it)[2].c_str()), Position(atoi((*it)[3].c_str()), atoi((*it)[4].c_str()))
#define sep cout<<"==========================================================="<<endl;

using namespace std;

vector<Room*> rooms;
vector<Room*> labss; //labs = long abs value function
vector<Room*> lectureHalls;

int main(int argc, char** argv) {
	initializeData();
}

void initializeData() {
	vector<vector<string> > roomDetails = Reader::read("data/ROOM.txt", 5);
	vector<vector<string> > labDetails = Reader::read("data/LAB.txt", 6);
	vector<vector<string> > lectureHallDetails = Reader::read("data/LEC.txt",
			6);
	parse(roomDetails, ROOMS);
	parse(labDetails, LABS);
	parse(lectureHallDetails, LECTURE_HALLS);
	printAll();
}

void parse(vector<vector<string> > roomDetails, int type) {
	vector<vector<string> >::iterator it = roomDetails.begin();
	while (it != roomDetails.end()) {
		switch (type) {
		case ROOMS:
			rooms.push_back(new Room(expand_it));
			break;
			case LABS:
			labss.push_back( new Lab(expand_it,atoi((*it)[5].c_str())));
			break;
			case LECTURE_HALLS:
			lectureHalls.push_back( new LectureHall(expand_it,atoi((*it)[5].c_str())));
			break;
		}
		it++;
	}
}

void printAll() {
	sep
	cout << "These are currently " << rooms.size() << " rooms: " << endl;
	for (unsigned i = 0; i < rooms.size(); i++) {
		rooms[i]->printRoom();
	}
	sep
	cout << "These are currently " << labss.size() << " labs: " << endl;
	for (unsigned i = 0; i < labss.size(); i++) {
		labss[i]->printRoom();
	}
	sep
	cout << "These are currently " << lectureHalls.size() << " lectureHalls: "
			<< endl;
	for (unsigned i = 0; i < lectureHalls.size(); i++) {
		lectureHalls[i]->printRoom();
	}
	sep
}
