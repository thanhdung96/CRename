#include "CRuleRemove.h"

CRuleRemove::CRuleRemove()
{
}

CRuleRemove::~CRuleRemove()
{
}

void CRuleRemove::setDirection(CRuleRemove::Direction direction){
	this->direction = direction;
}

void CRuleRemove::setLength(const size_t& length){
	this->length = length;
}

void CRuleRemove::setPosition(const unsigned& position){
	this->position = position;
}

string CRuleRemove::preview(const string& fileName){
	// TODO implement processing file name based on rule definition
	return nullptr;
}

void CRuleRemove::apply(string& fileName){
	// TODO implement processing file name based on rule definition
}

string* CRuleRemove::toString(){
	string* str = new string("remove ");
	string temp;
	stringstream ss;

	ss << this->length;
	ss >> temp;
	str->append(temp);
	str->append(" characters to the ");
	switch (this->direction)
	{
	case CRuleRemove::Direction::Right:
		str->append("right");
		break;
	default:
		str->append("left");
		break;
	}
	str->append(" from position ");
	ss << this->position;
	ss >> temp;
	str->append(temp);

	return str;
}
