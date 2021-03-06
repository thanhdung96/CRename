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
		resolveHome(pth);
		if (!fileImportDirectory(&lstFiles, pth, count)){
			cout << IMPORT_DIRECTORY_FAILED;
		}
		else{
			if (count == 0){
				cout << "empty directory.\n";
			}
			else{
				resolveToAbsolute(&lstFiles, &lstAbsolutePath, &lstResolvedFileName);
				cout << "imported " << count << " files.\n";
			}
		}
		pth = "";	//reset path for next import or addition
		break;
	}

	case INT_MENU_ACTION_ADD:{		//add a file
		cout << IMPORT_PROMPT;
		getline(cin, pth);
		resolveHome(pth);
		if (!addFile(&lstFiles, pth)){
			cout << ADD_FILE_FAILED;
		}
		else{
			resolveToAbsolute(&lstFiles, &lstAbsolutePath, &lstResolvedFileName);
			cout << "added 1 file.\n";
		}
		pth = "";	//reset path for next import or addition
		break;
	}

	case INT_MENU_ACTION_REMOVE:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			size_t totalRemoved = fileRemoveAll(&lstFiles, &lstAbsolutePath, &lstResolvedFileName);
			cout << totalRemoved << " file(s) removed.\n";
		}
		else{
			if (fileRemove(&lstFiles, &lstAbsolutePath, &lstResolvedFileName, intParsedPrompt[2])){
				cout << "[" << intParsedPrompt[2] << "] removed.\n";
			}
		}
		break;
	}

	case INT_MENU_ACTION_SHOW:{
		if (intParsedPrompt[2] == INT_PARAMETER_ALL){
			vector<string>* lstFileStrings = fileShowAll(&lstResolvedFileName);
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
			string f = fileShow(&lstResolvedFileName, intParsedPrompt[2]);
			if (f.compare("") == 0){
				cout << "file index out of range.\n";
			}
			else{
				cout << "[" << intParsedPrompt[2] << "] " << f << "\n";
			}
		}
		break;
	}

	case INT_MENU_ACTION_MOVE:{
		switch(intParsedPrompt[3]){		// destination parameter
			case INT_PARAMETER_END:{
				fileMove(lstFiles, lstAbsolutePath, lstResolvedFileName, intParsedPrompt[2], lstRules.size() - 1);
				break;
			}
			
			case INT_PARAMETER_FIRST:{
				fileMove(lstFiles, lstAbsolutePath, lstResolvedFileName, intParsedPrompt[2], 0);
				break;
			}
			
			case INT_PARAMETER_TO:{
				fileMove(lstFiles, lstAbsolutePath, lstResolvedFileName, intParsedPrompt[2], intParsedPrompt[4]);
				break;
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
		if(intParsedPrompt.size() == 3){
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
		} else{
			cout << "please specify a rule type.\n";
		}
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

	case INT_MENU_ACTION_MOVE:{
		if(intParsedPrompt[2] >= lstRules.size() || intParsedPrompt[2] < 0){
			cout << "FROM index out of range.\n";
		}
		else{
			switch(intParsedPrompt[3]){		// destination parameter
				case INT_PARAMETER_END:{
					ruleMove(lstRules, intParsedPrompt[2], lstRules.size() - 1);
					break;
				}
				
				case INT_PARAMETER_FIRST:{
					ruleMove(lstRules, intParsedPrompt[2], 0);
					break;
				}
				
				case INT_PARAMETER_TO:{
					if(intParsedPrompt[4] >= lstRules.size() || intParsedPrompt[4] < 0){
						cout << "TO index out of range.\n";
					}
					else{
						ruleMove(lstRules, intParsedPrompt[2], intParsedPrompt[4]);
					}
					break;
				}
			}
		}
		break;
	}
		
	default:
		break;
	}
}

bool menuApplyActions(){
	if (lstFiles.size() == 0){
		cout << "no file(s) to be applied.\n";
		return false;
	}
	if (lstRules.size() == 0){
		cout << "no rule(s) to be applied.\n";
		return false;
	}
	
	string newName;
	for (unsigned i = 0; i < lstResolvedFileName.size(); i++){
		newName = lstResolvedFileName.at(i).string();
		for (unsigned j = 0; j < lstRules.size(); j++){
			newName = lstRules.at(j)->preview(newName);
		}
		lstNewFileName.push_back(newName);
	}
	
#ifdef IS_LINUX
	char separator = '/';
#else
	char separator = '\\';
#endif
	for(unsigned i=0; i<lstAbsolutePath.size(); i++){
		path oldAbsolutePath(canonical(lstAbsolutePath.at(i).string()).string() + separator + lstResolvedFileName.at(i).string());
		path newAbsolutePath(canonical(lstAbsolutePath.at(i).string()).string() + separator + lstNewFileName.at(i).string());
		rename(oldAbsolutePath, newAbsolutePath);
	}

	lstNewFileName.clear();
	lstNewFileName.shrink_to_fit();
	cout << "applied.\n";
	return true;
}

vector<string>* menuPreviewAction(){
	if (lstFiles.size() == 0){
		cout << "no file(s) to be previewed.\n";
		return nullptr;
	}
	if (lstRules.size() == 0){
		cout << "no rule(s) to be previewed.\n";
		return nullptr;
	}

	vector<string>* lstPreviewString = new vector<string>();
	string previewString;
	for (unsigned i = 0; i < lstResolvedFileName.size(); i++){
		previewString = lstResolvedFileName.at(i).string();
		for (unsigned j = 0; j < lstRules.size(); j++){
			previewString = lstRules.at(j)->preview(previewString);
		}
		lstPreviewString->push_back(previewString);
	}

	return lstPreviewString;
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
	boost::trim_all(promptInput);
	
	if(promptInput.length() > 0){
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
				
			case INT_MAIN_MENU_PREVIEW:{
				vector<string>* lstPreviewString = menuPreviewAction();
				
				if (lstPreviewString != nullptr) {
					for (unsigned i = 0; i < lstPreviewString->size(); i++) {
						cout << "[" << i << "]" << lstPreviewString->at(i) << "\n";
					}
				}
				delete lstPreviewString;
				break;
			}
			
			default:	//default case is help
				break;
			}
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
	commandMap.insert(pair<string, ConstInt>(MENU_ACTION_MOVE, INT_MENU_ACTION_MOVE));

	commandMap.insert(pair<string, ConstInt>(PARAMETER_ALL, INT_PARAMETER_ALL));
	commandMap.insert(pair<string, ConstInt>(PARAMETER_TO, INT_PARAMETER_TO));
	commandMap.insert(pair<string, ConstInt>(PARAMETER_END, INT_PARAMETER_END));
	commandMap.insert(pair<string, ConstInt>(PARAMETER_FIRST, INT_PARAMETER_FIRST));
	
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

	// rule list uses pointers to rules, it should be deallocated before exiting
	ruleRemoveAll(&lstRules);

	cout << "bye!\n";
    return 0;
}

