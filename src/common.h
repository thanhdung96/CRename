#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <unordered_map>

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

vector<path> lstFiles;	//temporary file list using string
vector<string> lstRules;	//temporary rule list using string

#endif // !COMMON_H
