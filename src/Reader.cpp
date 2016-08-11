/*
 * Reader.cpp
 *
 *  Created on: 10-Aug-2016
 *      Author: aditya
 */

#include "Reader.h"

#include <fstream>

using namespace std;

vector<vector<string> > Reader::read(const char* pFilename, int pColumns) {
	ifstream inputStream;
	vector<vector<string> > rooms;
	inputStream.open(pFilename);
	if (inputStream.is_open()) {
		while (!inputStream.eof()) {
			vector<string> roomDetails;
			for (int i = 0; i < pColumns; i++) {
				string detail;
				inputStream >> detail;
				roomDetails.push_back(detail);
			}
			rooms.push_back(roomDetails);
		}
	}
	inputStream.close();
	return rooms;
}

