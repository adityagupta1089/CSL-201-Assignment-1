#include <iterator>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

#include "Reader.h"
#include "Room.h"
#include "Functions.h"

using namespace std;

vector<Room*> rooms;
vector<Room*> labss; //labs = long abs value function
vector<Room*> lectureHalls;

int main(int argc, char** argv) {
	initializeData();
}

void initializeData() {
	vector<vector<string> > roomDetails = Reader::read("data/ROOM.txt", 5);
	vector<vector<string> > labDetails = Reader::read("data/LAB.txt", 7);
	vector<vector<string> > lectureHallDetails = Reader::read("data/LEC.txt",
			6);
	rooms = parse(roomDetails);
	labss = parse(labDetails);
	lectureHalls = parse(lectureHallDetails);
	print(rooms);
	print(labss); //TODO fix missing entries
	print(lectureHalls);
}

vector<Room*> parse(vector<vector<string> > roomDetails) {
	vector<Room*> rooms;
	vector<vector<string> >::iterator it = roomDetails.begin();
	while (it != roomDetails.end()) {
		rooms.push_back( //TODO individual parser
				new Room((*it)[0], atof((*it)[1].c_str()),
						atoi((*it)[2].c_str()),
						Position(atoi((*it)[3].c_str()),
								atoi((*it)[4].c_str()))));
		it++;
	}
	return rooms;
}

void print(vector<Room*> rooms) {
	for (unsigned int i = 0; i < rooms.size(); i++) {
		Room r = *rooms[i];
		cout << r.name << " " << r.area << " " << r.doors << " " << r.position.x
				<< " " << r.position.y << endl;
	}
}
