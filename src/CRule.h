#ifndef CRULE_H
#define CRULE_H

#include <string>
using namespace std;

class CRule
{
public:
	CRule();
	~CRule();

	virtual string preview(const string& fileName);
	virtual void apply(string& fileName);

private:
};

#endif