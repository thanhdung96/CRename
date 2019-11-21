
#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <unordered_map>
#include "constants.h"

string promptInput;
string endParameter;
vector<unsigned> intParsedPrompt;
unordered_map<string, ConstInt> commandMap;

// TODO: replace string with "path" class in boost library
vector<string> lstFiles;	//temporary file list using string
vector<string> lstRules;	//temporary rule list using string

#endif // !COMMON_H
