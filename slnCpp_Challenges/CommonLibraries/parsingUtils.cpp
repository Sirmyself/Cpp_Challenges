#include "stdafx_c.h"
#include "parsingUtils.h"

using namespace std;

//following here is the old algorithm for reference purpose.
/*size_t checkCorrespondingParenthesis(const string pFormula, unsigned int firstIndex)
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
}*/

//here is the new algorithm to support both opening and closing parenthesis search.
size_t checkCorrespondingParenthesis(const string pFormula, unsigned int firstIndex)
{
	unsigned int i = firstIndex;
	unsigned int opening = 0, closing = 0;
	
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
	    return -10; //probably need to change in order to have a proper error code.
	                //error will be "Error : Given index was not a parenthesis"
	}

	while (i < pFormula.length())
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
	while (retVal[0] == '(' && checkCorrespondingParenthesis(retVal, 0) == retVal.length() - 1)
	{
		retVal = retVal.substr(1, retVal.length() - 2); // -2 for both parentheses
	}
	return retVal;
}
