/*
 * functions.h
 *
 *  Created on: 10-Aug-2016
 *      Author: aditya
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include <vector>

#include "Room.h"

using namespace std;

void initializeData();
void parse(vector<vector<string> > roomDetails, int type);
void addRoom(); //TODO
void removeRoom(); //TODO
void bookRoom(); //TODO
void unbookRoom(); //TODO
void getLectureHall(); //TODO
void getLab(); //TODO
void increaseEquipment(); //TODO
void getNearestRoom(); //TODO
void printAll(); //TODO
void fluhInfo(); //TODO
//TODO function overloading, operator overloading, virtual functions, function templates

#endif /* FUNCTIONS_H_ */
