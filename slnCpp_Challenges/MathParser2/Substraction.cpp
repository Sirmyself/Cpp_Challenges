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
	bool lastIsNbrOrClosing = false;
	unsigned mustClose = 0;
	std::string formatted = pFormula;

	for (int i = 0 ; i < formatted.length(); ++i)
	{
		bool isNbr = (formatted[i] >= '0' && formatted[i] <= '9') || formatted[i] == '.';
		if (formatted[i] == Substraction::operatorChar && !lastIsNbrOrClosing)
		{
			formatted.insert(i,"(0");
			i = i + 2;
			++mustClose;
		}
		else if (!isNbr && (mustClose > 0))
		{
			--mustClose;
			formatted.insert(i, ")");
		}

		lastIsNbrOrClosing = isNbr || formatted[i] == ')';
	}
	while (mustClose-- > 0)
	{
		formatted.insert(formatted.length(), ")");
	}

	return Expression::formatFormula(formatted);
}

Substraction::~Substraction()
{
}
