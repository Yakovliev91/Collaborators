#include <iostream>
#include<string>
#include "Collaborator.h"

using namespace std;

int main()
{
	init();
	int action = 0;
	cout << "\tCOLLABORATORS\t\n" << endl;
	do
	{
		cout << "1. Data Entry" << endl;
		cout << "2. Show all collaborators" << endl;
		cout << "3. Search by age" << endl;
		cout << "4. Search by second name " << endl;
		cout << "5. Search by letter " << endl;
		cout << "6. Edit Info" << endl;
		cout << "7. Delete" << endl;
		cout << "8. Saving Data in file" << endl;
		cout << "9. Exit" << endl;
		cout << endl;
		cout << "Select action :";
		cin >> action;
		switch (action)
		{
		case 1:
			AddInfo();
			break;
		case 2:
			ShowAll();
			break;
		case 3:
			SearchAge();
			break;
		case 4:
			SearchSecondName();
			break;
		case 5:
			SearchLetter();
			break;
		case 6:
			Edit();
			break;
		case 7:
			Delete();
			break;
		case 8:
			Save();
			break;
		case 9:
			break;
		
		default:
			break;
		}


	} while (action!=8);









	system("pause");
	return 0;
}