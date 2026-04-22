#pragma once
#include "Expression.h"

class Addition : public Expression
{
private:
	static const char operatorChar = '+';

public:
	Addition();

	char charOper() override;
	double evaluate() override;
	std::unique_ptr<Expression> createProto() override;

	~Addition() override = default;
};
