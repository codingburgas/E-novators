#include "precompiler.h"

// --ALL WINDOWS LISTED BELOW ARE *STUDENT RELATED*--

static Button button;
extern Texture2D background;

void sceneMagager()
{
	system("cls");
	system("color f0");

	InitWindow(1920, 1080, "e-Class Edge");
	ToggleFullscreen();
	SetTargetFPS(60);

	textureRenderer();

	int windowDeterminer = 1;
	while (!WindowShouldClose())
	{
		BeginDrawing();

		mainWindowFunctions();
		ClearBackground(RAYWHITE);
		


		Button::GetInstance()->drawButton(button.menuButtons[0]);
		DrawText("10V class", screenWidth / 2 - MeasureText("10V class", 30) / 2, 488, 30, menuTextColor);


		EndDrawing();
	}

	UnloadTexture(background);
	CloseWindow();
}

void mainWindow()			// --Same as teacher window--
{
	DrawTexture(background, 0, 0, RAYWHITE);
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