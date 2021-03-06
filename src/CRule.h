#ifndef CRULE_H
#define CRULE_H

#include <string>
using namespace std;

class CRule
{
public:
	enum Direction{
		Left = -1,
		Right = 1
	};

public:
	CRule();
	virtual ~CRule();

	virtual string preview(const string& fileName);
	virtual bool apply(string& fileName);
	virtual string toString();

private:
};

#endif
