#pragma once
#include<iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	Student(string xfirst, string xlast, int xID);
	~Student();
	Student(const Student& stud);

	void set_first(string xfirst);
	void set_last(string xlast);
	void set_ID(int xID);
	string get_first() const;
	string get_last() const;
	int get_ID() const;
	void Clear();

	int CheckoutCount() const;
	bool CheckOut(const string& item);
	bool CheckIn(const string& item);
	bool HasCheckedOut(const string& item);
	void print_info();
	void increase_size();

	friend istream& operator >>(istream& in, Student& item);
	friend ostream& operator <<(ostream& out, const Student& item);
	Student operator +(string& item);
	void operator +=(string& item);
	bool operator ==(const Student rhs) const;
	bool operator !=(const Student rhs);
	const Student & operator = (const Student & rhs);


private:
	string first;
	string last;
	unsigned int ID;
	unsigned int items_out;
	string *p;
	int max;
};