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
	char splitFormulas(string pMain, string* pSubFormula1, string* pSubFormula2);
	map<char, P_Expression> supportedOperators;

public:
	FormulaParser(void);

	P_Expression parse(string formula);
	int isValidFormula(string formula);

	virtual ~FormulaParser();
};

