#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <sstream>
using namespace std;

typedef const int ConstInt;

string PROMPT_GREETER = "crename> ";
string PARSE_FAILURE_NOTIFICATION = "unable to understand the command ";
const char PROMPT_DELIMITER = ' ';
const bool PARSE_OK = true;
const bool PARSE_FAILED = false;

string MAIN_MENU_FILE = "file";
string MAIN_MENU_RULE = "rule";
string MAIN_MENU_PREVIEW = "preview";
string MAIN_MENU_APPLY = "apply";
string MAIN_MENU_HELP = "help";
string MAIN_MENU_EXIT = "exit";

ConstInt INT_MAIN_MENU_FILE = 1;
ConstInt INT_MAIN_MENU_RULE = 2;
ConstInt INT_MAIN_MENU_PREVIEW = 3;
ConstInt INT_MAIN_MENU_APPLY = 4;
ConstInt INT_MAIN_MENU_HELP = 5;
ConstInt INT_MAIN_MENU_EXIT = 0;

string MENU_ACTION_IMPORT = "import";
string MENU_ACTION_ADD = "add";
string MENU_ACTION_REMOVE = "remove";

ConstInt INT_MENU_ACTION_IMPORT = 100;
ConstInt INT_MENU_ACTION_ADD = 101;
ConstInt INT_MENU_ACTION_REMOVE = 102;

string PARAMETER_ALL = "all";

ConstInt INT_PARAMETER_ALL = 200;
#endif // !CONSTANTS_H
