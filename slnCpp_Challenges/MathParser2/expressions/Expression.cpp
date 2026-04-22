#include "Expression.h"

#include <algorithm>

using namespace std;

Expression::Expression()
	: value_(0)
{}

Expression::Expression(double pValue)
	: value_(pValue)
{}

Expression::Expression(ExprPtr pExpr1, ExprPtr pExpr2)
	: value_(0), expr1_(move(pExpr1)), expr2_(move(pExpr2))
{}

char Expression::charOper()
{
	return operatorChar;
}

string Expression::formatFormula(const string pFormula)
{
	string retVal = pFormula;
	retVal.erase(remove(retVal.begin(), retVal.end(), ' '), retVal.end());
	return removeUselessParentheses(retVal);
}

double Expression::evaluate()
{
	return value_;
}

unique_ptr<Expression> Expression::createProto()
{
	return nullptr;
}

void Expression::initialize(double pValue, ExprPtr pExp1, ExprPtr pExp2)
{
	value_ = pValue;
	expr1_ = move(pExp1);
	expr2_ = move(pExp2);
}
