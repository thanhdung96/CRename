#include "CRuleInsert.h"

CRuleInsert::CRuleInsert()
{
	text = "";
	this->position = 0;
}

CRuleInsert::~CRuleInsert()
{
}

void CRuleInsert::setPosition(const unsigned& pos){
	this->position = pos;
}

void CRuleInsert::setText(string& newText){
	text = newText;
}

bool CRuleInsert::apply(string& fileName){
	if (text.compare("") == 0){	// if string is null or empty
		return false;
	}
	else{
		makeValid(fileName.size());
		fileName.insert(position, (this->text));
		return true;
	}
}

string CRuleInsert::preview(const string& fileName){
	if (text.compare("") == 0){	// if string is null or empty
		return "";
	}
	else{
		makeValid(fileName.size());
		string ret = fileName;
		ret.insert(position, (this->text));
		return ret;
	}
}

// make rule configuration valid for each file name applied
void CRuleInsert::makeValid(unsigned fileNameSize) {
	if(position < 0){
		position = 0;
	}
	if(position > fileNameSize){
		position = fileNameSize;
	}
}

string* CRuleInsert::toString(){
	stringstream ss;
	string temp;
	string* str = new string("insert \"");

	str->append(text);
	str->append("\" at ");
	ss << this->position;
	ss >> temp;
	str->append(temp);

	return str;
}
