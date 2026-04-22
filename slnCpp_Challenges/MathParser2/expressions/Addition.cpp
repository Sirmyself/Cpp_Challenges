#include "Addition.h"

Addition::Addition() = default;

char Addition::charOper()
{
	return Addition::operatorChar;
}

double Addition::evaluate()
{
	return expr1_->evaluate() + expr2_->evaluate();
}

std::unique_ptr<Expression> Addition::createProto()
{
	return std::make_unique<Addition>();
}
