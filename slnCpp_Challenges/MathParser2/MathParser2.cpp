#include "stdafx.h"

#include "baseFunctions.h"
#include "FormulaParser.h"

#include <iostream>
#include <iomanip>

using namespace std;

void initErrorCodes();
int evaluateFormula(char pFormula[]);
string instructions();

const int MAX_FORMULA_LENGTH = 255;

int main()
{
	initErrorCodes();

	int err = 0;
	int cntr = 1;
	do
	{
		char formula[MAX_FORMULA_LENGTH] = "";

		cout << instructions();
		line();

		cout << "\nFormula #" << cntr++ << " :\n";
		cin >> formula;
		err = evaluateFormula(formula);

		logError(0, cout);
	} while (!askIsUserDone());

    return err;
}

void initErrorCodes()
{
	// set customized error messages here along with the corresponding error code.
	setErrorCode(0, "");
}

int evaluateFormula(char pFormula[])
{
	P_FParser parser = new FormulaParser();
	P_Expression a = parser->parse(pFormula);

	cout << pFormula << " = " << setprecision(9) << a->evaluate();
	pause();

	return 0;
}

string instructions()
{
	string retVal = "";
	retVal.append("\n").append("Enter the formula you want to evaluate below.");
	retVal.append("\n").append("  - Please use the period character '.' for decimal values.");
	retVal.append("\n").append("  - Please use the complete syntax with parentheses\n    (do not use the (a)(b) syntax to multiply them)");

	return retVal;
}