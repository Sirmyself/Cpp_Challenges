#pragma once
#include "Expression.h"
class Division :
	public Expression
{
private:
	static const char operatorChar = '/';

public:
	Division();
	Division(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	double evaluate();
	ExprPtr createProto();

	~Division();
};

