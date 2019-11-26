#ifndef CRULE_SWITCH_CASE_H
#define CRULE_SWITCH_CASE_H

#include "CRule.h"
#include "utilities.h"
#include <boost\algorithm\string\case_conv.hpp>
#include <sstream>
#include <vector>

class CRuleSwitchCase :public CRule
{
public:
	enum StringCase{
		Upper_Case,
		Lower_Case,
		Proper_Case
	};

public:
	CRuleSwitchCase();
	~CRuleSwitchCase();
	string preview(const string& fileName);
	bool apply(string& fileName);
	string* toString();

	void setChangeCaseTo(const StringCase& strCase);

private:
	StringCase strCase;

private:
	void doSwitchCase(string& fileName);
	void convertToUpperCase(string& fileName);
	void convertToLowerCase(string& fileName);
	void convertToProperCase(string& fileName);
};

#endif