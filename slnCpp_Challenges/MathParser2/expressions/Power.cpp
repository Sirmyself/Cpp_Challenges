#include "Power.h"

Power::Power() = default;

char Power::charOper()
{
	return Power::operatorChar;
}

double Power::evaluate()
{
	return pow(expr1_->evaluate(), expr2_->evaluate());
}

std::unique_ptr<Expression> Power::createProto()
{
	return std::make_unique<Power>();
}
