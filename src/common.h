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

vector<path> lstFiles;				// list of file temporarily stored after import
vector<path> lstAbsolutePath;		// resolve to absolute path
vector<path> lstResolvedFileName;	// extract file name and extension only
vector<path> lstNewFileName;

vector<CRule*> lstRules;


#endif // !COMMON_H
