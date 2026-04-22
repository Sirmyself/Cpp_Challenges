#include "parsingUtils.h"

using namespace std;

int checkCorrespondingParenthesis(const string pFormula, int firstIndex)
{
	int i = firstIndex;
	int opening = 0, closing = 0;

	int mod = 0;
	if (pFormula[i] == '(')
	{
		mod = 1;
	}
	else if (pFormula[i] == ')')
	{
		mod = -1;
	}
	else
	{
		return -10;
	}

	while (i >= 0 && i < static_cast<int>(pFormula.length()))
	{
		if (pFormula[i] == '(') ++opening;
		if (pFormula[i] == ')') ++closing;

		if (opening == closing)
			return i;
		else
			i += mod;
	}

	return -5;
}

string removeUselessParentheses(const string pString)
{
	string retVal = pString;
	while (!retVal.empty() && retVal[0] == '(' && checkCorrespondingParenthesis(retVal, 0) == static_cast<int>(retVal.length()) - 1)
	{
		retVal = retVal.substr(1, retVal.length() - 2);
	}
	return retVal;
}
