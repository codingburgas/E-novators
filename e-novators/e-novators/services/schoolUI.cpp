#include "precompiler.h"

// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;

void mainWindow()			// --Same as teacher window--
{
	system("70");

	InitWindow(1920, 1080, "e-Class Edge");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		mainWindowFunctions();

		Button::GetInstance()->drawButton(button.menuButtons[0]);	
		DrawText("Start", screenWidth / 2 - MeasureText("Start", 30) / 2, 488, 30, menuTextColor);
		

		EndDrawing();
	}

	CloseWindow();
}

void profileWindow()		// --Same as teacher window--
{
	
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