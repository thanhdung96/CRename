#ifndef RULE_FUNCTIONS_H
#define RULE_FUNCTIONS_H

#include "CRuleInsert.h"
#include "CRuleNumber.h"
#include "CRuleRemove.h"
#include "CRuleReplace.h"
#include "CRuleSwitchCase.h"
#include <iostream>
using namespace std;

enum AvailableRules{
	Insert,
	Numering,
	Remove,
	Replace,
	SwitchCase
};
// constructing rule functions
void createRuleInsert(CRuleInsert& insert, bool& status);
void createRuleNumbering(CRuleNumber& number, bool& status);
void createRuleRemove(CRuleRemove& remove, bool& status);
void createRuleReplace(CRuleReplace& replace, bool& status);
void createRuleSwitchCase(CRuleSwitchCase& switchCase, bool& status);

// general rule functions
bool addRule(vector<CRule*>* lstRules, AvailableRules chosenRule);
string ruleShow(vector<CRule*>* lstRules, const unsigned& index);
vector<string>* ruleShowAll(vector<CRule*>* lstRules);
bool ruleRemove(vector<CRule*>* lstRules, const unsigned& index);
size_t ruleRemoveAll(vector<CRule*>* lstRules);
void ruleMove(std::vector< CRule* >& lstRules, unsigned int from, unsigned int to);

#endif
