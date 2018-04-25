#include "stdafx.h"
#include "baseFunctions.h"


char* s_line()
{
	return (char*)lineStr;
}

void line()
{
	std::cout << lineStr;
}

void line(std::ostream out)
{
	out << lineStr;
}

void changeDefaultLine(char* newLine)
{
	strcpy_s(lineStr, newLine);
}

bool askIsUserDone(void)
{
	return askIsUserDone((char*)"\nDo you want to continue?", 'n', 'y');
}

bool askIsUserDone(char* message, char isDone, char notDone)
{
	char answer = '\0';
	char buffer[255] = {};

	while (answer != tolower(notDone) && answer != tolower(isDone))
	{
		line();
		std::cout << message << "(" << notDone << "/" << isDone << ")";
		std::cin >> buffer;
		if (strlen(buffer) > 1)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		else
			answer = buffer[0];
		system("cls");
		answer = tolower(answer);
	}

	return answer == tolower(isDone);
}