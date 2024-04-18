#include "services/sceneManager.h"
#include "services/buttons.h"
static Button button;

void SceneManager()
{

	if (menu)
	{
		mainWindow();

		if (Button::GetInstance()->isClicked(button.menuButtons[0]))	// Buttons toggle menu items/close window
		{

			menu = false;
			start = true;

		}



	}




	else if (start)		// Opens game scene
	{
		ClearBackground(BLACK);

		profileWindow();

	}



}

