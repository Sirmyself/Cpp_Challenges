#include "stdafx.h"
#include "Expression.h"

using namespace std;

Expression::Expression()
	: value_(0), expr1_(nullptr), expr2_(nullptr)
{}

Expression::Expression(double pValue)
	: value_(pValue), expr1_(nullptr), expr2_(nullptr)
{}

Expression::Expression(ExprPtr pExpr1, ExprPtr pExpr2)
	: value_(0), expr1_(pExpr1), expr2_(pExpr2)
{}

size_t checkCorrespondingParenthesis(const string pFormula, unsigned int firstIndex)
{
	unsigned int i = firstIndex;
	unsigned int opening = 0, closing = 0;

	while (i < pFormula.length())
	{
		if (pFormula[i] == '(') ++opening;
		if (pFormula[i] == ')') ++closing;

		if (opening == closing) 
			return i;
		else 
			++i;
	}

	return -5; // error : corresponding parenthesis not found;
}

/*
	Use this function to extend support over notations for the formula.

	override this function if an Expression sub class needs to add support for a certain notation
		- i.e. "(a)(b)" notation for multiplication would be formatted "(a)*(b)" so the parser
		  can parse it without a parentheses parsing error.

	This function assumes the prentheses are valid in the formula. It
	returns a formatted copy of the string received in the argument.
	If "formatFormula" is not overridden, it will simply remove unnecessary outter 
	parentheses and return the string as it is.

	Use this function before any form of validation on the formula string (except for parentheses validation)
*/
string Expression::formatFormula(const string pFormula)
{
	string retVal = "";
	if (pFormula[0] == '(' && checkCorrespondingParenthesis(pFormula, 0) == pFormula.length() - 1)
	{
		retVal = pFormula.substr(1, pFormula.length() - 2); // -2 for both parentheses
	}
	else
	{
		retVal = pFormula;
	}
	return retVal;
}

double Expression::evaluate()
{
	return value_;
}


Expression::ExprPtr Expression::createProto()
{
	return nullptr;
}

void Expression::initialize(double pValue, ExprPtr pExp1, ExprPtr pExp2)
{
	this->value_ = pValue;

	if (this->expr1_ != nullptr) { delete this->expr1_; }
	this->expr1_ = pExp1;

	if (this->expr2_ != nullptr) { delete this->expr2_; }
	this->expr2_ = pExp2;
}

Expression::~Expression()
{
	if (this->expr1_ != nullptr) { delete this->expr1_; }
	if (this->expr2_ != nullptr) { delete this->expr2_; }
}
