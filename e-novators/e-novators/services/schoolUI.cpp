#include "precompiler.h"
#include "closer.h"
// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D background;
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

		Button::GetInstance()->drawButton(button.menuButtons[0]);
		DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 100) / 2, 488, 30, menuTextColor);


		switch (windowsTransition)
		{
		case 1: mainWindow(); break;
		case 2: profileWindow(); break;
		case 3: schoolWindow(); break;
		case 4: assignmentWindowStudent(); break;
		case 5: assignmentWindowTeacher(); break;
		case 6: schoolLibrary(); break;
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

	Button::GetInstance()->drawButton(button.menuButtons[4]);
	DrawText("Exit", screenWidth - 100 - MeasureText("Exit", 30) / 2, 60, 30, menuTextColor);


	if (Button::GetInstance()->isClicked(button.menuButtons[0]))	// Buttons toggle menu items/close window
	{
		windowsTransition = 2;
	}

	if (Button::GetInstance()->isClicked(button.menuButtons[4])) // Checks if the button is clicked
	{

		closeKey = true;

	}


}

void profileWindow()		// --Same as teacher window--	ID: 2
{
	Button::GetInstance()->drawButton(button.backButton);
	DrawText("Back", (screenWidth / 12) - 10 - MeasureText("Back", 30) / 2, 100, 30, menuTextColor);

	Button::GetInstance()->drawButton(button.menuButtons[4]);
	DrawText("Exit", screenWidth - 100 - MeasureText("Exit", 30) / 2, 60, 30, menuTextColor);

	if (Button::GetInstance()->isClicked(button.menuButtons[4])) // Checks if they are clicked
	{

		closeKey = true;

	}

	if (Button::GetInstance()->isClicked(button.backButton))	// Buttons toggle menu items/close window
	{
		windowsTransition = 1;
	}
}

void schoolWindow()			// --Same as teacher window--	ID: 3
{

}

void assignmentWindowStudent()							//	ID: 4
{

}


// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()							//	ID: 5
{

}

void schoolLibrary()		// --Same as student window (exept with different options)--		ID: 6
{

}