#include <map>

#include "stdafx.h"
#include "FormulaParser.h"
#include "Addition.h"

FormulaParser::FormulaParser()
{
	// Use the following syntax to add a new supported expression :
	//     supportedOperators[CLASS_NAME::operatorChar] = new CLASS_NAME(0);
	//
	// Order them by priority here, parentheses' priority will allways be 
	// on top of the following Expressions

	supportedOperators[Addition::operatorChar] = new Addition();
	//supportedOperators[Substraction::operatorChar] = new Substraction(0);
	//supportedOperators[Multiplication::operatorChar] = new Multiplication(0);
	//supportedOperators[Division::operatorChar] = new Division(0);
}

/*
	this function returns a value lower than 0 when the string is an invalid formula.

	the following codes correspond to the explanation on why the formula is invalid :
		-1 : Parentheses are not parsable (verify correspondence of parentheses and their count)
		-2 : Unsupported operator found

		-999 : any other unsupported error

	If the formula is valid, the function returns 0
	If the formula can be translated to a double value, the function returns 77
*/
int FormulaParser::isValidFormula(string formula)
{
	return -999;
}

char FormulaParser::splitFormulas(string pMain, string* pSubFormula1, string* pSubFormula2)
{
	char retVal = '\0';

	return retVal;
}

P_Expression FormulaParser::parse(string formula)
{/*will return nullptr if the string is not a valid formula*/
	int validCode = FormulaParser::isValidFormula(formula);
	if (validCode > 0)
	{
		string subFormula1, subFormula2 = "";
		char oper = splitFormulas(formula, &subFormula1, &subFormula2);
		P_Expression newExpr = supportedOperators[oper]->createProto();
		newExpr->initialize(validCode, parse(subFormula1), parse(subFormula2));
		return newExpr;
	}
	else if (validCode == 0)
	{
		return new Expression(stod(formula, nullptr));
	}
	return nullptr;
}

FormulaParser::~FormulaParser()
{
}
