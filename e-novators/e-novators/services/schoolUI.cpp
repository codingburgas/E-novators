#include "precompiler.h"
#include "closer.h"
// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D background;
extern Texture2D exitButton;
extern int windowsTransition;

void sceneMagager()
{
	InitWindow(1920, 1080, "E-novators");
	SetTargetFPS(60);
	//ToggleFullscreen();

	textureRenderer();

	bool windowsTransitionError = false;
	while (!WindowShouldClose() && closeKey == false)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, RAYWHITE);

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
	Button::GetInstance()->drawButton(button.menuButtons[0]);// Draws menu button
	DrawText("English", screenWidth / 2 - MeasureText("English", 30) / 2, 488, 30, menuTextColor); // Draws menu button

	Button::GetInstance()->drawButton(button.menuButtons[1]);// Draws menu button
	DrawText("Mathematics", (screenWidth / 3) - MeasureText("Mathematics", 30) / 2, 488, 30, menuTextColor); // Draws menu button

	Button::GetInstance()->drawButton(button.menuButtons[2]);// Draws menu button
	DrawText("Mathematics", (screenWidth / 4) - MeasureText("Geography", 30) / 2, 488, 30, menuTextColor); // Draws menu button

	Button::GetInstance()->drawButton(button.menuButtons[3]);// Draws menu button
	DrawText("Mathematics", (screenWidth / 5) - MeasureText("Geography", 30) / 2, 488, 30, menuTextColor); // Draws menu button

	DrawTexture(exitButton, GetScreenWidth() - 100, 10, RAYWHITE);

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (checkIfClicked(GetMouseX(), GetMouseY(), exitButton, GetScreenWidth() - 100, 10))
		{
			closeKey = true;
		}
	}


	if (Button::GetInstance()->isClicked(button.menuButtons[0]))	// Buttons toggle menu items/close window
	{
		windowsTransition = 2;
	}


}

void schoolWindow()			// --Same as teacher window--	ID: 2
{

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