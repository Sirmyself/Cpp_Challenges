#include "stdafx_c.h"
#include "baseFunctions.h"

using namespace std;

namespace perso {
	static char lineStr[] = "\n\n=================================\n";
	static map<int, string> errorList;

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
		return askIsUserDone((char*)"\nDo you want to continue? ", 'n', 'y');
	}

	bool askIsUserDone(char* message, char isDone, char notDone)
	{
		char answer = '\0';
		char buffer[255] = {};

		while (answer != tolower(notDone) && answer != tolower(isDone))
		{
			line();
			std::cout << message << "(" << notDone << "/" << isDone << ") : ";
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

	void setErrorCode(int pIndex, string pMessage)
	{
		errorList[pIndex] = pMessage;
	}

	void logError(int pErrorCode, ostream& pOut)
	{
		logError(pErrorCode, pOut, "\n\nPress any key to continue");
	}

	void logError(int pErrorCode, ostream& pOut, string pContinueMessage)
	{
		if (errorList.find(pErrorCode) != errorList.end() && pErrorCode != 0)
		{
			pOut << "\n" << errorList[pErrorCode] << "\n";
			pause(pContinueMessage);
		}
	}

	void pause()
	{
		cin.ignore();
	}

	void pause(string message)
	{
		cout << message << "\n";
		cin.ignore();
		cin.ignore();
	}
}