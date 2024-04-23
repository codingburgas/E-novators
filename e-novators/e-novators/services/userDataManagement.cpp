#include "precompiler.h"
#include "render.h"

static Button button;

// Wait for user input
void waitForKey()
{
	// Check if the "Enter" key is pressed
	int userInput = 0;
	while (userInput != 13)
	{
		userInput = _getch();
	}
}

// Check if user wants to login/register
bool accountLogOrReg()
{
	// Let's the user choose between login and register
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

// Check if user is a teacher/student
bool userStudentOrTeacher(bool logOrReg)
{
	// Determines whether the user is a student or a teacher
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
	profilePictures[0] = LoadTexture("../../sprites/user-profile-designs/profile-beige.png");
	profilePictures[1] = LoadTexture("../../sprites/user-profile-designs/profile-cyan.png");
	profilePictures[2] = LoadTexture("../../sprites/user-profile-designs/profile-gold.png");
	profilePictures[3] = LoadTexture("../../sprites/user-profile-designs/profile-green.png");
	profilePictures[4] = LoadTexture("../../sprites/user-profile-designs/profile-indigo.png");
	profilePictures[5] = LoadTexture("../../sprites/user-profile-designs/profile-orange.png");
	profilePictures[6] = LoadTexture("../../sprites/user-profile-designs/profile-red.png");

	// Profile pictures layer - teachers
	profilePictures[7] = LoadTexture("../../sprites/user-profile-designs/teachers/profile-1-t.png");
	profilePictures[8] = LoadTexture("../../sprites/user-profile-designs/teachers/profile-2-t.png");
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

	delete[] profilePictures;
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

// Generate student statistics
std::string generateUserStatistics()
{
	std::string userStatistics = "";

	std::random_device avgStudentGrade;
	std::uniform_real_distribution<float> rangeGrade(2, 6);
	userStatistics += std::to_string(rangeGrade(avgStudentGrade)) + " ";

	std::random_device classMembers;
	std::uniform_int_distribution<int> rangeClass(1, 24);
	userStatistics += std::to_string(rangeClass(classMembers)) + " ";

	std::random_device graduation;
	std::uniform_int_distribution<int> rangeGraduation(1, 503);
	userStatistics += std::to_string(rangeGraduation(graduation));

	return userStatistics;
}

// Check if a button is clicked
bool checkIfClicked(int x, int y, Texture2D image, int imageX, int imageY)
{
	// Defines whether a given point is within an area
	if ((x >= imageX && x <= imageX + image.width) && (y >= imageY && y <= imageY + image.height))
	{
		return true;
	}
	else
	{
		return false;
	}
}