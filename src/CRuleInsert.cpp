#include "CRuleInsert.h"

CRuleInsert::CRuleInsert()
{
	this->text = new string("");
	this->position = 0;
}

CRuleInsert::~CRuleInsert()
{
	delete this->text;
}

void CRuleInsert::setPosition(const unsigned& pos){
	this->position = pos;
}

void CRuleInsert::setText(string* text){
	this->text = text;
}

void CRuleInsert::apply(string& fileName){
	if (this->text == nullptr && this->text->compare("") == 0){	// if string is null or empty
		// TODO implement processing file name based on rule definition
	}
	else{
		// TODO implement processing file name based on rule definition
	}
}

string CRuleInsert::preview(const string& fileName){
	if (this->text == nullptr && this->text->compare("") == 0){	// if string is null or empty
		return nullptr;
	}
	else{
		// TODO implement processing file name based on rule definition
		return nullptr;
	}
}

string* CRuleInsert::toString(){
	stringstream ss;
	string temp;
	string* str = new string("insert \"");

	str->append(*(this->text));
	str->append("\" at ");
	ss << this->position;
	ss >> temp;
	str->append(temp);

	return str;
}
