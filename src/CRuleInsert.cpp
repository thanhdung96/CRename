#include "CRuleInsert.h"

CRuleInsert::CRuleInsert()
{
	text = "";
	this->position = 0;
	position = 0;
	positionDirectionRelativeTo = Direction::Left;

}

CRuleInsert::~CRuleInsert()
{
}

void CRuleInsert::setPosition(const unsigned& pos, const Direction positionDirectionRelativeTo){
	this->positionDirectionRelativeTo = positionDirectionRelativeTo;
	this->position = position;
	this->storedPosition = position;
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
	//adjusting position to make it in range of string length
	if (position < 0){
		position = 0;
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
}

string CRuleInsert::toString(){
	stringstream ss;
	string temp;
	string str = "insert \"";

	str.append(text);
	str.append("\" at ");
	ss << this->position;
	ss >> temp;
	str.append(temp);

	str.append(" from the ");
	switch (this->positionDirectionRelativeTo)
	{
	case Direction::Right:
		str.append("right");
		break;
	default:
		str.append("left");
		break;
	}

	return str;
}
