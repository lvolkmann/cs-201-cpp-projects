#pragma once
#include"Members.h"
using namespace std;

class Faculty:public Members
{
public:
	Faculty();
	Faculty(const string& first, const string& last, int id, double salary);
	void printMember() const;
	void readWriteMembers(ifstream& fin, ofstream& fout);
	void set_salary(double salaryx);
	double get_salary();
protected:
	double salary;
};