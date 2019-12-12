#ifndef CRULE_INSERT_H
#define CRULE_INSERT_H

#include <string>
#include <sstream>
#include "CRule.h"
using namespace std;

class CRuleInsert : public CRule
{
public:
	CRuleInsert();
	~CRuleInsert();

	void setPosition(const unsigned& pos, const Direction positionDirectionRelativeTo);
	void setText(string& newText);
	string preview(const string& fileName);
	bool apply(string& fileName);
	string toString();

private:
	unsigned storedPosition;	//used to cache user input position to restore when position is changed in makeValid
	unsigned position;
	string text;
	Direction positionDirectionRelativeTo;
	
private:
	void makeValid(unsigned fileNameSize);
};

#endif
