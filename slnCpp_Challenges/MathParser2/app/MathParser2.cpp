#include "baseFunctions.h"
#include "FormulaParser.h"

#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;
using namespace perso;

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

		logError(err, cout);
	} while (!askIsUserDone());

	return err;
}

void initErrorCodes()
{
	setErrorCode(0, "");
	setErrorCode(-1, "Parentheses are not parsable\n(please verify correspondence of parentheses and their count).");
	setErrorCode(-2, "Unsupported operator found.");
	setErrorCode(-3, "Empty parentheses found.");
	setErrorCode(-4, "Missing operators between parentheses.");
	setErrorCode(-5, "An error occured while parsing the parentheses in the formula : corresponding parenthesis not found.");
	setErrorCode(-6, "The splitting function could not parse the formula with\nthe current supported expressions.");
	setErrorCode(-10, "An error occured when parsing the parenthesis (given index did not point ot a parenthesis.");
	setErrorCode(-11, "The formula is empty.");
	setErrorCode(-999, "An unsupported error occured");
}

int evaluateFormula(char pFormula[])
{
	FormulaParser parser;
	unique_ptr<Expression> result;
	int error = parser.parse(pFormula, result);

	if (error >= 0)
	{
		cout << pFormula << " = " << setprecision(9) << result->evaluate();
		pause();
	}

	return error;
}

string instructions()
{
	string retVal = "";
	retVal.append("\n").append("Enter the formula you want to evaluate below.");
	retVal.append("\n").append("    - Please use the period character '.' for decimal values.");

	return retVal;
}
