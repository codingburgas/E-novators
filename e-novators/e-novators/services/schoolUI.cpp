#include "precompiler.h"
// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D background;
extern Texture2D exitButton;
extern Texture2D backButton;
extern Texture2D classButton;

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
extern int windowsTransition;
extern bool closeKey;

void sceneMagager(int userPFP)
{
	system("cls");
	system("color f0");

	InitWindow(1920, 1080, "E-novators");
	SetTargetFPS(60);
	ToggleFullscreen();

	textureRenderer();

	bool windowsTransitionError = false;
	while (!WindowShouldClose() && closeKey == false)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, RAYWHITE);

		DrawTexture(exitButton, GetScreenWidth() - 100, 10, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (checkIfClicked(GetMouseX(), GetMouseY(), exitButton, GetScreenWidth() - 100, 10))
			{
				closeKey = true;
			}
		}

		DrawTexture(classButton, GetScreenWidth() - 320, 33, RAYWHITE);

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
	Button::GetInstance()->drawButton(button.menuButtons[0]);
	DrawText("Go to 2nd window", screenWidth / 2 - MeasureText("Go to 2nd window", 30) / 2 - 15, 515, 30, menuTextColor);

	if (Button::GetInstance()->isClicked(button.menuButtons[0]))
	{
		windowsTransition = 2;
	}
}

void schoolWindow()			// --Same as teacher window--	ID: 2
{
	DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 33))
		{
			windowsTransition = 1;
		}
	}

	// Goshe brat slagai tuk butonite
}

void assignmentWindowStudent()							//	ID: 3
{

}

// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()							//	ID: 4
{

}

void schoolLibrary()		// --Same as student window (exept with different options)--		ID: 5
{

}