#include "precompiler.h"
// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D profile_red;
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
	DrawText("Go to 2nd \n\n window", screenWidth / 2 - MeasureText("Go to 2nd window", 30) / 2 + 60, 515, 30, menuTextColor);

	DrawText("Georgi Ivanov", 145, 50, 40, BLACK);
	DrawTexture(profile_red, 30, 30, WHITE);

	if (Button::GetInstance()->isClicked(button.menuButtons[0]))
	{
		windowsTransition = 2;
	}
}

void schoolWindow()			// --Same as teacher window--	ID: 2
{
	DrawText("Georgi Ivanov", 145, 50, 40, BLACK);
	DrawTexture(profile_red, 30, 30, WHITE);

	DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{

		if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 33))
		{
			windowsTransition = 1;
		}
	}

	// Top layer buttons

	// Bulgarian button
	DrawTexture(bulgarian, GetScreenWidth() - 1090, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		DrawText("Georgi Ivanov", 145, 50, 40, BLACK);
		DrawTexture(profile_red, 30, 30, WHITE);
		if (checkIfClicked(GetMouseX(), GetMouseY(), bulgarian, GetScreenWidth() - 1090, 200))
		{
			windowsTransition = 3;
		}
	}

	// English button

	DrawTexture(english, GetScreenWidth() - 1300, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), english, GetScreenWidth() - 1300, 200))
		{
			windowsTransition = 3;
		}
	}

	// German button

	DrawTexture(german, GetScreenWidth() - 1530, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), german, GetScreenWidth() - 1530, 200))
		{
			windowsTransition = 3;
		}
	}

	// Mathematics button

	DrawTexture(mathematics, GetScreenWidth() - 830, 200, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), mathematics, GetScreenWidth() - 830, 200))
		{
			windowsTransition = 3;
		}
	}

	// Middle layer buttons
	
	// Programing button

	DrawTexture(programming, GetScreenWidth() - 800, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), programming, GetScreenWidth() - 800, 500))
		{
			windowsTransition = 3;
		}
	}

	// History button

	DrawTexture(history, GetScreenWidth() - 1580, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), history, GetScreenWidth() - 1580, 500))
		{
			windowsTransition = 3;
		}
	}

	// Geography button

	DrawTexture(geography, GetScreenWidth() - 1360, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), geography, GetScreenWidth() - 1360, 500))
		{
			windowsTransition = 3;
		}
	}

	// Philosophy button

	DrawTexture(philosophy, GetScreenWidth() - 1080, 500, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), philosophy, GetScreenWidth() - 1110, 500))
		{
			windowsTransition = 3;
		}
	}

	// Bottom layer buttons

	// Digital Arts button

	DrawTexture(digitalArts, GetScreenWidth() - 820, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), digitalArts, GetScreenWidth() - 820, 800))
		{
			windowsTransition = 3;
		}
	}

	// Biology button

	DrawTexture(biology, GetScreenWidth() - 1150, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), biology, GetScreenWidth() - 1150, 800))
		{
			windowsTransition = 3;
		}
	}

	// Chemistry button

	DrawTexture(chemistry, GetScreenWidth() - 1550, 800, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), chemistry, GetScreenWidth() - 1550, 800))
		{
			windowsTransition = 3;
		}
	}
	
}

void assignmentWindowStudent()							//	ID: 3
{
	DrawText("Georgi Ivanov", 145, 50, 40, BLACK);
	DrawTexture(profile_red, 30, 30, WHITE);

	DrawTexture(backButton, GetScreenWidth() - 500, 33, RAYWHITE);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), backButton, GetScreenWidth() - 500, 33))
		{
			windowsTransition = 2;
		}
	}

	
}





// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()							//	ID: 4
{

}

void schoolLibrary()		// --Same as student window (exept with different options)--		ID: 5
{

}