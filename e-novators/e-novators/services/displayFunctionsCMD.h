#pragma once

void drawTopDesign();
void drawBottomDesign();
void displayEntryPage();
void userType(bool userType);
void displayStudentRegLog(std::ifstream& studentsDBREAD, std::string& username, std::string& password, bool entryType);
void displayTeacherRegLog(std::ifstream& teachersDBREAD, std::string& username, std::string& password, bool entryType);