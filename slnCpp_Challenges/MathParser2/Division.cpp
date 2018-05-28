#include "stdafx.h"
#include "Division.h"


Division::Division() : Expression(nullptr, nullptr) {}

Division::Division(ExprPtr pExpr1, ExprPtr pExpr2) : Expression(pExpr1, pExpr2) {}

char Division::charOper()
{
	return Division::operatorChar;
}

double Division::evaluate()
{
	return Expression::expr1_->evaluate() / Expression::expr2_->evaluate();
}

Division::ExprPtr Division::createProto()
{
	ExprPtr newExp = new Division(nullptr, nullptr);
	return newExp;
}

Division::~Division()
{
}
