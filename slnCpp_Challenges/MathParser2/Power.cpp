#include "stdafx.h"
#include "Power.h"


Power::Power() : Expression(nullptr, nullptr) {}

Power::Power(ExprPtr pExpr1, ExprPtr pExpr2) : Expression(pExpr1, pExpr2) {}

char Power::charOper()
{
	return Power::operatorChar;
}

double Power::evaluate()
{
	return pow(Expression::expr1_->evaluate(), Expression::expr2_->evaluate());
}

Power::ExprPtr Power::createProto()
{
	ExprPtr newExp = new Power(nullptr, nullptr);
	return newExp;
}

Power::~Power()
{
}
