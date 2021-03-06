#pragma once

#include "parsingUtils.h"

#include <string>

class Expression
{
private : 
	static const char operatorChar = '\0';

protected:
	typedef Expression* ExprPtr;

	Expression* expr1_;
	Expression* expr2_;
	double value_;

public:
	Expression();
	Expression(double pValue);
	Expression(ExprPtr pExpr1, ExprPtr pExpr2);

	virtual char charOper();                                        //must override
	virtual std::string formatFormula(const std::string pFormula);  //optionnal override
	virtual double evaluate();                                      //must override
	virtual ExprPtr createProto();                                  //must override
	void initialize(double pValue, ExprPtr pExp1, ExprPtr pExp2);

	virtual ~Expression();
};

typedef Expression* P_Expression;