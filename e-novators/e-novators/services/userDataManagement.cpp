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

// Loading/Rendering all textures
void textureRenderer()
{
	// Base layer
	background = LoadTexture("../../sprites/windows-design/mainWindowFHD.png");
	exitButton = LoadTexture("../../sprites/buttons/exitButton.png");
	backButton = LoadTexture("../../sprites/buttons/backButton.png");
	classButton = LoadTexture("../../sprites/buttons/classButton.png");

	// Top layer buttons
	english = LoadTexture("../../sprites/TEMP-Buttons/english.png");
	bulgarian = LoadTexture("../../sprites/TEMP-Buttons/bulgarian.png");
	german = LoadTexture("../../sprites/TEMP-Buttons/german.png");
	mathematics = LoadTexture("../../sprites/TEMP-Buttons/mathematics.png");

	// Mid layer buttons
	programming = LoadTexture("../../sprites/TEMP-Buttons/programming.png");
	history = LoadTexture("../../sprites/TEMP-Buttons/history.png");
	geography = LoadTexture("../../sprites/TEMP-Buttons/geography.png");
	philosophy = LoadTexture("../../sprites/TEMP-Buttons/philosophy.png");

	// Bottom layer buttons
	digitalArts = LoadTexture("../../sprites/TEMP-Buttons/digitalArts.png");
	biology = LoadTexture("../../sprites/TEMP-Buttons/Biology.png");
	chemistry = LoadTexture("../../sprites/TEMP-Buttons/Chemistry.png");
}

// Unloading all textures
void textureUnloader()
{
	UnloadTexture(background);
	UnloadTexture(backButton);
	UnloadTexture(exitButton);
	UnloadTexture(classButton);
	UnloadTexture(english);
	UnloadTexture(bulgarian);
	UnloadTexture(german);
	UnloadTexture(mathematics);
	UnloadTexture(programming);
	UnloadTexture(history);
	UnloadTexture(geography);
	UnloadTexture(philosophy);
	UnloadTexture(digitalArts);
	UnloadTexture(biology);
	UnloadTexture(chemistry);
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

int generateUserStatistics()
{
	/*std::random_device avgStudentGrade;
	std::uniform_int_distribution<float> rangeGrade(2, 6);

	std::random_device classMembers;
	std::uniform_int_distribution<int> rangeClass(1, 24);

	std::random_device graduation;
	std::uniform_int_distribution<int> rangeGraduation(1, 503);*/

	return 1;
}

bool checkIfClicked(int x, int y, Texture2D image, int imageX, int imageY)
{
	if ((x >= imageX && x <= imageX + image.width) && (y >= imageY && y <= imageY + image.height))
	{
		return true;
	}
	else
	{
		return false;
	}
}