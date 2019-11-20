#include <iostream>
#include "utilities.h"
#include "common.h"
#include "constants.h"
using namespace std;

bool isExit = false;

void menuFileActions(){
	switch (intParsedPrompt[1])
	{
	case INT_MENU_ACTION_IMPORT:	//import a directory
		break;
	case INT_MENU_ACTION_ADD:		//add a file
		break;
	case INT_MENU_ACTION_REMOVE:
		break;
	default:
		break;
	}
}

void menuRuleActions(){
	switch (intParsedPrompt[1])
	{
	case INT_MENU_ACTION_ADD:		//add a rule
		break;
	case INT_MENU_ACTION_REMOVE:
		break;
	default:
		break;
	}
}

void menuApplyActions(){

}

bool parsingCommand(string* returnedError){
	stringstream stringStream(trimWhiteSpaces(promptInput));
	string s;
	intParsedPrompt.clear();
	
	while (getline(stringStream, s, PROMPT_DELIMITER)){
		if (commandMap.find(s) != commandMap.end()){
			intParsedPrompt.push_back(commandMap.find(s)->second);
		}
		else{
			returnedError = &s;
			return PARSE_FAILED;
		}
	}
	return PARSE_OK;
}

void prompting(){
	string returnedError;
	cout << PROMPT_GREETER;
	getline(cin, promptInput);
	bool status = parsingCommand(&returnedError);
	
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
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_ADD, INT_MENU_ACTION_IMPORT));
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_REMOVE, INT_MENU_ACTION_REMOVE));

	commandMap.insert(pair<string, ConstInt>(PARAMETER_ALL, INT_PARAMETER_ALL));
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
