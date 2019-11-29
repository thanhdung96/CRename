#include "utilities.h"

string trimWhiteSpaces(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

string joinStrings(vector<string> lstString, const char delimiter) {
	if (lstString.size() == 0){
		return lstString.at(0);
	}

	string ret;
	ret.append(lstString[0]);
	for (size_t i = 1; i < lstString.size(); i++){
		ret.append(&delimiter);
		ret.append(lstString[i]);
	}

	return ret;
}

bool isNumber(const string& s)
{
	return !s.empty() && find_if(
		s.begin(), s.end(), [](char c) {
		return !isdigit(c); 
	}) == s.end();
}