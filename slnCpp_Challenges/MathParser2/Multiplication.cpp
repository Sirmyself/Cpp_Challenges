#include "stdafx.h"
#include "Multiplication.h"

Multiplication::Multiplication()
	: Expression(nullptr, nullptr)
{
}

Multiplication::Multiplication(ExprPtr pExpr1, ExprPtr pExpr2)
	: Expression(pExpr1, pExpr2)
{
}

char Multiplication::charOper()
{
	return Multiplication::operatorChar;
}

double Multiplication::evaluate()
{
	return Expression::expr1_->evaluate() * Expression::expr2_->evaluate();
}

Multiplication::ExprPtr Multiplication::createProto()
{
	ExprPtr newExp = new Multiplication();
	return newExp;
}

std::string Multiplication::formatFormula(const std::string pFormula)
{
	std::string retVal = pFormula;
	for (int i = 1; i < retVal.length(); ++i)
	{
		if (retVal[i] == '(' && retVal[i - 1] == ')')
		{ 
			retVal.insert(i, "*");
		}
	}

	return retVal;
}

Multiplication::~Multiplication()
{
}
