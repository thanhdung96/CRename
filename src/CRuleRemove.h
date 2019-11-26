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

	void setRemoveDirection(Direction direction);	//set direction for removal
	void setPosition(const unsigned& position, const Direction positionDirectionRelativeTo);
	void setLength(const size_t& length);

	string preview(const string& fileName);
	bool apply(string& fileName);
	string* toString();

private:
	unsigned position;
	unsigned storedPosition;	//used to cache user input position to restore when position is changed in makeValid
	size_t length;
	Direction direction;
	Direction positionDirectionRelativeTo;
	
private:
	void makeValid(size_t fileNameSize);
};
#endif
