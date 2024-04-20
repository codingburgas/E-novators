#include "precompiler.h"

// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;

void mainWindow()			// --Same as teacher window--
{
	system("70");

	InitWindow(1920, 1080, "e-Class Edge");
	ToggleFullscreen();
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		mainWindowFunctions();
		ClearBackground(RAYWHITE); //background
		DrawRectangle(0, 0, 1920, 10, DARKGRAY);         //frame
		DrawRectangle(1920, 1080, -1920, -10, DARKGRAY); //frame
		DrawRectangle(0, 0, 10, 1080, DARKGRAY);	//frame
		DrawRectangle(1920, 1080, -10, -1080, DARKGRAY); //frame

		DrawRectangle(0, 100, 1920, 5, DARKGRAY);
		DrawCircle(60, 55, 40, BLACK);


		Button::GetInstance()->drawButton(button.menuButtons[0]);	
		DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 30) / 2, 488, 30, menuTextColor);
		

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