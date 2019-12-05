#include "CRuleRemove.h"

CRuleRemove::CRuleRemove()
{
	position = 0;
	storedPosition = 0;
	length = 0;
	direction = Direction::Right;
	positionDirectionRelativeTo = Direction::Left;
}

CRuleRemove::~CRuleRemove()
{
}

void CRuleRemove::setRemoveDirection(Direction direction){
	this->direction = direction;
}

void CRuleRemove::setLength(const size_t& length){
	this->length = length;
}

void CRuleRemove::setPosition(const unsigned& position, const Direction positionDirectionRelativeTo){
	this->positionDirectionRelativeTo = positionDirectionRelativeTo;
	this->position = position;
	this->storedPosition = position;
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
	if (fileName.compare("") == 0){
		return false;
	}

	makeValid(fileName.size());
	size_t startIndex = 0;
	switch (direction){
	case Direction::Left:
		startIndex = position - length;
		break;
	default:
		startIndex = position;
		break;
	}
	fileName.erase(startIndex, length);

	return true;
}

void CRuleRemove::makeValid(size_t fileNameSize){
	//adjusting position to make it in range of string length
	if(position < 0){
		position= 0;
	}
	else if (position > fileNameSize){
		//position = fileNameSize;
		position = positionDirectionRelativeTo == Direction::Right ? fileNameSize - storedPosition : storedPosition;
	}
	else{
		//if position relative to the left, do nothing
		// else convert it to position relative to the left
		position = positionDirectionRelativeTo == Direction::Right ? fileNameSize - storedPosition : storedPosition;
	}

	switch(direction){
		//adjusting length value
		// if the length makes the removal out of index of string, set it equal to the rest of the string based on direction
		case Direction::Left:
			if(((int)position - (int)length) < 0){
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

string CRuleRemove::toString(){
	string str = "remove ";
	string temp;
	stringstream ss;

	ss << this->length;
	ss >> temp;
	str.append(temp);
	str.append(" characters to the ");
	switch (this->direction)
	{
	case Direction::Right:
		str.append("right");
		break;
	default:
		str.append("left");
		break;
	}
	str.append(" from position ");
	ss << this->position;
	ss >> temp;
	str.append(temp);

	return str;
}
