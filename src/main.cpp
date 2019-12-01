#include <iostream>

#ifdef IS_LINUX
	#include <boost/algorithm/string/trim_all.hpp>
#else
	#include <boost\algorithm\string\trim_all.hpp>
#endif

#include "file_functions.h"
#include "rule_functions.h"
#include "utilities.h"
#include "common.h"
#include "constants.h"
using namespace std;

bool isExit = false;

void menuFileActions(){
	string pth;
	switch (intParsedPrompt[1])
	{
	case INT_MENU_ACTION_IMPORT:{	//import a directory
		unsigned count = 0;
		cout << IMPORT_PROMPT;
		getline(cin, pth);
		if (!fileImportDirectory(&lstFiles, pth, count)){
			cout << IMPORT_DIRECTORY_FAILED;
		}
		else{
			if (count == 0){
				cout << "empty directory.\n";
			}
			else{
				cout << "imported " << count << " files.\n";
			}
		}
		pth = "";	//reset path for next import or addition
		break;
	}

	case INT_MENU_ACTION_ADD:{		//add a file
		cout << IMPORT_PROMPT;
		getline(cin, pth);
		if (!addFile(&lstFiles, pth)){
			cout << ADD_FILE_FAILED;
		}
		cout << "added 1 file.\n";
		pth = "";	//reset path for next import or addition
		break;
	}

	case INT_MENU_ACTION_REMOVE:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			size_t totalRemoved = fileRemoveAll(&lstFiles);
			cout << totalRemoved << " file(s) removed.\n";
		}
		else{
			if (fileRemove(&lstFiles, intParsedPrompt[2])){
				cout << "[" << intParsedPrompt[2] << "] removed.\n";
			}
		}
		break;
	}

	case INT_MENU_ACTION_SHOW:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			vector<string>* lstFileStrings = fileShowAll(&lstFiles);
			if (lstFileStrings == nullptr){
				cout << "no files imported.\n";
			}
			else{
				for (unsigned i = 0; i < lstFileStrings->size(); i++){
					cout << "[" << i << "] " << lstFileStrings->at(i) << "\n";
				}
				delete lstFileStrings;
			}
		}
		else{
			string f = fileShow(&lstFiles, intParsedPrompt[2]);
			if (f.compare("") == 0){
				cout << "file index out of range.\n";
			}
			else{
				cout << "[" << intParsedPrompt[2] << "] " << f << "\n";
			}
		}
		break;
	}

	default:
		break;
	}
}

void menuRuleActions(){
	switch (intParsedPrompt[1])
	{
	case INT_MENU_ACTION_ADD:{		//add a rule
		AvailableRules chosenRule;
		string strChosenRule;
		switch(intParsedPrompt[2]){
			case INT_RULE_INSERT:
				chosenRule = AvailableRules::Insert;
				strChosenRule = "insert rule";
				break;
			case INT_RULE_NUMBERING:
				chosenRule = AvailableRules::Numering;
				strChosenRule = "numbering rule";
				break;
			case INT_RULE_REMOVE:
				chosenRule = AvailableRules::Remove;
				strChosenRule = "removing rule";
				break;
			case INT_RULE_REPLACE:
				chosenRule = AvailableRules::Replace;
				strChosenRule = "replacing rule";
				break;
			case INT_RULE_CASE_SWITCH:
				chosenRule = AvailableRules::SwitchCase;
				strChosenRule = "switching case rule";
				break;
		}
		
		if(addRule(&lstRules, chosenRule) == true){
			cout << strChosenRule << " added.\n";
		} else{
			cout << "rule addition aborted.\n";
		}
		break;
	}
		
	case INT_MENU_ACTION_REMOVE:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			size_t totalRemoved = ruleRemoveAll(&lstRules);
			cout << totalRemoved << " rule(s) removed.\n";
		}
		else{
			if (ruleRemove(&lstRules, intParsedPrompt[2])){
				cout << "[" << intParsedPrompt[2] << "] removed.\n";
			}
		}
		break;
	}
	
	case INT_MENU_ACTION_SHOW:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			vector<string>* lstRuleStrings = ruleShowAll(&lstRules);
			if (lstRuleStrings == nullptr){
				cout << "no rules created.\n";
			}
			else{
				for (unsigned i = 0; i < lstRuleStrings->size(); i++){
					cout << "[" << i << "] " << lstRuleStrings->at(i) << "\n";
				}
				delete lstRuleStrings;
			}
		}
		else{
			string r = ruleShow(&lstRules, intParsedPrompt[2]);
			if (r.compare("") == 0){
				cout << "rule index out of range.\n";
			}
			else{
				cout << "[" << intParsedPrompt[2] << "] " << r << "\n";
			}
		}
		break;
	}
		
	default:
		break;
	}
}

void menuApplyActions(){

}

void menuPreviewAction(){
	
}

bool parsingCommand(string& returnedError){
	boost::trim_all(promptInput);
	stringstream stringStream(promptInput);
	string s;
	intParsedPrompt.clear();
	
	while (getline(stringStream, s, PROMPT_DELIMITER)){
		if (commandMap.find(s) != commandMap.end()){		//if command is not found in the library (command map)
			intParsedPrompt.push_back(commandMap.find(s)->second);
		}
		else{
			if (isNumber(s)){
				intParsedPrompt.push_back(stoi(s));
			}
			else{
				returnedError = s;
				return PARSE_FAILED;
			}
		}
	}
	return PARSE_OK;
}

void prompting(){
	string returnedError;
	cout << PROMPT_GREETER;
	getline(cin, promptInput);
	bool status = parsingCommand(returnedError);
	
	if (status == PARSE_FAILED){
		cout << PARSE_FAILURE_NOTIFICATION << returnedError << "\n";
	}
	else{
		switch (intParsedPrompt.at(0))
		{
		case INT_MAIN_MENU_EXIT:
			isExit = true;
			break;
		case INT_MAIN_MENU_FILE:
			menuFileActions();
			break;
		case INT_MAIN_MENU_RULE:
			menuRuleActions();
			break;
		case INT_MAIN_MENU_APPLY:
			menuApplyActions();
			break;
		case INT_MAIN_MENU_PREVIEW:
			menuPreviewAction();
			break;
		default:	//default case is help
			break;
		}
	}
}

void preparingCommandsMap(){
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_EXIT, INT_MAIN_MENU_EXIT));
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_FILE, INT_MAIN_MENU_FILE));
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_RULE, INT_MAIN_MENU_RULE));
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_PREVIEW, INT_MAIN_MENU_PREVIEW));
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_APPLY, INT_MAIN_MENU_APPLY));
	commandMap.insert(pair<string, ConstInt>(MAIN_MENU_HELP, INT_MAIN_MENU_HELP));

	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_IMPORT, INT_MENU_ACTION_IMPORT));
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_ADD, INT_MENU_ACTION_ADD));
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_REMOVE, INT_MENU_ACTION_REMOVE));
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_SHOW, INT_MENU_ACTION_SHOW));

	commandMap.insert(pair<string, ConstInt>(PARAMETER_ALL, INT_PARAMETER_ALL));
	
	commandMap.insert(pair<string, ConstInt>(RULE_INSERT, INT_RULE_INSERT));
	commandMap.insert(pair<string, ConstInt>(RULE_NUMBERING, INT_RULE_NUMBERING));
	commandMap.insert(pair<string, ConstInt>(RULE_REMOVE, INT_RULE_REMOVE));
	commandMap.insert(pair<string, ConstInt>(RULE_REPLACE, INT_RULE_REPLACE));
	commandMap.insert(pair<string, ConstInt>(RULE_CASE_SWITCH, INT_RULE_CASE_SWITCH));

}

int main() {
	cout << "initiazing...\n";
	preparingCommandsMap();

	while(!isExit){
		prompting();
	}
	cout << "bye!\n";
    return 0;
}
