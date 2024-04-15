#include "precompiler.h"

bool accountLogOrReg()
{
	displayEntryPage();

	int userInput = 0;
	while (userInput != 49 && userInput != 50)
	{
		userInput = _getch();
	}

	if (userInput == 49)
	{
		return true;
	}

	return false;
}

bool userStudentOrTeacher(bool logOrReg)
{
	userType(logOrReg);

	int userInput = 0;
	while (userInput != 49 && userInput != 50)
	{
		userInput = _getch();
	}

	if (userInput == 49)
	{
		return true;
	}

	return false;
}