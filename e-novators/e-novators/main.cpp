#include "services/precompiler.h"

// eClass Edge(e - Class Edge)

int main()
{
	system("cls");
	system("color 0f");
	system("MODE CON COLS=186 LINES=50");	// Setting CMD's resolution(cols, lines) to 186x50 without resize lock - PUBLIC/ORGANISATION PCs ONLY

	std::ifstream teacherDBREAD("database/users-teachers.txt");  // Database for teacher's login
	std::ifstream studentsDBREAD("database/users-students.txt");  // Database for student's  login
	std::string* username = new std::string(), * password = new std::string();

	if (!(teacherDBREAD.is_open() && studentsDBREAD.is_open()))
	{
		std::cout << "Error opening database\nClosing application...";
	}
	else
	{
		bool entryType = accountLogOrReg();
		if (userStudentOrTeacher(entryType))
		{
			displayStudentRegLog(studentsDBREAD, *username, *password, entryType);
		}
		else
		{
			displayTeacherRegLog(teacherDBREAD, *username, *password, entryType);
		}
	}

	delete(username);
	delete(password);
	teacherDBREAD.close();
	studentsDBREAD.close();

}