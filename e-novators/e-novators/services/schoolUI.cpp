#include "precompiler.h"
#include "def.h"
#include "buttons.h"

// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;

void mainWindow()			// --Same as teacher window--
{
	system("70");

	InitWindow(1980, 1080, "e-Class Edge");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		Button::GetInstance()->drawButton(button.menuButtons[0]);		// Draws menu buttons
		DrawText("Start", screenWidth / 2 - MeasureText("Start", 30) / 2, 488, 30, menuTextColor);

		EndDrawing();
	}

	CloseWindow();
}

void profileWindow()		// --Same as teacher window--
{
	InitWindow(1980, 1080, "e-Class Edge");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Make "1st Window" here

		EndDrawing();
	}

	CloseWindow();
}

void schoolWindow()			// --Same as teacher window--
{
	InitWindow(1980, 1080, "e-Class Edge");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Make "1st Window" here

		EndDrawing();
	}

	CloseWindow();
}

void assignmentWindowStudent()
{
	InitWindow(1980, 1080, "e-Class Edge");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Make "1st Window" here

		EndDrawing();
	}

	CloseWindow();
}


// --ALL WINDOWS LISTED BELOW ARE *TEACHER RELATED*--

void assignmentWindowTeacher()
{
	InitWindow(1980, 1080, "e-Class Edge");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Make "1st Window" here

		EndDrawing();
	}

	CloseWindow();
}

void schoolLibrary()		// --Same as student window (exept with different options)--
{
	InitWindow(1980, 1080, "e-Class Edge");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Make "1st Window" here

		EndDrawing();
	}

	CloseWindow();
}