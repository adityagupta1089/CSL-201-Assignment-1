/*
 * Reader.h
 *
 *  Created on: 10-Aug-2016
 *      Author: aditya
 */

#include <string>
#include <vector>

#ifndef READER_H_
#define READER_H_

using namespace std;

class Reader {
public:
	static vector<vector<string> > read(const char* pFilename, int pColumns);
};

#endif /* READER_H_ */
