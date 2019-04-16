#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Members
{
public:
	Members();
	Members(const string& first, const string& last, int id);
	void printMember() const;
	void readWriteMembers(ifstream& fin, ofstream& fout);
	void set_first(string first);
	string get_first();
	void set_last(string last);
	string get_last();
	void set_id(int id);
	int get_id();

protected:
	string first_name;
	string last_name;
	int id_num;
};