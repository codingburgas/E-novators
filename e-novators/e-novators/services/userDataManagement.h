#pragma once

void waitForKey();
bool accountLogOrReg();
bool userStudentOrTeacher(bool userType);
void textureRenderer();
void textureUnloader();
void entryViolation();
int generateUserPFP(bool studentPFP);
int generateUserStatistics();
bool checkIfClicked(int x, int y, Texture2D image, int imageX, int imageY);