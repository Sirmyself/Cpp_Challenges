#include "stdafx.h"
#include "Addition.h"

Addition::Addition() : Expression(nullptr, nullptr) {}

Addition::Addition(ExprPtr pExpr1, ExprPtr pExpr2) : Expression(pExpr1, pExpr2) {}

char Addition::charOper()
{
	return Addition::operatorChar;
}

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
