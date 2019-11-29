#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string trimWhiteSpaces(const string& str);
string joinStrings(vector<string> lstString, const char delimiter);
bool isNumber(const string& str);

#endif