//Landon Volkmann
//Student Num: 16221373
//CS 201
//Program 2
//02/16/18

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Main
int main()
{
	//Set Precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Function Declarations
	void printCustomersData(const int id[], const string first[], const string last[], const double savings[], const double checking[], const int max);
	//Precondition: Pass in constant arrays of ID, First, Last, Savings, Checking, and Max array size;
	//Postcondition: Data output to console; No return;
	void printNames(const int id[], const string first[], const string last[], const int max);
	//Precondition: Pass in constant arrays of ID, First, Last, and Max array size;
	//Postcondition: Data output to console; No return;
	void printTotal(const int id[], const double savings[], const double checking[], const int max);
	//Precondition:Pass in constant arrays of ID, Savings, Checking, and Max array size;
	//Postcondition: Data output to console; No return;
	char menu_func(const string options);
	//Precondition: Pass in constant string menu;
	//Postcondition: Return Valid Choice character of 1, 2, 3, q, or Q; 

	//Max Elements in Array
	const int max = 10;

	//Elements Declaration
	int id[max];
	string first[max];
	string last[max];
	double savings[max];
	double checking[max];

	//Main Declarations
	char choice;
	bool running = true;

	//Menu
	string options = "1. Print all customers data \n\
2. Print names and IDs\n\
3. Print acounts total \n\
4. Enter q/Q to quit \n \n\
Enter your choice, or 'q' to quit: ";

	//File Read-in
	ifstream fin;
	fin.open("input.txt");

	//Read File
	for (int i = 0; i < max; i++)
	{
		fin >> id[i];
		fin >> first[i];
		fin >> last[i];
		fin >> savings[i];
		fin >> checking[i];
	}

	//Check Read-in Success & Close
	if (fin.fail())
	{
		cout << "Something went terribly wrong." << endl;
		running = false;
	}
	else
		fin.close();

	//Get Choice and Excute Desired Function
	while (running)
	{
		choice = menu_func(options);

		switch (choice)
		{
		case '1':
			printCustomersData(id, first, last, savings, checking, max);
			break;
		case '2':
			printNames(id, first, last, max);
			break;
		case '3':
			printTotal(id, savings, checking, max);
			break;
		case 'q':
			running = false;
			break;
		case 'Q':
			running = false;
			break;
		default:
			break;
		}

	}
	
	cout << "Thank you for banking with Volkman and Volkmann. Come again!" << endl;
	system("Pause");
	return 0;
}

//Function Definitions
void printCustomersData(const int id[], const string first[], const string last[], const double savings[], const double checking[], const int max)
{
	//Precondition: Pass in constant arrays of ID, First, Last, Savings, Checking, and Max array size;
	//Postcondition: Data output to console; No return;
	cout << setw(20) << left << "ID" << setw(20) << "First" << setw(20) << "Last" << setw(20) << "Savings Account" << setw(20) << "Checking Account" << endl;
	for(int i = 0; i < max; i++)
	{
		cout << setw(20) << left << id[i] << setw(20) << first[i] << setw(20) << last[i] << setw(20) << savings[i] << setw(20) << checking[i] << endl;
	}
	cout << endl;
}

void printNames(const int id[], const string first[], const string last[], const int max)
{
	//Precondition: Pass in constant arrays of ID, First, Last, and Max array size;
	//Postcondition: Data output to console; No return;
	cout << setw(20) << left << "ID" << setw(20) << "First" << setw(20) << "Last" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << setw(20) << left << id[i] << setw(20) << first[i] << setw(20) << last[i] << endl;
	}
	cout << endl;
}

void printTotal(const int id[], const double savings[], const double checking[], const int max)
{
	//Precondition:Pass in constant arrays of ID, Savings, Checking, and Max array size;
	//Postcondition: Data output to console; No return;
	cout << setw(20) << left << "ID" << setw(20) << "Savings Account" << setw(20) << "Checking Account" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << setw(20) << left << id[i] << setw(20) <<  savings[i] << setw(20) << checking[i] << endl;
	}
	cout << endl;
}

char menu_func(string const options)
{
	//Precondition: Pass in constant string menu;
	//Postcondition: Return Valid Choice character of 1, 2, 3, q, or Q; 
	char choice;
	bool valid = false;

	do
	{
		cin.clear();
		cout << options;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case '1':
			valid = true;
			break;
		case '2':
			valid = true;
			break;
		case '3':
			valid = true;
			break;
		case 'q':
			valid = true;
			break;
		case 'Q':
			valid = true;
			break;
		default:
			cout << "Invalid input! Try again. \n" << endl;
			break;
		}
	} while (!valid);
	
	return choice;
}