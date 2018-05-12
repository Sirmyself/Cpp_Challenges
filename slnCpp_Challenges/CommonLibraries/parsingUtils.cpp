#include "stdafx_c.h"
#include "parsingUtils.h"

using namespace std;

size_t checkCorrespondingParenthesis(const string pFormula, unsigned int firstIndex)
{
	unsigned int i = firstIndex;
	unsigned int opening = 0, closing = 0;

	while (i < pFormula.length())
	{
		if (pFormula[i] == '(') ++opening;
		if (pFormula[i] == ')') ++closing;

		if (opening == closing)
			return i;
		else
			++i;
	}

	return -5;
}

string removeUselessParentheses(const string pString)
{
	string retVal = pString;
	while (retVal[0] == '(' && checkCorrespondingParenthesis(retVal, 0) == retVal.length() - 1)
	{
		retVal = retVal.substr(1, retVal.length() - 2); // -2 for both parentheses
	}
	return retVal;
}