#include "precompiler.h"

// Displaying entry page
void displayEntryPage()
{
	system("cls");

	// Drawing TOP page design
	std::cout << std::setw(70);
	for (int i = 0; i < 50; i++)
	{
		std::cout << '_';
	}
	std::cout << '\n' << std::setw(70) << "/" << std::setw(49) << "\\";

	// Drawing options
	std::cout << '\n' << std::setw(87) << "|Press '1' Login" << '\n' << std::setw(98) << "|Press '2' for Registration" << '\n';
	
	// Drawing BOTTOM page design
	std::cout << std::setw(70) << "\\";
	for (int i = 0; i < 48; i++)
	{
		std::cout << '_';
	}
	std::cout << "/";
}

void userType(bool userType)
{
	system("cls");

	// Drawing TOP page design
	std::cout << std::setw(70);
	for (int i = 0; i < 50; i++)
	{
		std::cout << '_';
	}
	std::cout << '\n' << std::setw(70) << "/" << std::setw(49) << "\\";
	
	// Checking if the user wants to be logged in or be registered
	if (userType)
	{
		// Drawing options
		std::cout << '\n' << std::setw(100) << "|Press '1' to login - student" << '\n' << std::setw(100) << "|Press '2' to login - teacher" << '\n';
	}
	else
	{
		// Drawing options
		std::cout << '\n' << std::setw(103) << "|Press '1' to register - student" << '\n' << std::setw(103) << "|Press '2' to register - teacher" << '\n';
	}

	// Drawing BOTTOM page design
	std::cout << std::setw(70) << "\\";
	for (int i = 0; i < 48; i++)
	{
		std::cout << '_';
	}
	std::cout << "/";
}

void displayStudentRegLog(std::ifstream& studentsDBREAD, std::string& username, std::string& password)
{
	system("cls");
	bool flag = false;

	// Drawing TOP page design
	std::cout << std::setw(70);
	for (int i = 0; i < 50; i++)
	{
		std::cout << '_';
	}
	std::cout << '\n' << std::setw(70) << "/" << std::setw(49) << "\\";

	// Drawing options
	std::cout << '\n' << std::setw(98) << "|Enter student name (WIP): ";
	std::cin >> username;
	std::cout << std::setw(102) << "|Enter student password (WIP): ";
	std::cin >> password;

	std::string root = "";
	while (studentsDBREAD)
	{
		getline(studentsDBREAD, root);
		if (root == (username + " " + password))
		{
			flag = true;
			break;
		}
	}

	// Drawing BOTTOM page design
	std::cout << std::setw(70) << "\\";
	for (int i = 0; i < 48; i++)
	{
		std::cout << '_';
	}
	std::cout << "/";

	system("cls");
	if (flag)
	{
		std::cout << "Bravo, you are in!";
	}
	else
	{
		std::cout << "Account not found...";
	}
}

void displayTeacherRegLog(std::ifstream& teachersDBREAD, std::string& username, std::string& password)
{
	system("cls");
	bool flag = false;

	// Drawing TOP page design
	std::cout << std::setw(70);
	for (int i = 0; i < 50; i++)
	{
		std::cout << '_';
	}
	std::cout << '\n' << std::setw(70) << "/" << std::setw(49) << "\\";

	// Drawing options
	std::cout << '\n' << std::setw(98) << "|Enter teacher name (WIP): ";
	std::cin >> username;
	std::cout << std::setw(102) << "|Enter teacher password (WIP): ";
	std::cin >> password;

	std::string root = "";
	while (teachersDBREAD)
	{
		getline(teachersDBREAD, root);
		if (root == (username + " " + password))
		{
			flag = true;
			break;
		}
	}

	// Drawing BOTTOM page design
	std::cout << std::setw(70) << "\\";
	for (int i = 0; i < 48; i++)
	{
		std::cout << '_';
	}
	std::cout << "/";

	system("cls");
	if (flag)
	{
		std::cout << "Bravo, you are in!";
	}
	else
	{
		std::cout << "Account not found...";
	}
}