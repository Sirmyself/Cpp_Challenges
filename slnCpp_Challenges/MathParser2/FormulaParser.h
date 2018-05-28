#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "baseFunctions.h"
#include "Expression.h"
#include "Addition.h"
#include "Substraction.h"
#include "Multiplication.h"

class FormulaParser
{
private:
	typedef std::vector<P_Expression>* ExpressionVector;

	ExpressionVector supportedExpressions;

	int splitFormula(const std::string pMain, std::string* pSubFormula1, std::string* pSubFormula2, char* pOper);
	bool isParsableToDouble(const std::string pFormula);
	int validateParentheses(const std::string formula);
	int validateOperatorsSupported(const std::string formula);
	int validateFormula(const std::string pFormula);
	P_Expression operatorToExpressionProto(const char pOperator);
	P_Expression recurParse(const std::string pFormula, int* validCode);

public:
	FormulaParser(void);

	int parse(const std::string pFormula, P_Expression& pTarget);

	virtual ~FormulaParser();
};

typedef FormulaParser* P_FParser;
