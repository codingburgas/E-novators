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
	english = LoadTexture("../../sprites/buttons/english.png");
	bulgarian = LoadTexture("../../sprites/buttons/bulgarian.png");
	german = LoadTexture("../../sprites/buttons/german.png");
	mathematics = LoadTexture("../../sprites/buttons/mathematics.png");

	// Mid layer buttons
	programming = LoadTexture("../../sprites/buttons/programming.png");
	history = LoadTexture("../../sprites/buttons/history.png");
	geography = LoadTexture("../../sprites/buttons/geography.png");
	philosophy = LoadTexture("../../sprites/buttons/philosophy.png");

	// Bottom layer buttons
	digitalArts = LoadTexture("../../sprites/buttons/digitalArts.png");
	biology = LoadTexture("../../sprites/buttons/biology.png");
	chemistry = LoadTexture("../../sprites/buttons/chemistry.png");

	// Profile pictures layer - students
	studentsPFPRED = LoadTexture("../../sprites/user-profile-designs/profile-red.png");
	studentsPFPBEIGE = LoadTexture("../../sprites/user-profile-designs/profile-beige.png");
	studentsPFPCYAN = LoadTexture("../../sprites/user-profile-designs/profile-cyan.png");
	studentsPFPGOLD = LoadTexture("../../sprites/user-profile-designs/profile-gold.png");
	studentsPFPGREEN = LoadTexture("../../sprites/user-profile-designs/profile-green.png");
	studentsPFPINDIGO = LoadTexture("../../sprites/user-profile-designs/profile-indigo.png");
	studentsPFPORANGE = LoadTexture("../../sprites/user-profile-designs/profile-orange.png");

	// Profile pictures layer - teachers
	teachersPFPGRAY = LoadTexture("../../sprites/user-profile-designs/teachers/profile-1-t.png");
	teachersPFPWHITE = LoadTexture("../../sprites/user-profile-designs/teachers/profile-2-t.png");
}

// Unloading all textures
void textureUnloader()
{
	// Unloading base textures
	UnloadTexture(background);
	UnloadTexture(backButton);
	UnloadTexture(exitButton);
	UnloadTexture(classButton);

	// Unloading class button textures
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

	// Unloading profile picture textures
	UnloadTexture(studentsPFPRED);
	UnloadTexture(studentsPFPBEIGE);
	UnloadTexture(studentsPFPCYAN);
	UnloadTexture(studentsPFPGOLD);
	UnloadTexture(studentsPFPGREEN);
	UnloadTexture(studentsPFPINDIGO);
	UnloadTexture(studentsPFPORANGE);
	UnloadTexture(teachersPFPGRAY);
	UnloadTexture(teachersPFPWHITE);

	delete[] buttons;
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