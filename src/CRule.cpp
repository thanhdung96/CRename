#include "CRule.h"

CRule::CRule()
{
}

CRule::~CRule()
{
}

// method to be derived in inherited classes
string CRule::preview(const string& fileName){
	return nullptr;
}

// method to be derived in inherited classes
void CRule::apply(string& fileName){
	return;
}