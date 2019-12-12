#include "CRuleReplace.h"


CRuleReplace::CRuleReplace()
{
	findWhat = "";
	replaceWith = "";
}

CRuleReplace::~CRuleReplace()
{
}

void CRuleReplace::setFindWhat(const string& findWhat){
	this->findWhat = findWhat;
}

void CRuleReplace::setReplaceWith(const string& replaceWith){
	this->replaceWith = replaceWith;
}

string CRuleReplace::preview(const string& fileName){
	if (fileName.compare("") == 0){
		return "";
	}

	string ret = fileName;
	boost::replace_all(ret, this->findWhat, this->replaceWith);
	return ret;
}

bool CRuleReplace::apply(string& fileName){
	if (fileName.compare("") == 0){
		return false;
	}

	boost::replace_all(fileName, this->findWhat, this->replaceWith);

	return true;
}

string CRuleReplace::toString(){
	string ret = "replace \"";
	ret.append(this->findWhat);
	ret.append("\" with \"");
	ret.append(this->replaceWith);
	ret.append("\"");

	return ret;
}
