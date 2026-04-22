#include "Multiplication.h"

Multiplication::Multiplication() = default;

char Multiplication::charOper()
{
	return Multiplication::operatorChar;
}

double Multiplication::evaluate()
{
	return expr1_->evaluate() * expr2_->evaluate();
}

std::unique_ptr<Expression> Multiplication::createProto()
{
	return std::make_unique<Multiplication>();
}

std::string Multiplication::formatFormula(const std::string pFormula)
{
	std::string retVal = pFormula;
	for (int i = 1; i < static_cast<int>(retVal.length()); ++i)
	{
		if (retVal[i] == '(' && (retVal[i - 1] == ')' || (retVal[i - 1] >= '0' && retVal[i - 1] <= '9')))
		{
			retVal.insert(i, 1, Multiplication::operatorChar);
		}
	}

	return Expression::formatFormula(retVal);
}
