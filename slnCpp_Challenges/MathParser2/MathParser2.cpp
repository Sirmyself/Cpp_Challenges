// MathParser2.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>
#include "stdafx.h"
#include "baseFunctions.h"
#include "FormulaParser.h"

using namespace std;

int evaluateFormula(char pFormula[]);

const int MAX_FORMULA_LENGTH = 255;

int main()
{
	int err = 0;
	int cntr = 1;
	do
	{
		char formula[MAX_FORMULA_LENGTH] = "";
		cout << "\nFormula #" << cntr++ << " :\n";
		cin >> formula;
		err = evaluateFormula(formula);
	} while (!askIsUserDone());

    return err;
}

int evaluateFormula(char pFormula[])
{
	P_Expression a = new Addition(new Expression(2.555), new Expression(3));

	cout << "testing (simple Addition) : " << a->evaluate() << "\n";
	system("pause");

	int err = 0;
	cout << "here is your formula : " << pFormula;

	return err;
}