#include "CRuleSwitchCase.h"

CRuleSwitchCase::CRuleSwitchCase()
{
	this->strCase = StringCase::Lower_Case;
}

CRuleSwitchCase::~CRuleSwitchCase()
{
}


string CRuleSwitchCase::preview(const string& fileName){
	if (fileName.compare("") == 0){
		return "";
	}

	string ret = fileName;
	doSwitchCase(ret);
	return ret;
}

bool CRuleSwitchCase::apply(string& fileName){
	if (fileName.compare("") == 0){
		return false;
	}

	doSwitchCase(fileName);
	return true;
}

string CRuleSwitchCase::toString(){
	string ret = "convert to ";
	switch (strCase)
	{
	case StringCase::Lower_Case:
		ret.append("lower case");
		break;
	case StringCase::Upper_Case:
		ret.append("upper case");
		break;
	default:
		ret.append("proper case");
		break;
	}
	return ret;
}

void CRuleSwitchCase::setChangeCaseTo(const StringCase& strCase){
	this->strCase = strCase;
}

void CRuleSwitchCase::doSwitchCase(string& fileName){
	switch (this->strCase)
	{
	case CRuleSwitchCase::Upper_Case:
		convertToUpperCase(fileName);
		break;
	case CRuleSwitchCase::Lower_Case:
		convertToLowerCase(fileName);
		break;
	case CRuleSwitchCase::Proper_Case:
		convertToProperCase(fileName);
		break;
	default:
		break;
	}
}

void CRuleSwitchCase::convertToUpperCase(string& fileName){
	boost::to_upper(fileName);
}

void CRuleSwitchCase::convertToLowerCase(string& fileName){
	boost::to_lower(fileName);
}

void CRuleSwitchCase::convertToProperCase(string& fileName){
	vector<string> splitString;
	stringstream stringStream(fileName);
	string temp;

	while (getline(stringStream, temp, ' ')){
		splitString.push_back(temp);
	}

	for (size_t i = 0; i < splitString.size(); i++){
		string& str = splitString[i];
		if (str[0] <= 122 && str[0] >= 97){ //if first character of each word is lowercase, convert to uppercase
			str[0] = str[0] - 32;	// based on ascii table
		}
	}
	fileName = joinStrings(splitString, ' ');
}
