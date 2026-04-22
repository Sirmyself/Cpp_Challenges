#include "Division.h"

#include <iostream>
#include <limits>

Division::Division() = default;

char Division::charOper()
{
	return Division::operatorChar;
}

double Division::evaluate()
{
	double divisor = expr2_->evaluate();
	if (divisor == 0.0)
	{
		std::cerr << "Warning: division by zero\n";
		return std::numeric_limits<double>::infinity();
	}
	return expr1_->evaluate() / divisor;
}

std::unique_ptr<Expression> Division::createProto()
{
	return std::make_unique<Division>();
}
