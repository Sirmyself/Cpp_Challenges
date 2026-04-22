#pragma once
#include "Expression.h"
#include <cmath>

class Power : public Expression
{
private:
	static const char operatorChar = '^';

public:
	Power();

	char charOper() override;
	double evaluate() override;
	std::unique_ptr<Expression> createProto() override;

	~Power() override = default;
};
