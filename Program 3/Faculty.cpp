#include "Faculty.h"
#include"Members.h"
#include<iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;

Faculty::Faculty()
{
	//Default Constructor;
	//Postcondition: Initizalizes first_name, last_name, id_num, and salary;
	Members();
	salary = 0.0;
}

Faculty::Faculty(const string & first, const string & last, int id, double salaryx):Members(first, last, id)
{
	//Precondition: Argument Constructor;
	//Postcondition: Initizalizes first_name, last_name, id_num, and salary;
	salary = salaryx;
}

void Faculty::printMember() const
{
	//Precondition: Member variables first_name, last_name, id_num, and salary have been initialized;
	//Postcondition: Output member variables;
	cout << "Faculty name is: " << first_name << " " << last_name << ". The ID is: " << id_num << ". Salary is: " <<  salary << endl;
}

void Faculty::readWriteMembers(ifstream & fin, ofstream & fout)
{
	//Precondition: Valid, open input file stream and output file stream passed in; ifstream: first_name, last_name, id_num, and salary separated by spaces;
	//Postcondition: Output File Stream: first_name, last_name, id_num, and salary in readable format;
	fin >> first_name >> last_name >> id_num >> salary;
	fout << "Faculty name is: " << first_name << " " << last_name << ". The ID is: " << id_num << ". Salary is: " << salary << endl;
}

void Faculty::set_salary(double salaryx)
{
	salary = salaryx;
}

double Faculty::get_salary()
{
	return salary;
}
