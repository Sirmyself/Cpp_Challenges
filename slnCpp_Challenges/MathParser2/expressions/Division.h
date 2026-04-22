#pragma once
#include "Expression.h"

class Division : public Expression
{
private:
	static const char operatorChar = '/';

public:
	Division();

	char charOper() override;
	double evaluate() override;
	std::unique_ptr<Expression> createProto() override;

	~Division() override = default;
};
