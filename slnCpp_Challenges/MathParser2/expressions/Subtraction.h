#pragma once
#include "Expression.h"
#include <string>

class Subtraction : public Expression
{
private:
	static const char operatorChar = '-';

public:
	Subtraction();

	char charOper() override;
	double evaluate() override;
	std::unique_ptr<Expression> createProto() override;

	std::string formatFormula(const std::string pFormula) override;

	~Subtraction() override = default;
};
