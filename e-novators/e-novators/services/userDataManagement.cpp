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

void mainWindowFunctions()
{
	
	if (Button::GetInstance()->isClicked(button.menuButtons[0]))	// Buttons toggle menu items/close window
	{

		mainWindow();

	}
}

void textureRenderer()
{
	background = LoadTexture("../../sprites/windows-design/mainWindowFHD.png");
}

void ManageWindow() // Sets basic window parameters
{

	system("cls");
	system("color f0");

	InitWindow(1920, 1080, "e-Class Edge");
	ToggleFullscreen();
	SetTargetFPS(60);
	
}