#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <unordered_map>
#include "CRule.h"

#ifdef IS_LINUX
	#include <boost/filesystem.hpp>
#else
	#include <boost\filesystem.hpp>
#endif

#include "constants.h"

using namespace boost::filesystem;

string promptInput;
string endParameter;
vector<unsigned> intParsedPrompt;
unordered_map<string, ConstInt> commandMap;

vector<path> lstFiles;
vector<CRule*> lstRules;

#endif // !COMMON_H
