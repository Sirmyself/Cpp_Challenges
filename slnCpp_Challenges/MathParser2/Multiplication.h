#pragma once
#include "Expression.h"

class Multiplication :
	public Expression
{
public:
	static const char operatorChar = '*';

	Multiplication(ExprPtr pExpr1, ExprPtr pExpr2);
	double evaluate();
	ExprPtr createProto();
	
	virtual std::string formatFormula(const std::string pFormula);

	~Multiplication();
};

