/*
Author:		Misbahud Din
Language:	C++
Project:	Coloured Console
Description:	Everyone Likes colors :) . This program shows some of the colors c++ can display in console
*/


#include <Windows.h>		// Header file for colors
#include <iostream>

using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	string name;
	cout << "Enter your name: ";
	cin >> name;

	for (int i = 0; i <+ 255; i++)
	{
		SetConsoleTextAttribute(h, i);
		cout << "Your name is " << name << endl;
	}
	cout<<"Hello World";
	return 0;
}
