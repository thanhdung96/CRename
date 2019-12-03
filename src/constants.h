#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <sstream>
using namespace std;

typedef const int ConstInt;

string PROMPT_GREETER = "\ncrename> ";
string IMPORT_PROMPT = "--- > ";
const char PROMPT_DELIMITER = ' ';
const bool PARSE_OK = true;
const bool PARSE_FAILED = false;

string PARSE_FAILURE_NOTIFICATION = "unable to understand the command ";
string IMPORT_DIRECTORY_FAILED = "import failed.\nmake sure it\'s a directory and it should exist.\n";
string ADD_FILE_FAILED = "import failed.\nmake sure it\'s a file and it should exist.\n";

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
string MENU_ACTION_SHOW = "show";

ConstInt INT_MENU_ACTION_IMPORT = 100;
ConstInt INT_MENU_ACTION_ADD = 101;
ConstInt INT_MENU_ACTION_REMOVE = 102;
ConstInt INT_MENU_ACTION_SHOW = 103;

string PARAMETER_ALL = "all";

ConstInt INT_PARAMETER_ALL = 200;

string RULE_INSERT = "insert";
string RULE_NUMBERING = "numbering";
string RULE_REMOVE = "remove";
string RULE_REPLACE = "replace";
string RULE_CASE_SWITCH = "case_conv";

ConstInt INT_RULE_INSERT = 300;
ConstInt INT_RULE_NUMBERING = 301;
ConstInt INT_RULE_REMOVE = 302;
ConstInt INT_RULE_REPLACE = 303;
ConstInt INT_RULE_CASE_SWITCH = 304;

#endif // !CONSTANTS_H
