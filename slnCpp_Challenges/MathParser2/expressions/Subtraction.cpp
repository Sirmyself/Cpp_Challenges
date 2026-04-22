#include "Subtraction.h"

Subtraction::Subtraction() = default;

char Subtraction::charOper()
{
	return Subtraction::operatorChar;
}

double Subtraction::evaluate()
{
	return expr1_->evaluate() - expr2_->evaluate();
}

std::unique_ptr<Expression> Subtraction::createProto()
{
	return std::make_unique<Subtraction>();
}

std::string Subtraction::formatFormula(const std::string pFormula)
{
	bool lastIsNbrOrClosing = false;
	unsigned mustClose = 0;
	std::string formatted = pFormula;

	if (formatted.find(Subtraction::operatorChar) != std::string::npos)
	{
		for (int i = 0; i < static_cast<int>(formatted.length()); ++i)
		{
			bool isNbr = (formatted[i] >= '0' && formatted[i] <= '9') || formatted[i] == '.';
			if (formatted[i] == Subtraction::operatorChar && !lastIsNbrOrClosing)
			{
				formatted.insert(i, "(0");
				i = i + 2;
				++mustClose;
			}
			else if (!isNbr && (mustClose > 0))
			{
				--mustClose;
				formatted.insert(i, ")");
			}

			lastIsNbrOrClosing = isNbr || formatted[i] == ')';
		}
		while (mustClose-- > 0)
		{
			formatted.insert(formatted.length(), ")");
		}
	}

	return Expression::formatFormula(formatted);
}
