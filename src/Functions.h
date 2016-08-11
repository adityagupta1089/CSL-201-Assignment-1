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

vector<Room> parse(string (&pColumns));
void initializeData();
vector<Room*> parse(vector<vector<string> > roomDetails);
void print(vector<Room*> rooms);

#endif /* FUNCTIONS_H_ */
