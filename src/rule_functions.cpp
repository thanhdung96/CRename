#include "rule_functions.h"

// constructing rule functions
void createRuleInsert(CRuleInsert& insert, bool& status){
	unsigned start;
	cout << "start at: ";
	cin >> start;
	
	// TODO implement set position relativity to inserting rule
	string strStartPositionRelativeTo;
	CRuleRemove::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRuleRemove::Direction::Left;
	}else{
		startPositionRelativeTo = CRuleRemove::Direction::Right;
	}
	
	string insertWhat;
	cout << "insert what: ";
	getline(cin, insertWhat);
	
	insert.setText(insertWhat);
	insert.setPosition(start);
	
	status = true;
}

void createRuleNumbering(CRuleNumber& number, bool& status){
	unsigned start;
	cout << "at: ";
	cin >> start;
	
	string strStartPositionRelativeTo;
	CRuleNumber::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRuleNumber::Direction::Left;
	}else{
		startPositionRelativeTo = CRuleNumber::Direction::Right;
	}

	number.setPositionRelativeTo(start, startPositionRelativeTo);
	
	status = true;
}

void createRuleRemove(CRuleRemove& remove, bool& status){
	unsigned start;
	cout << "start at: ";
	cin >> start;
	
	string strStartPositionRelativeTo;
	CRuleRemove::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRuleRemove::Direction::Left;
	}else{
		startPositionRelativeTo = CRuleRemove::Direction::Right;
	}
	
	unsigned length;
	cout << "number of characters to remove: ";
	cin >> length;
	
	string strRemoveDirection;
	CRuleRemove::Direction removeDirection;
	cout << "from [Left/right]: ";
	getline(cin, strRemoveDirection);
	if(strRemoveDirection.compare("left")){
		removeDirection = CRuleRemove::Direction::Left;
	}else{
		removeDirection = CRuleRemove::Direction::Right;
	}
	
	remove.setPosition(start, startPositionRelativeTo);
	remove.setLength(length);
	remove.setRemoveDirection(removeDirection);
	
	status = true;
}

void createRuleReplace(CRuleReplace& replace, bool& status){
	string findWhat;
	cout << "find what: ";
	getline(cin, findWhat);
	
	string replaceWith;
	cout << "replace with: ";
	getline(cin, replaceWith);
	
	replace.setFindWhat(findWhat);
	replace.setReplaceWith(replaceWith);
	
	status = true;
}

void createRuleSwitchCase(CRuleSwitchCase& switchCase, bool& status){
	string strCase;
	CRuleSwitchCase::StringCase stringCase;
	cout << "convert to: ";
	getline(cin, strCase);
	
	if(strCase.compare("uppercase")){
		stringCase = CRuleSwitchCase::StringCase::Upper_Case;
	}else if(strCase.compare("lowercase")){
		stringCase = CRuleSwitchCase::StringCase::Lower_Case;
	}else if(strCase.compare("propercase")){
		stringCase = CRuleSwitchCase::StringCase::Proper_Case;
	}
	
	switchCase.setChangeCaseTo(stringCase);
	
	status = true;
}

// general rule functions
bool addRule(vector<CRule>* lstRules, AvailableRules chosenRule){
	bool result = false;
	
	switch(chosenRule){
		case AvailableRules::Insert:{
			CRuleInsert insert;
			createRuleInsert(insert, result);
			if(result == true){
				lstRules->push_back(insert);
			}
			else{
				return false;
			}
			break;
		}
		
		case AvailableRules::Numering:{
			CRuleNumber numbering;
			createRuleNumbering(numbering, result);
			if(result == true){
				lstRules->push_back(numbering);
			}
			else{
				return false;
			}
			break;

		}
		case AvailableRules::Remove:{
			CRuleRemove remove;
			createRuleRemove(remove, result);
			if(result == true){
				lstRules->push_back(remove);
			}
			else{
				return false;
			}
			break;
		}
		case AvailableRules::Replace:{
			CRuleReplace replace;
			createRuleReplace(replace, result);
			if(result == true){
				lstRules->push_back(replace);
			}
			else{
				return false;
			}
			break;

		}
		case AvailableRules::SwitchCase:{
			CRuleSwitchCase switchCase;
			createRuleSwitchCase(switchCase, result);
			if(result == true){
				lstRules->push_back(switchCase);
			}
			else{
				return false;
			}
			break;

		}
		default:
			break;
	}

	return true;
}

string ruleShow(vector<CRule>* lstRules, const unsigned& index){
		if (index < 0 || index >= lstRules->size()){
		return "";
	}

	return lstRules->at(index).toString();
}

vector<string>* ruleShowAll(vector<CRule>* lstRules){
	if (lstRules->size() == 0){
		return nullptr;
	}

	vector<string>* lstRuleString = new vector<string>();
	for (unsigned i = 0; i < lstRules->size(); i++){
		lstRuleString->push_back(lstRules->at(i).toString());
	}

	return lstRuleString;
}

bool ruleRemove(vector<CRule>* lstRules, const unsigned& index){
	if (index < 0 || index >= lstRules->size()){
		return false;
	}
	lstRules->erase(lstRules->begin() + index);
	lstRules->shrink_to_fit();
	return true;
}

size_t ruleRemoveAll(vector<CRule>* lstRules){
	size_t totalRemoved = lstRules->size();
	lstRules->clear();
	lstRules->shrink_to_fit();

	return totalRemoved;
}
