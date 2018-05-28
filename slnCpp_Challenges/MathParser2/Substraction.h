#pragma once
#include "Expression.h"
#include <string>

class Substraction :
	public Expression
{
private:
	static const char operatorChar = '-';

public:
	Substraction();
	Substraction(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	double evaluate();
	ExprPtr createProto();

	std::string formatFormula(const std::string pFormula);

	~Substraction();
};

