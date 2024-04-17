#pragma once

#include "precompiler.h"
#include "def.h"

class Button
{
public:
	static Button* GetInstance()
	{
		// Check if the instance is not already created
		if (instance == nullptr)
		{
			instance = new Button;
		}
		return instance;
	}

	void drawButton(Rectangle rect);

	// Check if the button is clicked
	bool isClicked(Rectangle rect);

	Rectangle menuButtons[3] = {
		{screenWidth / 2 - menuButtonLength / 2, screenHeight / 2.4, menuButtonLength, menuButtonHeight},

	};	// Sets button size and position

	Rectangle controllsBackButton = { 50, 50 , menuButtonLength, menuButtonHeight }; // Draws the back button in the menu

private:
	static Button* instance;
};