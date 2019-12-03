#include "CRuleNumber.h"

CRuleNumber::CRuleNumber()
{
	this->position = 0;
	this->storedPosition = 0;
	this->positionRelativeTo = Direction::Left;
	this->index = INDEX_START;
}

CRuleNumber::~CRuleNumber()
{
}

string CRuleNumber::preview(const string& fileName){
	if (fileName.compare("") == 0){
		return "";
	}

	string ret = fileName;
	stringstream stringStream;
	stringStream << index;
	string strIndex;
	stringStream >> strIndex;
	makeValid(ret.size());

	ret.insert(position, strIndex);
	index++;

	return ret;
}

bool CRuleNumber::apply(string& fileName){
	if (fileName.compare("") == 0){
		return false;
	}

	stringstream stringStream;
	stringStream << index;
	string strIndex;
	stringStream >> strIndex;
	makeValid(fileName.size());

	fileName.insert(position, strIndex);
	index++;

	return true;
}

string CRuleNumber::toString(){
	string ret = "insert index at ";

	stringstream stringStream;
	stringStream << position;
	string temp;
	stringStream >> temp;
	ret.append(temp);

	ret.append(" characters away from the ");

	switch (positionRelativeTo)
	{
	case CRuleNumber::Left:
		ret.append("left");
		break;
	case CRuleNumber::Right:
		ret.append("right");
		break;
	default:
		break;
	}

	return ret;
}

void CRuleNumber::resetIndex(){
	this->index = INDEX_START;
}

void CRuleNumber::setPositionRelativeTo(const unsigned& position, const Direction& direction){
	this->position = position;
	this->storedPosition = position;
	this->positionRelativeTo = direction;
}

void CRuleNumber::makeValid(const unsigned& fileNameSize){
	//adjusting position to make it in range of string length
	if (position < 0){
		position = 0;
	}
	else if (position > fileNameSize){
		position = fileNameSize;
	}
	else{
		//if position relative to the left, do nothing
		// else convert it to position relative to the left
		position = positionRelativeTo == Direction::Right ? fileNameSize - storedPosition : storedPosition;
	}
}
