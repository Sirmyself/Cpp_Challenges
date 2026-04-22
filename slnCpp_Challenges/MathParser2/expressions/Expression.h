#pragma once

#include "parsingUtils.h"

#include <memory>
#include <string>

class Expression
{
private:
	static const char operatorChar = '\0';

protected:
	using ExprPtr = std::unique_ptr<Expression>;

	ExprPtr expr1_;
	ExprPtr expr2_;
	double value_;

public:
	Expression();
	Expression(double pValue);
	Expression(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();
	virtual std::string formatFormula(const std::string pFormula);
	virtual double evaluate();
	virtual std::unique_ptr<Expression> createProto();
	void initialize(double pValue, ExprPtr pExp1, ExprPtr pExp2);

	virtual ~Expression() = default;
};
