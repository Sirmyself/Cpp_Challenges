#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "baseFunctions.h"
#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"

class FormulaParser
{
private:
	std::vector<std::unique_ptr<Expression>> supportedExpressions;

	int splitFormula(const std::string pMain, std::string* pSubFormula1, std::string* pSubFormula2, char* pOper);
	bool isParsableToDouble(const std::string pFormula);
	int validateParentheses(const std::string formula);
	int validateOperatorsSupported(const std::string formula);
	int validateFormula(const std::string pFormula);
	Expression* operatorToExpressionProto(const char pOperator);
	std::unique_ptr<Expression> recurParse(const std::string pFormula, int* validCode);

public:
	FormulaParser();

	int parse(const std::string pFormula, std::unique_ptr<Expression>& pTarget);
};
