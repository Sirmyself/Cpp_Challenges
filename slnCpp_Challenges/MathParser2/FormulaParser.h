#pragma once
#include <iostream>
#include <string>
#include <map>

#include "baseFunctions.h"
#include "Expression.h"
#include "Addition.h"
#include "Multiplication.h"

class FormulaParser
{
private:
	std::map<char, P_Expression> supportedOperators;

	char splitFormulas(const std::string pMain, std::string* pSubFormula1, std::string* pSubFormula2);
	bool isParsableToDouble(std::string pFormula);
	int validateParentheses(const std::string formula);
	int validateOperatorsSupported(const std::string formula);
	int validateFormula(const std::string pFormula);
	P_Expression recurParse(std::string pFormula, int validCode);

public:
	FormulaParser(void);

	int parse(const std::string pFormula, P_Expression& pTarget);

	virtual ~FormulaParser();
};

typedef FormulaParser* P_FParser;
