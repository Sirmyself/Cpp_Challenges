#pragma once
#include "Expression.h"

class Addition :
	public Expression
{
private:
	static const char operatorChar = '+';
	 
public:
	Addition();
	Addition(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	double evaluate();
	ExprPtr createProto();

	~Addition();
};

