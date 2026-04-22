#pragma once
#include "Expression.h"

class Multiplication : public Expression
{
private:
	static const char operatorChar = '*';

public:
	Multiplication();

	char charOper() override;
	double evaluate() override;
	std::unique_ptr<Expression> createProto() override;

	std::string formatFormula(const std::string pFormula) override;

	~Multiplication() override = default;
};
