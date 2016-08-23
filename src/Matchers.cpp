#include "Matchers.h"

using namespace std;
Matchers::MatchName::MatchName(const string& s) :
		name(s) {
}
bool Matchers::MatchName::operator()(const Room* r) const {
	return r->getName() == name;
}
Matchers::MatchPosition::MatchPosition(const int pX, const int pY) :
		x(pX), y(pY) {
}
bool Matchers::MatchPosition::operator()(const Room* r) const {
	return r->getPosition().x == x && r->getPosition().y == y;
}

