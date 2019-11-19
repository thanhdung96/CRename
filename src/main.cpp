#include <iostream>
#include <vector>
#include "constants.h"
using namespace std;

string promptInput;
vector<string> parsedPrompt;
bool isExit = false;

void parsingCommand(){
	stringstream stringStream(promptInput);
	string s;
	parsedPrompt.clear();
	
	while(getline(stringStream, s, PROMPT_DELIMITER)){
		parsedPrompt.push_back(s);
	}
}

void prompting(){
	cout << PROMPT_GREETER;
	getline(cin, promptInput);
	parsingCommand();
	if(promptInput.compare(EXIT_PROGRAM) == 0){
		isExit = true;
	}	
}

int main() {
	while(!isExit){
		prompting();
	}
	cout << "exit crename\n" ;
    return 0;
}
