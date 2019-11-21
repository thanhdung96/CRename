#ifndef CRULE_INSERT_H
#define CRULE_INSERT_H

#include <string>
#include "CRule.h"
using namespace std;

class CRuleInsert : public CRule
{
public:
	CRuleInsert();
	~CRuleInsert();

	void setPosition(const unsigned& pos);
	void setText(const string& newText);
	string preview(const string& fileName);
	void apply(string& fileName);

private:
	unsigned position;
	string text;
};

#endif