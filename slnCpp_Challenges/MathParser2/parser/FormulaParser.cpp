#include "FormulaParser.h"

using namespace std;

FormulaParser::FormulaParser()
{
	supportedExpressions.push_back(make_unique<Addition>());
	supportedExpressions.push_back(make_unique<Subtraction>());
	supportedExpressions.push_back(make_unique<Multiplication>());
	supportedExpressions.push_back(make_unique<Division>());
	supportedExpressions.push_back(make_unique<Power>());
}

bool FormulaParser::isParsableToDouble(string pFormula)
{
	if (pFormula.empty()) return false;

	int dotCount = 0;
	for (char c : pFormula)
	{
		if (c == '.')
		{
			if (++dotCount > 1) return false;
		}
		else if (c < '0' || c > '9')
		{
			return false;
		}
	}

	return true;
}

int FormulaParser::validateParentheses(const string pFormula)
{
	int open = 0, close = 0;
	char last = '\0';

	for (char c : pFormula)
	{
		if (c == '(')
		{
			if (last == ')') return -4;
			++open;
		}
		else if (c == ')')
		{
			if (last == '(') return -3;
			++close;
		}

		if (open < close) return -1;
		last = c;
	}

	return open == close ? 0 : -5;
}

int FormulaParser::validateOperatorsSupported(const string formula)
{
	for (char c : formula)
	{
		if (!(c == ' ' || c == '(' || c == ')' || (c >= '0' && c <= '9') || c == '.'))
		{
			bool supported = false;
			for (auto& expr : supportedExpressions)
			{
				supported = supported || expr->charOper() == c;
			}
			if (!supported)
			{
				return -2;
			}
		}
	}
	return 0;
}

int FormulaParser::validateFormula(const string pFormula)
{
	int err = validateParentheses(pFormula);

	if (pFormula.length() == 0)
	{
		err = -11;
	}
	else if (isParsableToDouble(pFormula))
	{
		err = 77;
	}
	else if (err == 0)
	{
		err = validateOperatorsSupported(pFormula);
	}
	return err;
}

int FormulaParser::splitFormula(const string pMain, string* pSubFormula1, string* pSubFormula2, char* pOper)
{
	for (auto& proto : supportedExpressions)
	{
		for (int i = static_cast<int>(pMain.length()) - 1; i >= 0; --i)
		{
			if (pMain[i] == ')')
			{
				i = checkCorrespondingParenthesis(pMain, i);
				if (i < 0) return i;
			}

			if (pMain[i] == proto->charOper())
			{
				*pOper = pMain[i];
				*pSubFormula1 = removeUselessParentheses(pMain.substr(0, i));
				*pSubFormula2 = removeUselessParentheses(pMain.substr(i + 1, pMain.length() - i - 1));
				return i;
			}
		}
	}
	return -6;
}

Expression* FormulaParser::operatorToExpressionProto(const char pOperator)
{
	for (auto& expr : supportedExpressions)
	{
		if (pOperator == expr->charOper())
		{
			return expr.get();
		}
	}
	return nullptr;
}

unique_ptr<Expression> FormulaParser::recurParse(const string pFormula, int* pValidCode)
{
	if (*pValidCode > 0)
	{
		return make_unique<Expression>(stod(pFormula));
	}
	else if (*pValidCode == 0)
	{
		string subFormula1 = "", subFormula2 = "";
		char oper;
		*pValidCode = splitFormula(pFormula, &subFormula1, &subFormula2, &oper);

		if (*pValidCode >= 0)
		{
			int valid1 = validateFormula(subFormula1);
			int valid2 = validateFormula(subFormula2);

			Expression* proto = operatorToExpressionProto(oper);
			if (proto == nullptr) return nullptr;

			auto newExpr = proto->createProto();
			newExpr->initialize(
				0,
				recurParse(subFormula1, &valid1),
				recurParse(subFormula2, &valid2)
			);
			return newExpr;
		}
	}

	return nullptr;
}

int FormulaParser::parse(const string pFormula, unique_ptr<Expression>& pTarget)
{
	string formatted = pFormula;

	for (auto& expr : supportedExpressions)
	{
		formatted = expr->formatFormula(formatted);
	}

	int validCode = validateFormula(formatted);
	if (validCode >= 0)
	{
		pTarget = recurParse(formatted, &validCode);

		return validCode < 0 ? validCode : 0;
	}

	return validCode;
}
