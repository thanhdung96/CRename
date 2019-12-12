#ifndef CRULE_NUMER_H
#define CRULE_NUMER_H

#include "CRule.h"
#include <sstream>

class CRuleNumber : public CRule
{
//public:
//	enum Direction{
//		Left = -1,
//		Right = 1
//	};

	const unsigned INDEX_START = 1;

public:
	CRuleNumber();
	~CRuleNumber();

	string preview(const string& fileName);
	bool apply(string& fileName);
	string toString();

	void resetIndex();
	void setPositionRelativeTo(const unsigned& position, const Direction& direction);

private:
	unsigned position;
	unsigned storedPosition;
	Direction positionRelativeTo;
	unsigned index;

private:
	void makeValid(const unsigned& fileNameSize);
};

#endif
