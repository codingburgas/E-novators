#include "precompiler.h"

// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D background;

void sceneMagager()
{
	ManageWindow();

	textureRenderer();

	int windowDeterminer = 1;
	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawTexture(background, 0, 0, RAYWHITE);
		
		

	Button::GetInstance()->drawButton(button.menuButtons[0]);
		DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 100) / 2, 488, 30, menuTextColor);
		mainWindowFunctions();
		

		EndDrawing();
	}

	
	CloseWindow();
}

void mainWindow()			// --Same as teacher window--
{
	UnloadTexture(background);
	ClearBackground(BLACK);
}

void profileWindow()		// --Same as teacher window--
{
	Button::GetInstance()->drawButton(button.menuButtons[0]);
	DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 30) / 2, 488, 30, menuTextColor);
	mainWindowFunctions();


	EndDrawing();
}

void schoolWindow()			// --Same as teacher window--
{

}

void assignmentWindowStudent()
{

}


// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()
{
	
}

void schoolLibrary()		// --Same as student window (exept with different options)--
{
	
}