#include "stdafx.h"

#include "FormulaParser.h"

#include <map>

using namespace std;

FormulaParser::FormulaParser()
{
	/* Use the following syntax to add a new supported expression :
	     supportedOperators[CLASS_NAME::operatorChar] = new CLASS_NAME(0);
	
	Order them by priority here (first is less important than next), 
	parentheses will be managed automatically*/

	supportedOperators[Addition::operatorChar] = new Addition(nullptr, nullptr);
	//supportedOperators[Substraction::operatorChar] = new Substraction(nullptr, nullptr);
	supportedOperators[Multiplication::operatorChar] = new Multiplication(nullptr, nullptr);
	//supportedOperators[Division::operatorChar] = new Division(nullptr, nullptr);
}

bool FormulaParser::isParsableToDouble(string pFormula)
{
	for (char c : pFormula)
	{
		if (!((c >= '0' && c <= '9') || c == '.'))
		{
			return false;
		}
	}

	return true;
}

int FormulaParser::validateParentheses(const string pFormula)
{
	int open = 0, close = 0;
	char last = '\0';

	for (char c : pFormula)
	{
		if (c == '(')
		{
			if (last == ')') return -4; //missing operator between perentheses
			++open;
		}
		else if (c == ')')
		{
			if (last == '(') return -3; // empty perentheses
			++close;
		}

		if (open < close) return -1; // parentheses not parsable
		last = c;
	}

	return open == close ? 0 : -1; // parentheses not parsable
}

int FormulaParser::validateOperatorsSupported(const string formula)
{
	return 0;
}

/*
	this function returns a value lower than 0 when the string is an invalid formula.

	the following codes correspond to the explanation on why the formula is invalid :
		-1 : Parentheses are not parsable (verify correspondence of parentheses and their count)
		-2 : Unsupported operator found
		-3 : Empty parentheses
		-4 : Missing operators between parentheses
		-999 : any other unsupported error

	If the formula is valid, the function returns 0
	If the formula can be translated to a double value, the function returns 77
*/
int FormulaParser::validateFormula(const string pFormula)
{
	int err = 0;

	if (isParsableToDouble(pFormula))
	{
		return 77;
	}

	if (validateOperatorsSupported(pFormula) == 0)
	{
		return 0;
	}

	return err;
}

char FormulaParser::splitFormulas(const string pMain, string* pSubFormula1, string* pSubFormula2)
{
	char retVal = '\0';

	return retVal;
}

P_Expression FormulaParser::recurParse(string pFormula, int pValidCode)
{
	if (pValidCode > 0)
	{
		return new Expression(stod(pFormula));
	}
	else if (pValidCode == 0)
	{
		string subFormula1 = "", subFormula2 = "";
		char oper = splitFormulas(pFormula, &subFormula1, &subFormula2);

		P_Expression newExpr = FormulaParser::supportedOperators[oper]->createProto();
		newExpr->initialize// ->
		(
			0,
			recurParse(subFormula1, validateFormula(subFormula1)),
			recurParse(subFormula2, validateFormula(subFormula2))
		);

		return newExpr;
	}

	return nullptr;
}

int FormulaParser::parse(const string pFormula, P_Expression& pTarget)
{/*will return nullptr if the string is not a valid formula*/

	string formatted = pFormula;

	//formatting the formula with every supported Expressions
	for (map<char, P_Expression>::iterator iter = supportedOperators.begin(); iter != supportedOperators.end(); ++iter)
	{
		formatted = iter->second->formatFormula(formatted);
	}

	//validating the parentheses opening parentheses all have a corresponding closing parenthesis
	int validation = 0;
	if (formatted.find("(") != string::npos && (validation = validateParentheses(formatted)) < 0)
		return validation;


	int validCode = validateFormula(formatted);
	if (validCode >= 0)
	{
		pTarget = recurParse(formatted, validCode);

		return 0;
	}

	return validCode;
}

FormulaParser::~FormulaParser()
{
}
