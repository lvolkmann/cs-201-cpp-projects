#include "Members.h"
#include<iostream>
#include <string>
#include<fstream>
using namespace std;

Members::Members()
{
	//Precondition: Default Constructor; 
	//Postcondition: Initializes first_name, last_name, and id_num;
	first_name = "";
	last_name = "";
	id_num = 0;
}

Members::Members(const string & first, const string & last, int id)
{
	//Precondition: Argument Constructor;
	//Postcondition: Initizalizes first_name, last_name, and id_num;
	first_name = first;
	last_name = last;
	id_num = id;
}

void Members::printMember() const
{
	//Precondition: Member variables first_name, last_name, and id_num have been initialized;
	//Postcondition: Output member variables;
	cout << "Member name is: " << first_name << " " << last_name << ". The ID is: " << id_num << "." << endl;
}

void Members::readWriteMembers(ifstream & fin, ofstream & fout)
{
	//Will not use this function at class Members level;
}

void Members::set_first(string first)
{
	first_name = first;
}

string Members::get_first()
{
	return first_name;
}

void Members::set_last(string last)
{
	last_name = last;
}

string Members::get_last()
{
	return last_name;
}

void Members::set_id(int id)
{
	id_num = id;
}

int Members::get_id()
{
	return id_num;
}
