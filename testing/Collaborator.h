#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Collaborator {
	string name;
	string secondName;
	int age;
};

void init();
void AddInfo();
void ShowAll();
void SearchAge();
void SearchSecondName();
void SearchLetter();
void Edit();
void Delete();
void Save();