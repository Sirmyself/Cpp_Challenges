#pragma once
#include <iostream>
#include <string>
#include <map>

#include "baseFunctions.h"
#include "Expression.h"
#include "Addition.h"

using namespace std;

class FormulaParser
{
private:
	char splitFormulas(const string pMain, string* pSubFormula1, string* pSubFormula2);
	map<char, P_Expression> supportedOperators;

	int validateParentheses(const string formula);
	int validateOperatorsSupported(const string formula);
	int validateFormula(const string pFormula);

	P_Expression recurParse(string pFormula, int validCode);

public:
	FormulaParser(void);

	int parse(const string pFormula, P_Expression& pTarget);

	virtual ~FormulaParser();
};

typedef FormulaParser* P_FParser;
