//Landon Volkmann
//Student Num: 16221373
//CS 201
//Program 4
//03/18/2018

#include<iostream>
#include<fstream>
#include<string>
#include"Student.h"
using namespace std;

int main()
{
	//Initialize Streams
	ifstream stud("Students.txt");
	ifstream checkin("checkins.txt");
	ifstream checkout("checkouts.txt");
	ofstream fout("Updated_Students.txt");

	//Initialize Student Array
	Student a[50];
	int stud_count = 0;

	//Initialize Variables for Temporary Storage
	int ID_in;
	string item_out;
	string item_in;
	bool checked_in;
	int pos;

	if (stud.fail() || checkin.fail() || checkout.fail())
	{
		cout << "Failed to open file.";
		system("Pause");
		return 0;
	}

	//Read in Student File
	while (!stud.eof())
	{
		Student new_stud;
		stud >> new_stud;
		a[stud_count] = new_stud;
		stud_count++;
	}
	
	//Read in Checkout File
	while (!checkout.eof())
	{
		checkout >> ID_in >> item_out;
		for (int i = 0; i < stud_count; i++)
		{
			if (ID_in == a[i].get_ID())
				a[i] += item_out;
		}
	}

	//Read in Checkin File
	while (!checkin.eof())
	{
		checkin >> item_in;

		pos = 0;
		checked_in = false;

		while (!checked_in)
		{
			checked_in = a[pos].CheckIn(item_in);
			pos++;
		}
	}

	//Output Results
	for (int i = 0; i < stud_count; i++)
	{
		fout << a[i];
		fout << endl;
	}

	//Close Open Files
	fout.close();
	checkin.close();
	checkout.close();
	stud.close();

	return 0;
}