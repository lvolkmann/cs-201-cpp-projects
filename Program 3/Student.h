#pragma once
#include"Members.h"
using namespace std;

class Student :public Members
{
public:
	Student();
	Student(const string& first, const string& last, int id, string& major);
	void printMember() const;
	void readWriteMembers(ifstream& fin, ofstream& fout);
	void set_major(string majorx);
	string get_major();
protected:
	string major;
};