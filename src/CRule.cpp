#include "CRule.h"

CRule::CRule()
{
}

CRule::~CRule()
{
}

/*
*	Leave these methods listed below empty
*/

// method to be derived in inherited classes
string CRule::preview(const string& fileName){
	return nullptr;
}

// method to be derived in inherited classes
void CRule::apply(string& fileName){
	
}

// method to be derived in inherited classes
string* CRule::toString(){
	return nullptr;
}
