#ifndef MATCHERS_H_
#define MATCHERS_H_

#include <string>

#include "Position.h"
#include "Room.h"

using namespace std;

class Matchers {
	public:
		struct MatchName {
				MatchName(const string& s);
				bool operator()(const Room* r) const;
			private:
				const string& name;
		};
		struct MatchPosition {
				MatchPosition(const int pX, const int pY);
				bool operator()(const Room* r) const;
			private:
				const int x;
				const int y;
		};
};

#endif /* MATCHERS_H_ */
