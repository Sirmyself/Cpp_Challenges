#include "stdafx.h"
#include "Substraction.h"


Substraction::Substraction()
	: Expression(nullptr, nullptr)
{
}

Substraction::Substraction(ExprPtr pExpr1, ExprPtr pExpr2)
	: Expression(pExpr1, pExpr2)
{
}

char Substraction::charOper()
{
	return Substraction::operatorChar;
}

double Substraction::evaluate()
{
	return this->expr1_->evaluate() - this->expr2_->evaluate();
}

Substraction::ExprPtr Substraction::createProto()
{
	ExprPtr newExp = new Substraction();
	return newExp;
}

std::string Substraction::formatFormula(const std::string pFormula)
{
	bool lastIsNbr = false;
	bool mustClose = false;
	std::string formatted = pFormula;

	for (int i = 0 ; i < formatted.length(); ++i)
	{
		bool isNbr = (formatted[i] >= '0' && formatted[i] <= '9') || formatted[i] == '.';
		if (formatted[i] == Substraction::operatorChar && !lastIsNbr)
		{
			formatted.insert(i,"(0");
			i = i + 2;
			mustClose = true;
		}
		else if (!isNbr && mustClose)
		{
			mustClose = false;
			formatted.insert(i, ")");
		}

		lastIsNbr = isNbr;
	}

	if (mustClose)
	{
		formatted.insert(formatted.length(), ")");
		mustClose = false;
	}

	return formatted;
}

Substraction::~Substraction()
{
}
