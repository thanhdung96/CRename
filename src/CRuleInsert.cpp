#include "CRuleInsert.h"

CRuleInsert::CRuleInsert()
{

}

CRuleInsert::~CRuleInsert()
{

}

void CRuleInsert::setPosition(const unsigned& pos){
	this->position = pos;
}

void CRuleInsert::setText(const string& text){
	this->text = text;
}

void CRuleInsert::apply(string& fileName){

}

string CRuleInsert::preview(const string& fileName){
	return nullptr;
}