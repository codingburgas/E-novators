#include "precompiler.h"
// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

// Base layer
static Button button;
extern Texture2D background;
extern Texture2D exitButton;
extern Texture2D backButton;
extern Texture2D classButton;

extern int windowsTransition;
extern bool closeKey;

// Top layer buttons
extern Texture2D english;
extern Texture2D bulgarian;
extern Texture2D german;
extern Texture2D mathematics;

// Mid layer buttons
extern Texture2D programming;
extern Texture2D history;
extern Texture2D geography;
extern Texture2D philosophy;

// Bottom layer buttons
extern Texture2D digitalArts;
extern Texture2D biology;
extern Texture2D chemistry;

// Profile pictures array
extern Texture2D profilePictures[];

int userIDGLOBAL = 0;
bool chosenSubject[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool userTypeEntry;

void sceneMagager(std::string userName, std::string userClass, int userPFP, bool userTypePass)
{
	system("cls");
	system("color f0");

	userTypeEntry = userTypePass;		// Calling global variable - scope resolution operator (::)

	int countSpaces = 0;
	std::ifstream studentsDBREAD("database/users-students.txt");

	// Retrieve student credentials
	const char* username = userName.c_str();
	const char* studentClass = userClass.c_str();

	InitWindow(1920, 1080, "E-novators");
	SetTargetFPS(60);
	//ToggleFullscreen();

	textureRenderer();

	bool windowsTransitionError = false;
	while (!WindowShouldClose() && closeKey == false)
	{
		BeginDrawing();

		// Draw base layer
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, RAYWHITE);
		DrawText("----* eClass Edge *----", MeasureText("----* eClass Edge *----", 45) + 150, 50, 45, BLACK);

		// Draw student info
		DrawTexture(profilePictures[userPFP], 30, 30, RAYWHITE);
		DrawText(username, 145, 50, 45, BLACK);

		if (userTypeEntry)
		{
			DrawTexture(classButton, GetScreenWidth() - 320, 33, RAYWHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (checkIfClicked(GetMouseX(), GetMouseY(), classButton, GetScreenWidth() - 320, 12))
				{
					windowsTransition = 2;
				}
			}

			DrawText(studentClass, GetScreenWidth() - 280, 50, 45, RAYWHITE);
		}

		// Draw exit button
		DrawTexture(exitButton, GetScreenWidth() - 100, 10, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (checkIfClicked(GetMouseX(), GetMouseY(), exitButton, GetScreenWidth() - 100, -11))
			{
				closeKey = true;
			}
		}

		// Check for window change
		switch (windowsTransition)
		{
		case 1: mainWindow(); break;
		case 2: schoolWindow(); break;
		case 3: assignmentWindowStudent(); break;
		case 4: assignmentWindowTeacher(); break;
		case 5: schoolLibrary(); break;
		default: windowsTransitionError = true;
		}

		EndDrawing();
		if (windowsTransitionError) break;
	}

	textureUnloader();
	CloseWindow();

	if (windowsTransitionError)
	{
		std::cout << "\nFATAL ERROR <==> Windows Transition Error!\n";
	}
}

void mainWindow()			// --Same as teacher window--	ID: 1
{
	if (userIDGLOBAL)
	{
		DrawText("INFO HERE", 800, 600, 40, BLACK);
	}
}

void schoolWindow()			// --Same as teacher window--	ID: 2
{
	if (userTypeEntry)
	{
		DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 1;
			}
		}
	}
	else
	{
		DrawTexture(backButton, GetScreenWidth() - 320, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{

			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 1;
			}
		}
	}

	// --* Top layer buttons *--

	// Bulgarian button
	DrawTexture(bulgarian, GetScreenWidth() - 1090, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), bulgarian, GetScreenWidth() - 1090, 179))
		{
			windowsTransition = 3;
			chosenSubject[0] = true;
		}
	}

	// English button

	DrawTexture(english, GetScreenWidth() - 1300, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), english, GetScreenWidth() - 1300, 179))
		{
			windowsTransition = 3;
			chosenSubject[1] = true;
		}
	}

	// German button

	DrawTexture(german, GetScreenWidth() - 1530, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), german, GetScreenWidth() - 1530, 179))
		{
			windowsTransition = 3;
			chosenSubject[2] = true;
		}
	}

	// Mathematics button

	DrawTexture(mathematics, GetScreenWidth() - 830, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), mathematics, GetScreenWidth() - 830, 179))
		{
			windowsTransition = 3;
			chosenSubject[3] = true;
		}
	}

	// --* Middle layer buttons *--
	
	// Programing button

	DrawTexture(programming, GetScreenWidth() - 800, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), programming, GetScreenWidth() - 800, 479))
		{
			windowsTransition = 3;
			chosenSubject[4] = true;
		}
	}

	// History button

	DrawTexture(history, GetScreenWidth() - 1580, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), history, GetScreenWidth() - 1580, 479))
		{
			windowsTransition = 3;
			chosenSubject[5] = true;
		}
	}

	// Geography button

	DrawTexture(geography, GetScreenWidth() - 1360, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), geography, GetScreenWidth() - 1360, 479))
		{
			windowsTransition = 3;
			chosenSubject[6] = true;
		}
	}

	// Philosophy button

	DrawTexture(philosophy, GetScreenWidth() - 1080, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), philosophy, GetScreenWidth() - 1110, 479))
		{
			windowsTransition = 3;
			chosenSubject[7] = true;
		}
	}

	// --* Bottom layer buttons *--

	// Digital Arts button

	DrawTexture(digitalArts, GetScreenWidth() - 820, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), digitalArts, GetScreenWidth() - 820, 779))
		{
			windowsTransition = 3;
			chosenSubject[8] = true;
		}
	}

	// Biology button

	DrawTexture(biology, GetScreenWidth() - 1150, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), biology, GetScreenWidth() - 1150, 779))
		{
			windowsTransition = 3;
			chosenSubject[9] = true;
		}
	}

	// Chemistry button

	DrawTexture(chemistry, GetScreenWidth() - 1550, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), chemistry, GetScreenWidth() - 1550, 779))
		{
			windowsTransition = 3;
			chosenSubject[10] = true;
		}
	}
}

void assignmentWindowStudent()							//	ID: 3
{
	if (userTypeEntry)
	{
		DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 2;
			}
		}
	}
	else
	{
		DrawTexture(backButton, GetScreenWidth() - 320, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{

			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 1;
			}
		}
	}

	// Check which subject is chosen
	for (int i = 0; i < 11; i++)
	{
		if (chosenSubject[i] == true)
		{
			switch (i)
			{
			case 1:; break;
			case 2:; break;
			case 3:; break;
			case 4:; break;
			case 5:; break;
			case 6:; break;
			case 7:; break;
			case 8:; break;
			case 9:; break;
			case 10:; break;
			case 11:; break;
			}
		}
	}
}

// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()							//	ID: 4
{
	if (userTypeEntry)
	{
		DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 2;
			}
		}
	}
	else
	{
		DrawTexture(backButton, GetScreenWidth() - 320, 33, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{

			if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 12))
			{
				windowsTransition = 1;
			}
		}
	}

	// Check which subject is chosen
	for (int i = 0; i < 11; i++)
	{
		if (chosenSubject[i] == true)
		{
			switch (i)
			{
			case 1:; break;
			case 2:; break;
			case 3:; break;
			case 4:; break;
			case 5:; break;
			case 6:; break;
			case 7:; break;
			case 8:; break;
			case 9:; break;
			case 10:; break;
			case 11:; break;
			}
		}
	}
}

void schoolLibrary()		// --Same as teacher window--		ID: 5
{

}