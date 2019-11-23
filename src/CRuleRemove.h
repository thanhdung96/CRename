#ifndef CRULE_REMOVE_H
#define CRULE_REMOVE_H

#include <string>
#include <sstream>
#include "CRule.h"
using namespace std;

class CRuleRemove :public CRule
{
public:
	enum Direction{
		Left = -1,
		Right = 1
	};

public:
	CRuleRemove();
	~CRuleRemove();

	void setDirection(Direction direction);
	void setPosition(const unsigned& position);
	void setLength(const size_t& length);

	string preview(const string& fileName);
	bool apply(string& fileName);
	string* toString();

private:
	unsigned position;
	size_t length;
	Direction direction;
};
#endif
