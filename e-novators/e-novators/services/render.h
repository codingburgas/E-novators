#pragma once

int windowsTransition = 1;
bool closeKey = false;

// Base layer
Texture2D background;
Texture2D exitButton;
Texture2D backButton;
Texture2D classButton;

// Top layer buttons
Texture2D english;
Texture2D bulgarian;
Texture2D german;
Texture2D mathematics;

// Mid layer buttons
Texture2D programming;
Texture2D history;
Texture2D geography;
Texture2D philosophy;

// Bottom layer buttons
Texture2D digitalArts;
Texture2D biology;
Texture2D chemistry;

// Profile pictures layer - students
Texture2D studentsPFPRED;
Texture2D studentsPFPBEIGE;
Texture2D studentsPFPCYAN;
Texture2D studentsPFPGOLD;
Texture2D studentsPFPGREEN;
Texture2D studentsPFPINDIGO;
Texture2D studentsPFPORANGE;

// Profile pictures layer - teachers
Texture2D teachersPFPGRAY;
Texture2D teachersPFPWHITE;

// Profile pictures main array
Texture2D buttons[] = {
	studentsPFPRED, studentsPFPBEIGE, studentsPFPCYAN,
	studentsPFPGOLD, studentsPFPGREEN, studentsPFPINDIGO,
	studentsPFPORANGE, teachersPFPGRAY, teachersPFPWHITE
};