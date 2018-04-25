#pragma once
#include "Expression.h"

class Addition :
	public Expression
{
public:
	static const char operatorChar = '+';

	Addition();
	Addition(ExprPtr pExpr1, ExprPtr pExpr2);
	double evaluate();
	ExprPtr createProto();
	~Addition();
};

