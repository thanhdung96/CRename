#ifndef CRULE_REPLACE_H
#define CRULE_REPLACE_H

#include "CRule.h"
#include <boost\algorithm\string\replace.hpp>

class CRuleReplace: public CRule
{
public:
	CRuleReplace();
	~CRuleReplace();

	string preview(const string& fileName);
	bool apply(string& fileName);
	string* toString();
	void setFindWhat(const string& findWhat);
	void setReplaceWith(const string& replaceWith);

private:
	string findWhat;
	string replaceWith;
};

#endif