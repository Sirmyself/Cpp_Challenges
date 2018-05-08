#include "stdafx.h"
#include "Addition.h"

Addition::Addition(ExprPtr pExpr1, ExprPtr pExpr2) : Expression(pExpr1, pExpr2) {}

double Addition::evaluate()
{
	return Expression::expr1_->evaluate() + Expression::expr2_->evaluate();
}

Addition::ExprPtr Addition::createProto()
{
	ExprPtr newExp = new Addition(nullptr, nullptr);
	return newExp;
}

Addition::~Addition()
{
}
