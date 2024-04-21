#include "precompiler.h"

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
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, RAYWHITE);

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
	Button::GetInstance()->drawButton(button.menuButtons[0]);
	DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 30) / 2, 488, 30, menuTextColor);
	
	if (Button::GetInstance()->isClicked(button.menuButtons[0]))	// Buttons toggle menu items/close window
	{
		windowsTransition = 2;
	}
}

void profileWindow()		// --Same as teacher window--	ID: 2
{
	
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