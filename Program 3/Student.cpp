#include "Student.h"
#include<iostream>
#include <string>
#include<fstream>
using namespace std;

Student::Student()
{
	//Precondition: Default Constructor;
	//Postcondition: Initizalizes first_name, last_name, id_num, and major;
	Members();
	major = "";
}

Student::Student(const string & first, const string & last, int id, string & majorx):Members(first, last, id)
{
	//Precondition: Argument Constructor;
	//Postcondition: Initizalizes first_name, last_name, id_num, and major;
	major = majorx;
}

void Student::printMember() const
{
	//Precondition: Member variables first_name, last_name, id_num, and major have been initialized;
	//Postcondition: Output member variables;
	cout << "Student name is: " << first_name << " " << last_name << ". The ID is: " << id_num << ". Major is: " << major << endl;
}

void Student::readWriteMembers(ifstream & fin, ofstream & fout)
{
	//Precondition: Valid, open input file stream and output file stream passed in; ifstream: first_name, last_name, id_num, and major separated by spaces;
	//Postcondition: Output File Stream: first_name, last_name, id_num, and major in readable format;
	fin >> first_name >> last_name >> id_num >> major;
	fout << "Student name is: " << first_name << " " << last_name << ". The ID is: " << id_num << ". Major is: " << major << endl;
}

void Student::set_major(string majorx)
{
	major = majorx;
}

string Student::get_major()
{
	return major;
}
