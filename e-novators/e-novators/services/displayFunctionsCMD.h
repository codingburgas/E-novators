#pragma once

void displayEntryPage();
void userType(bool userType);
void displayStudentRegLog(std::ifstream& studentsDBREAD, std::string& username, std::string& password);
void displayTeacherRegLog(std::ifstream& teachersDBREAD, std::string& username, std::string& password);