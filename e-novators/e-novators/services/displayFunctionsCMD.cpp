#include "precompiler.h"

extern std::string studentStatsGLOBAL;

// Draw function for top design
void drawTopDesign()
{
	// Drawing TOP page design
	std::cout << std::setw(68);
	for (int i = 0; i < 50; i++)
	{
		std::cout << '_';
	}
	std::cout << '\n' << std::setw(68) << "/" << std::setw(49) << "\\" << '\n';
}

// Draw function for bottom design
void drawBottomDesign()
{
	// Drawing BOTTOM page design
	std::cout << std::setw(68) << "\\";
	for (int i = 0; i < 48; i++)
	{
		std::cout << '_';
	}
	std::cout << "/\n";
}

// Displaying entry page
void displayEntryPage()
{
	system("cls");

	// Drawing TOP page design
	drawTopDesign();

	// Drawing options
	std::cout << std::setw(87) << "|Press '1' Login" << '\n' << std::setw(98) << "|Press '2' for Registration" << '\n';
	
	// Drawing BOTTOM page design
	drawBottomDesign();
}

void userType(bool userType)
{
	system("cls");

	// Drawing TOP page design
	drawTopDesign();
	
	// Checking if the user wants to be logged in or be registered
	if (userType)
	{
		// Drawing options
		std::cout << std::setw(100) << "|Press '1' to login - student" << '\n' << std::setw(100) << "|Press '2' to login - teacher" << '\n';
	}
	else
	{
		// Drawing options
		std::cout << std::setw(103) << "|Press '1' to register - student" << '\n' << std::setw(103) << "|Press '2' to register - teacher" << '\n';
	}

	// Drawing BOTTOM page design
	drawBottomDesign();
}

void displayStudentRegLog(std::ifstream& studentsDBREAD, std::string& username, std::string& password, bool entryType)
{
	std::string keepStudentName = "", keepStudentClass = "";

	if (entryType)
	{
		// Login form - students

		std::ifstream studentsDBPFP("database/usersPFP-students.txt");

		char classLetter;
		bool accountFound = false, flag = false;
		int numberOfAttemps = 0, classNumber = 0;

		std::string rootStudentsDBPFP = "";

		while (!accountFound)
		{
			system("cls");

			// Drawing TOP page design
			drawTopDesign();

			// Drawing options
			std::cout << std::setw(92) << "|Enter student name: ";
			std::getline(std::cin, username);
			std::cout << std::setw(96) << "|Enter student password: ";
			std::getline(std::cin, password);
			std::cout << std::setw(100) << "|Enter student class number: ";
			std::cin >> classNumber;
			std::cin.clear();														// Clears std::cin buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Skip all characters in the stream's buffer until it reaches '\n'
			std::cout << std::setw(100) << "|Enter student class letter: ";
			std::cin >> classLetter;
			std::cin.ignore(2, '\n');												// Ignore 2 character and terminate when ‘\n’ is found

			// Clear the buffer and place the reading point at the beginning
			studentsDBREAD.clear();
			studentsDBREAD.seekg(0, std::ios::beg);
			studentsDBPFP.clear();
			studentsDBPFP.seekg(0, std::ios::beg);
			std::string rootStudentsDB = "";
			while (studentsDBREAD)
			{
				getline(studentsDBREAD, rootStudentsDB);
				getline(studentsDBPFP, rootStudentsDBPFP);
				if (rootStudentsDB == (username + " " + password + " " + std::to_string(classNumber) + " " + classLetter + " " + rootStudentsDBPFP))
				{
					keepStudentName = username;
					keepStudentClass = std::to_string(classNumber) + " " + classLetter;

					flag = true;
					break;
				}
			}

			// Drawing BOTTOM page design
			drawBottomDesign();

			if (flag)
			{
				system("cls");
				std::cout << "Successfully logged in! Press \"Enter\" to proceed to main program... - <clear screen (cls), change colours of cmd and start raylib window>";
				waitForKey();

				break;
			}
			else
			{
				numberOfAttemps++;
				std::cout << '\n' << std::setw(111) << "Account not found. Please try again.\n" << std::setw(101) << "Retries remaining: " << 5 - numberOfAttemps << '\n' << std::setw(106) << "Press \"Enter\" to continue...";
				waitForKey();

				if (!(5 - numberOfAttemps))
				{
					entryViolation();
					break;
				}
			}
		}

		studentsDBPFP.close();
		if (flag)
		{
			// Enter school
			sceneMagager(keepStudentName, keepStudentClass, stoi(rootStudentsDBPFP), true);
		}
	}
	else
	{
		// Registration form - students

		// Loading database
		std::ofstream studentsDBWRITE("./database/users-students.txt", std::ios::app);		// Open database in append mode
		std::ofstream studentsDBPFP("database/usersPFP-students.txt", std::ios::app);		// Open database in append mode
		std::ofstream studentsDBSTATS("database/users-statistics.txt", std::ios::app);		// Open database in append mode

		int keepUserPFP = 0;
		bool flag = true;
		if (!studentsDBWRITE.is_open())
		{
			system("cls");
			std::cout << "\nError opening database\nClosing application...";
		}
		else
		{
			std::string* checkForAccountDuplicate = new std::string();
			char studentClassLetter;
			int checkForSpace = 0, * studentClassNumber = new int();
			bool checkBufferMemory = false;

			while (flag)
			{
				system("cls");

				// Drawing TOP page design
				drawTopDesign();

				// Drawing options
				std::cout << std::setw(92) << "|Enter student name: ";
				std::getline(std::cin, username);
				
				if (checkBufferMemory)
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Skip all characters in the stream's buffer until it reaches '\n'
				}
				
				std::cout << std::setw(96) << "|Enter student password: ";
				std::getline(std::cin, password);
				std::cout << std::setw(93) << "|Enter student class: ";						// Number and Letter
				std::cin >> *studentClassNumber;
				std::cin >> studentClassLetter;
				std::cin.clear();															// Clears std::cin buffer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// Skip all characters in the stream's buffer until it reaches '\n'
				checkBufferMemory = true;

				// Drawing BOTTOM page design
				drawBottomDesign();

				// Check for empty username holder
				if ((username)[0] == 0 || (username)[0] == 32)
				{
					std::cout << '\n' << std::setw(101) << "Invalid username...";

					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}

				// Check if username already exists
				std::string surname = "";
				while (studentsDBREAD >> *checkForAccountDuplicate)
				{
					studentsDBREAD >> surname;
					*checkForAccountDuplicate += " " + surname;
					if (*checkForAccountDuplicate == username)
					{
						std::cout << '\n' << std::setw(105) << "Username already exists...";

						waitForKey();
						displayStudentRegLog(studentsDBREAD, username, password, entryType);
					}
				}

				// Check if symbols are from the alphabet
				for (size_t i = 0; i < username.length(); i++)
				{
					if (!(((username)[i] >= 65 && (username)[i] <= 90) || ((username)[i] >= 97 && (username)[i] <= 122) || (username)[i] == 32))
					{
						std::cout << '\n' << std::setw(110) << "Use symbols only from the alphabet...";

						waitForKey();
						displayStudentRegLog(studentsDBREAD, username, password, entryType);
					}
				}

				// Check if the first symbol is in uppercase
				if (!((username)[0] >= 65 && (username)[0] <= 90))
				{
					std::cout << '\n' << std::setw(111) << "First letter should be in uppercase...";

					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}

				for (size_t i = 0; i < username.length(); i++)
				{
					if ((username)[i - checkForSpace] == 32)
					{
						if (checkForSpace <= 2)
						{
							checkForSpace++;
							if (checkForSpace == 2)
							{
								// Check if the symbol is in uppercase
								if (!((username)[i] >= 65 && (username)[i] <= 90))
								{
									std::cout << '\n' << std::setw(112) << "Surname letter should be in uppercase...";

									waitForKey();
									displayStudentRegLog(studentsDBREAD, username, password, entryType);
								}
							}
						}
					}

					if (checkForSpace == 0 || checkForSpace == 3)
					{
						// Check if other symbols are in lowercase
						if (i != 0)
						{
							if (!((username)[i] >= 97 && (username)[i] <= 122))
							{
								std::cout << '\n' << std::setw(101) << "Invalid username...";

								waitForKey();
								displayStudentRegLog(studentsDBREAD, username, password, entryType);
							}
						}
					}
				}

				// Check for empty password holder
				if ((password)[0] == 0 || (password)[0] == 32)
				{
					std::cout << '\n' << std::setw(101) << "Invalid password...";

					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}

				// Check if surname is present
				if (checkForSpace == 0)
				{
					std::cout << '\n' << std::setw(101) << "Surname missing...";

					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}

				// Check class number
				if (*studentClassNumber <= 7 || *studentClassNumber >= 13)
				{
					std::cout << '\n' << std::setw(103) << "Invalid class number...";
					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}
				
				// Check class letter
				if (!(studentClassLetter == 'A' || studentClassLetter == 'B' || studentClassLetter == 'V' || studentClassLetter == 'G'))
				{
					std::cout << '\n' << std::setw(103) << "Invalid class letter...";
					waitForKey();
					displayStudentRegLog(studentsDBREAD, username, password, entryType);
				}

				keepUserPFP = generateUserPFP(true);

				// Write new data in database
				studentsDBWRITE << username << " " << password << " " << *studentClassNumber << " " << studentClassLetter << " " << keepUserPFP << '\n';
				studentsDBPFP << keepUserPFP << '\n';

				studentStatsGLOBAL = generateUserStatistics();
				studentsDBSTATS << studentStatsGLOBAL << '\n';

				keepStudentName = username;
				keepStudentClass = *studentClassNumber + " " + studentClassLetter;

				if (flag)
				{
					system("cls");
					std::cout << "Account created. Press \"Enter\" to proceed to main program... - <clear screen (cls), change colours of cmd and start raylib window>";
					waitForKey();

					break;
				}
			}

			studentsDBWRITE.close();
			studentsDBPFP.close();
			studentsDBSTATS.close();
			if (flag)
			{
				// Enter school after completing registration
				sceneMagager(keepStudentName, keepStudentClass, keepUserPFP, true);
			}
		}
	}
}

void displayTeacherRegLog(std::ifstream& teachersDBREAD, std::string& username, std::string& password, bool entryType)
{
	std::string keepTeacherName = "";

	if (entryType)
	{
		// Login form - teachers

		std::ifstream teachersDBPFP("database/usersPFP-teachers.txt");

		char classLetter;
		bool accountFound = false, flag = false;
		int numberOfAttemps = 0, classNumber = 0;

		std::string rootTeachersDBPFP = "";

		while (!accountFound)
		{
			system("cls");

			// Drawing TOP page design
			drawTopDesign();

			// Drawing options
			std::cout << std::setw(92) << "|Enter teacher name: ";
			std::getline(std::cin, username);
			std::cout << std::setw(96) << "|Enter teacher password: ";
			std::getline(std::cin, password);
			std::cin.clear();													// Clears std::cin buffer

			// Clear the buffer and place the reading point at the beginning
			teachersDBREAD.clear();
			teachersDBREAD.seekg(0, std::ios::beg);
			std::string rootTeachersDB = "";
			while (teachersDBREAD)
			{
				getline(teachersDBREAD, rootTeachersDB);
				getline(teachersDBREAD, rootTeachersDBPFP);
				if (rootTeachersDB == (username + " " + password + " " + rootTeachersDBPFP))
				{
					keepTeacherName = username;

					flag = true;
					break;
				}
			}

			// Drawing BOTTOM page design
			drawBottomDesign();

			if (flag)
			{
				system("cls");
				std::cout << "Successfully logged in! Press \"Enter\" to proceed to main program... - <clear screen (cls), change colours of cmd and start raylib window>";
				waitForKey();

				break;
			}
			else
			{
				numberOfAttemps++;
				std::cout << '\n' << std::setw(111) << "Account not found. Please try again.\n" << std::setw(101) << "Retries remaining: " << 5 - numberOfAttemps << '\n' << std::setw(106) << "Press \"Enter\" to continue...";
				waitForKey();

				if (!(5 - numberOfAttemps))
				{
					entryViolation();
					break;
				}
			}
		}

		teachersDBPFP.close();
		if (flag)
		{
			// Enter school after successful login
			sceneMagager(keepTeacherName, "<empty>", stoi(rootTeachersDBPFP), false);
		}
	}
	else
	{
		// Registration form - teachers

		// Loading database
		std::ofstream teachersDBWRITE("./database/users-teachers.txt", std::ios::app);		// Open database in append mode
		std::ofstream teachersDBPFP("./database/usersPFP-teachers.txt", std::ios::app);		// Open database in append mode

		if (!teachersDBWRITE.is_open())
		{
			system("cls");
			std::cout << "\nError opening database\nClosing application...";
		}
		else
		{
			std::string* checkForAccountDuplicate = new std::string();
			int checkForSpace = 0, keepUserPFP = 0;
			bool flag = true;

			while (flag)
			{
				system("cls");

				// Drawing TOP page design
				drawTopDesign();

				// Drawing options
				std::cout << std::setw(92) << "|Enter teacher name: ";
				std::getline(std::cin, username);
				std::cin.clear();													// Clears std::cin buffer
				std::cout << std::setw(96) << "|Enter teacher password: ";
				std::getline(std::cin, password);
				std::cin.clear();													// Clears std::cin buffer

				// Drawing BOTTOM page design
				drawBottomDesign();

				// Check for empty username holder
				if ((username)[0] == 0 || (username)[0] == 32)
				{
					std::cout << '\n' << std::setw(101) << "Invalid username...";

					waitForKey();
					displayTeacherRegLog(teachersDBREAD, username, password, entryType);
				}

				// Check if username already exists
				std::string surname = "";
				while (teachersDBREAD >> *checkForAccountDuplicate)
				{
					teachersDBREAD >> surname;
					*checkForAccountDuplicate += " " + surname;
					if (*checkForAccountDuplicate == username)
					{
						std::cout << '\n' << std::setw(105) << "Username already exists...";

						waitForKey();
						displayTeacherRegLog(teachersDBREAD, username, password, entryType);
					}
				}

				// Check if symbols are from the alphabet
				for (size_t i = 0; i < username.length(); i++)
				{
					if (!(((username)[i] >= 65 && (username)[i] <= 90) || ((username)[i] >= 97 && (username)[i] <= 122) || (username)[i] == 32))
					{
						std::cout << '\n' << std::setw(110) << "Use symbols only from the alphabet...";

						waitForKey();
						displayTeacherRegLog(teachersDBREAD, username, password, entryType);
					}
				}

				// Check if the first symbol is in uppercase
				if (!((username)[0] >= 65 && (username)[0] <= 90))
				{
					std::cout << '\n' << std::setw(111) << "First letter should be in uppercase...";

					waitForKey();
					displayTeacherRegLog(teachersDBREAD, username, password, entryType);
				}

				for (size_t i = 0; i < username.length(); i++)
				{
					if ((username)[i - checkForSpace] == 32)
					{
						if (checkForSpace <= 2)
						{
							checkForSpace++;
							if (checkForSpace == 2)
							{
								// Check if the symbol is in uppercase
								if (!((username)[i] >= 65 && (username)[i] <= 90))
								{
									std::cout << '\n' << std::setw(112) << "Surname letter should be in uppercase...";

									waitForKey();
									displayTeacherRegLog(teachersDBREAD, username, password, entryType);
								}
							}
						}
					}

					if (checkForSpace == 0 || checkForSpace == 3)
					{
						// Check if other symbols are in lowercase
						if (i != 0)
						{
							if (!((username)[i] >= 97 && (username)[i] <= 122))
							{
								std::cout << '\n' << std::setw(101) << "Invalid username...";

								waitForKey();
								displayTeacherRegLog(teachersDBREAD, username, password, entryType);
							}
						}
					}
				}

				// Check for empty password holder
				if ((password)[0] == 0 || (password)[0] == 32)
				{
					std::cout << '\n' << std::setw(101) << "Invalid password...";

					waitForKey();
					displayTeacherRegLog(teachersDBREAD, username, password, entryType);
				}

				// Check if surname is present
				if (checkForSpace == 0)
				{
					std::cout << '\n' << std::setw(101) << "Surname missing...";

					waitForKey();
					displayTeacherRegLog(teachersDBREAD, username, password, entryType);
				}

				keepUserPFP = generateUserPFP(false);

				// Write new data in database
				teachersDBWRITE << username << " " << password << " " << keepUserPFP << '\n';
				teachersDBPFP << keepUserPFP << '\n';

				keepTeacherName = username;

				if (flag)
				{
					system("cls");
					std::cout << "Account created. Press \"Enter\" to proceed to main program... - <clear screen (cls), change colours of cmd and start raylib window>";
					waitForKey();

					break;
				}
			}

			delete(checkForAccountDuplicate);
			teachersDBPFP.close();
			teachersDBWRITE.close();

			if (flag)
			{
				// Enter school after completing registration
				sceneMagager(keepTeacherName, "<empty>", keepUserPFP, false);
			}
		}
	}
}