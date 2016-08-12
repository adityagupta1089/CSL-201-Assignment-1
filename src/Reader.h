#include <string>
#include <vector>

#ifndef READER_H_
#define READER_H_

using namespace std;

class Reader {

public:
	//=========================================================================
	// READ FUNCTION
	//=========================================================================
	static vector<vector<string> > read(const char* pFilename, int pColumns);
};

#endif /* READER_H_ */
