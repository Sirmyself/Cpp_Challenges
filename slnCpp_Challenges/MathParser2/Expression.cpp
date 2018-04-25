#include "stdafx.h"
#include "Expression.h"

Expression::Expression()
	: value_(0), expr1_(nullptr), expr2_(nullptr)
{}

Expression::Expression(double pValue)
	: value_(pValue), expr1_(nullptr), expr2_(nullptr)
{}

Expression::Expression(ExprPtr pExpr1, ExprPtr pExpr2)
	: value_(0), expr1_(pExpr1), expr2_(pExpr2)
{}

double Expression::evaluate()
{
	return value_;
}


Expression::ExprPtr Expression::createProto()
{
	return nullptr;
}

void Expression::initialize(double pValue, ExprPtr pExp1, ExprPtr pExp2)
{
	this->value_ = pValue;

	if (this->expr1_ != nullptr) { delete this->expr1_; }
	this->expr1_ = pExp1;

	if (this->expr2_ != nullptr) { delete this->expr2_; }
	this->expr2_ = pExp2;
}

Expression::~Expression()
{
	if (this->expr1_ != nullptr) { delete this->expr1_; }
	if (this->expr2_ != nullptr) { delete this->expr2_; }
}
