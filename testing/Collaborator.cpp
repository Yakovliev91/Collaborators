#include "Collaborator.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


Collaborator* collaborators;
int countCollab = 0;

void init()
{
	ifstream fin;
	fin.open("Collaborators.txt");
	bool isOpen = fin.is_open();

	if (isOpen==false)
	{
		cout << "Error" << endl;
	}
	else
	{
		int currentString = 0;
		string data;
		int data_2;
		Collaborator oldInfo;
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
			if (currentString==1)
			{
				oldInfo.name = data;
			}
			else if (currentString==2)
			{
				oldInfo.secondName = data;
			}
			else
			{
				data_2 = stoi(data);
				oldInfo.age = data_2;
				currentString = 0;
				Collaborator*temp = new Collaborator[countCollab + 1];
				for (int i = 0; i < countCollab; i++)
				{
					temp[i] = collaborators[i];

				}
				temp[countCollab] = oldInfo;
				countCollab++;

				collaborators = new Collaborator[countCollab];
				for (int i = 0; i < countCollab; i++)
				{
					collaborators[i] = temp[i];
				}
				delete[]temp;
			}
		}
	}
}

void AddInfo()
{
	Collaborator*temp = new Collaborator[countCollab + 1];
	for (int i = 0; i < countCollab; i++)
	{
		temp[i] = collaborators[i];
	}
	cout << "Enter name of collaborator :" << endl;
	cin >> temp[countCollab].name;
	cout << "Enter second name : " << endl;
	cin >> temp[countCollab].secondName;
	cout << "Enter age :" << endl;
	cin >> temp[countCollab].age;
	countCollab++;

	collaborators = new Collaborator[countCollab];
	for (int i = 0; i < countCollab; i++)
	{
		collaborators[i] = temp[i];
	}
	delete[]temp;
}

void ShowAll()
{
	for (int i = 0; i < countCollab; i++)
	{
		cout << "Name :" << collaborators[i].name<<endl;
		cout << "Second name :" << collaborators[i].secondName << endl;
		cout << "Age :" << collaborators[i].age << endl;
	}

}

void SearchAge()
{
	int count = 1;
	int age = 0;
	cout << "Enter age :";
	cin >> age;
	for (int i = 0; i < countCollab; i++)
	{
		if (age==collaborators[i].age)
		{
			cout << " Name of collaborator :"<<collaborators[i].name << endl;
			cout << " Second name : "<<collaborators[i].secondName << endl;
			cout << " Age :"<<collaborators[i].age << endl;
			count++;
		}
	}


}



void SearchSecondName()
{
	cout << "Search by second name " << endl;
	
	int count = 1;
	string second_Name;
		
	cout << "Enter second name you looking :";
	cin >> second_Name;
	for (int i = 0; i < countCollab; i++)
	{
		if (second_Name==collaborators[i].secondName)
		{
			cout << " Name of collaborator :" << collaborators[i].name << endl;
			cout << " Second name : " << collaborators[i].secondName << endl;
			cout << " Age :" << collaborators[i].age << endl;
			count++;
		}
		else {
			cout << "Second name not found" << endl;
		}
				
	}
}

void SearchLetter()
{
	int count = 1;
	char letter;
	cout << "Enter letter of second name collaborator you looking :";
	cin >> letter;
	for (int i = 0; i < countCollab; i++)
	{
		if (letter == collaborators[i].secondName[0])
		{
			cout << " Name of collaborator :" << collaborators[i].name << endl;
			cout << " Second name : " << collaborators[i].secondName << endl;
			cout << " Age :" << collaborators[i].age << endl;
			count++;

		}
		else
		{
			cout << "Second name not found" << endl;
		}

	}
}

void Edit()
{
	int number = 0;
	cout << "Enter number of collaborator for edit :";
	cin >> number;
	for (int i = 0; i < countCollab; i++)
	{
		if ((number-1)==i)
		{
			cout << "Collaborator" << collaborators[i].name << "will be editing for :";
			cin >> collaborators[i].name;
			cout << "Collaborator" << collaborators[i].secondName << "will be editing for :";
			cin >> collaborators[i].secondName;
			cout << "Collaborator" << collaborators[i].age << "will be editing on :";
			cin >> collaborators[i].age;


		}

	}
}

void Delete() 
{
	int number = 0;
	int count = 0;
	cout << "Enter number of collaborator for delete :";
	cin >> number;
	Collaborator*temp = new Collaborator[countCollab - 1];
	for (int i = 0; i < countCollab; i++)
	{
		if ((number-1)==i)
		{

		}
		else
		{
			temp[count] = collaborators[i];
			count++;
		}
	}
	countCollab--;
	collaborators = new Collaborator[countCollab];
	for (int i = 0; i < countCollab; i++)
	{
		collaborators[i] = temp[i];
	}
	delete[]temp;
}

void Save()
{
	ofstream fout;
	fout.open("Collaborators.txt");
	bool isOpen = fout.is_open();
	if (isOpen==false)
	{
		cout << "Error opening file !" << endl;
	}
	else
	{
		for (int i = 0; i < countCollab; i++)
		{
			fout << collaborators[i].name << endl;
			fout << collaborators[i].secondName << endl;
			fout << collaborators[i].age << endl;

				
		}
	}
	fout.close();
	cout << "Successfull" << endl;
}

