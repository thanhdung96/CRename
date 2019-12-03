#include "rule_functions.h"

// constructing rule functions
void createRuleInsert(CRuleInsert* insert, bool& status){
	unsigned start;
	string strStart;
	cout << "start at: ";
	//cin >> start;
	getline(cin, strStart);
	start = stoul(strStart);
	
	// TODO implement set position relativity to inserting rule
	string strStartPositionRelativeTo;
	CRuleInsert::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRule::Direction::Left;
	}else{
		startPositionRelativeTo = CRule::Direction::Right;
	}
	
	string insertWhat;
	cout << "insert what: ";
	getline(cin, insertWhat);
	
	insert->setText(insertWhat);
	insert->setPosition(start, startPositionRelativeTo);
	
	status = true;
}

void createRuleNumbering(CRuleNumber* number, bool& status){
	unsigned start;
	string strStart;
	cout << "start at: ";
	//cin >> start;
	getline(cin, strStart);
	start = stoul(strStart);

	string strStartPositionRelativeTo;
	CRuleNumber::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRule::Direction::Left;
	}else{
		startPositionRelativeTo = CRule::Direction::Right;
	}

	number->setPositionRelativeTo(start, startPositionRelativeTo);
	
	status = true;
}

void createRuleRemove(CRuleRemove* remove, bool& status){
	unsigned start;
	string strStart;
	cout << "start at: ";
	//cin >> start;
	getline(cin, strStart);
	start = stoul(strStart);

	string strStartPositionRelativeTo;
	CRuleRemove::Direction startPositionRelativeTo;
	cout << "from [Left/right]: ";
	getline(cin, strStartPositionRelativeTo);
	if(strStartPositionRelativeTo.compare("left")){
		startPositionRelativeTo = CRule::Direction::Left;
	}else{
		startPositionRelativeTo = CRule::Direction::Right;
	}
	
	unsigned length;
	cout << "number of characters to remove: ";
	cin >> length;
	
	string strRemoveDirection;
	CRule::Direction removeDirection;
	cout << "from [Left/right]: ";
	getline(cin, strRemoveDirection);
	if(strRemoveDirection.compare("left")){
		removeDirection = CRule::Direction::Left;
	}else{
		removeDirection = CRule::Direction::Right;
	}
	
	remove->setPosition(start, startPositionRelativeTo);
	remove->setLength(length);
	remove->setRemoveDirection(removeDirection);
	
	status = true;
}

void createRuleReplace(CRuleReplace* replace, bool& status){
	string findWhat;
	cout << "find what: ";
	getline(cin, findWhat);
	
	string replaceWith;
	cout << "replace with: ";
	getline(cin, replaceWith);
	
	replace->setFindWhat(findWhat);
	replace->setReplaceWith(replaceWith);
	
	status = true;
}

void createRuleSwitchCase(CRuleSwitchCase* switchCase, bool& status){
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
	
	switchCase->setChangeCaseTo(stringCase);
	
	status = true;
}

// general rule functions
bool addRule(vector<CRule*>* lstRules, AvailableRules chosenRule){
	bool result = false;
	
	switch(chosenRule){
		case AvailableRules::Insert:{
			CRuleInsert* insert = new CRuleInsert;
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
			CRuleNumber* numbering = new CRuleNumber;
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
			CRuleRemove* remove = new CRuleRemove;
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
			CRuleReplace* replace = new CRuleReplace;
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
			CRuleSwitchCase* switchCase = new CRuleSwitchCase;
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

string ruleShow(vector<CRule*>* lstRules, const unsigned& index){
		if (index < 0 || index >= lstRules->size()){
		return "";
	}

	return lstRules->at(index)->toString();
}

vector<string>* ruleShowAll(vector<CRule*>* lstRules){
	if (lstRules->size() == 0){
		return nullptr;
	}

	vector<string>* lstRuleString = new vector<string>();
	for (unsigned i = 0; i < lstRules->size(); i++){
		lstRuleString->push_back(lstRules->at(i)->toString());
	}

	return lstRuleString;
}

bool ruleRemove(vector<CRule*>* lstRules, const unsigned& index){
	if (index < 0 || index >= lstRules->size()){
		return false;
	}

	CRule* ruleToDelete = lstRules->at(index);
	lstRules->erase(lstRules->begin() + index);
	delete ruleToDelete;
	lstRules->shrink_to_fit();
	return true;
}

size_t ruleRemoveAll(vector<CRule*>* lstRules){
	size_t totalRemoved = lstRules->size();

	for (int i = 0; i< lstRules->size(); i++)
	{
		delete lstRules->at(i);
	}
	lstRules->clear();
	lstRules->shrink_to_fit();

	return totalRemoved;
}
