#include "stdafx.h"
#include "FormulaParser.h"

using namespace std;

FormulaParser::FormulaParser()
{
	supportedExpressions = new vector<P_Expression>();

	/*  Use the following syntax to add a new supported expression :
	    supportedOperators->push_back(new CLASS_NAME());

 	    Order them by priority here (first is less important than next),
        parentheses will be managed automatically*/

	supportedExpressions->push_back(new Addition());
	//supportedExpressions->push_back(new Substraction());
	supportedExpressions->push_back(new Multiplication());
	//supportedExpressions->push_back(new Division());
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
			if (last == ')') return -4; //missing operator between parentheses
			++open;
		}
		else if (c == ')')
		{
			if (last == '(') return -3; // empty parentheses
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

int FormulaParser::splitFormula(const string pMain, string* pSubFormula1, string* pSubFormula2, char* pOper)
{
	for (vector<P_Expression>::iterator it = supportedExpressions->begin(); it != supportedExpressions->end(); ++it)
	{
		for (int i = 0; i < pMain.length(); ++i)
		{
			if (pMain[i] == '(')
			{
				i = checkCorrespondingParenthesis(pMain, i);
				if (i < 0) return i;
			}

			if (pMain[i] == (*it)->charOper())
			{
				*pOper = pMain[i];
				*pSubFormula1 = pMain.substr(0, i);
				*pSubFormula2 = pMain.substr(i + 1, pMain.length() - i - 1);
				return i;
			}
		}
	}
	return -6;
}

P_Expression FormulaParser::operatorToExpressionProto(const char pOperator)
{
	for (vector<P_Expression>::iterator i = supportedExpressions->begin(); i != supportedExpressions->end(); ++i)
	{
		if (pOperator == (*i)->charOper()) 
		{
			return *i;
		}
	}
	return nullptr;
}

P_Expression FormulaParser::recurParse(const string pFormula, int* pValidCode)
{
	string formatted = removeUselessParentheses(pFormula);

	if (*pValidCode > 0)
	{
		return new Expression(stod(formatted));
	}
	else if (*pValidCode == 0)
	{
		string subFormula1 = "", subFormula2 = "";
		char oper;
		*pValidCode = splitFormula(formatted, &subFormula1, &subFormula2, &oper);

		if (*pValidCode >= 0)
		{
			int valid1 = validateFormula(subFormula1);
			int valid2 = validateFormula(subFormula2);

			P_Expression newExpr = operatorToExpressionProto(oper)->createProto();
			newExpr->initialize// ->
			(
				0,
				recurParse(subFormula1, &valid1),
				recurParse(subFormula2, &valid2)
			);
			return newExpr;
		}
	}

	return nullptr;
}

int FormulaParser::parse(const string pFormula, P_Expression& pTarget)
{/*will return nullptr if the string is not a valid formula*/

	string formatted = pFormula;

	//formatting the formula with every supported Expressions
	for (vector<P_Expression>::iterator i = supportedExpressions->begin(); i != supportedExpressions->end(); ++i)
	{
		formatted = (*i)->formatFormula(formatted);
	}

	//validating the parentheses opening parentheses all have a corresponding closing parenthesis
	int validation = validateParentheses(formatted);
	if (formatted.find("(") != string::npos && validation < 0)
		return validation;


	int validCode = validateFormula(formatted);
	if (validCode >= 0)
	{
		pTarget = recurParse(formatted, &validCode);

		return validCode < 0 ? validCode : 0;
	}

	return validCode;
}

FormulaParser::~FormulaParser()
{
}
