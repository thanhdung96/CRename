#include "CRuleRemove.h"

CRuleRemove::CRuleRemove()
{
	position = 0;
	length = 0;
	direction = Direction::Left;
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
	if(fileName.compare("") == 0){
		return "";
	}
	
	makeValid(fileName.size());
	size_t startIndex = 0;
	switch(direction){
		case Direction::Left:
			startIndex = position - length;
			break;
		default:
			startIndex = position;
			break;
	}
	string ret = fileName;
	return ret.erase(startIndex, length);
}

bool CRuleRemove::apply(string& fileName){
	return true;
}

void CRuleRemove::makeValid(size_t fileNameSize){
	if(position < 0){
		position= 0;
	}
	if(position > fileNameSize){
		position = fileNameSize;
	}
	switch(direction){
		// if the lenght makes the removal out of index of string, set it equal to the rest of the string based on direction
		case Direction::Left:
			if(position - length < 0){
				length = position;
			}
			break;
		default:
			if(position + length > fileNameSize){
				length = fileNameSize - position;
			}
			break;
	}
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
