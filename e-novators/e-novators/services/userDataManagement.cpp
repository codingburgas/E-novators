#include "precompiler.h"
#include "render.h"

static Button button;

void waitForKey()
{
	// Check if the "Enter" key is pressed
	int userInput = 0;
	while (userInput != 13)
	{
		userInput = _getch();
	}
}

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

void textureRenderer()
{
	exitButton = LoadTexture("../../sprites/windows-design/exitButton.png");
	background = LoadTexture("../../sprites/windows-design/mainWindowFHD.png");
}

void textureUnloader()
{
	UnloadTexture(background);
}

// Considered as Entry Violation (EV) after 5 failed login attempts
void entryViolation()
{
	system("cls");
	std::cout << "Sorry, out of attempts!";
}

// Chose profile picture for student/teacher
int generateUserPFP(bool studentPFP)
{
	if (studentPFP)
	{
		std::random_device rd;
		std::uniform_int_distribution<int> range(1, 7);
		return range(rd);
	}
	else
	{
		std::random_device rd;
		std::uniform_int_distribution<int> range(1, 2);
		return range(rd);
	}
}