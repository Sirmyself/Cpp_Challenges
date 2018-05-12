#pragma once
#include "Expression.h"

class Multiplication :
	public Expression
{
private :
	static const char operatorChar = '*';

public:
	Multiplication();
	Multiplication(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	double evaluate();
	ExprPtr createProto();
	
	virtual std::string formatFormula(const std::string pFormula);

	~Multiplication();
};

