#include "services/precompiler.h"

int main()
{
	system("MODE CON COLS=186 LINES=50");	// Setting CMD's resolution(cols, lines) to 186x50 without resize lock - PUBLIC/ORGANISATION PCs ONLY

	/*// Setting CMD's resolution(cols, lines) to 126x50 and locking resizing;				RAYLIB.H CLASHES WITH WINDOWS.H			eClass Edge  (e-Class Edge)
	HWND console = GetConsoleWindow();

	SMALL_RECT rect = { 0, 0, 186, 50 }; // Adjust the values as needed
	SetConsoleWindowInfo(console, TRUE, &rect);
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);*/

	std::ifstream teacherDBREAD("database/users-teachers.txt");
	std::ifstream studentsDBREAD("database/users-students.txt");
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