#pragma once
#include "Expression.h"
class Power :
	public Expression
{
private:
	static const char operatorChar = '^';

public:
	Power();
	Power(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	double evaluate();
	ExprPtr createProto();
	~Power();
};

