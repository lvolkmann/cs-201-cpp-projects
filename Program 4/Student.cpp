#include "Student.h"

Student::Student()
{
	//Precondition: N/A;
	//Postcondition: Initialized object of class student with ID = 0, first = "", last = "", items_out = 0, and p = NULL;
	ID = 0;
	first = "";
	last = "";
	items_out = 0;
	p = NULL;
}

Student::Student(string xfirst, string xlast, int xID)
{
	//Precondition: Pass first and last of type string and ID of type int;
	//Postcondition: Initialized object of class student with ID = xID, first = xfirst, last = xlast, items_out = 0, and p = NULL;
	ID = xID;
	first = xfirst;
	last = xlast;
	items_out = 0;
	p = NULL;
}

Student::~Student()
{
	//Precondition: Initialized dynamic array p;
	//Postcondition: Deletion of the contents of p and p set to NULL;
	delete[] p;
	p = NULL;
}

Student::Student(const Student & stud)
{
	//Precondition: Pass object of type student;
	//Postcondition: Return copy of object passed of type student;
	first = stud.first;
	last = stud.last;
	ID = stud.ID;
	max = stud.max;
	items_out = stud.items_out;
	p = new string[max];
	for (int i = 0; i < items_out; i++)
		p[i] = stud.p[i];
}

void Student::set_first(string xfirst)
{
	//Precondition: Pass desired first name of type string;
	//Postcondition: Object updated with first = xfirst;
	first = xfirst;
}

void Student::set_last(string xlast)
{
	//Precondition: Pass desired last name of type string;
	//Postcondition: Object updated with last = xlast;
	last = xlast;
}

void Student::set_ID(int xID)
{
	//Precondition: Pass desired ID of type int; Int must be between 1000 and 10000;
	//Postcondition: Object updated with ID = xID;
	if (xID >= 1000 && xID <= 10000)
		ID = xID;
	else
		cout << "Invalid ID. Must be between 1,000 and 10,000." << endl;
}

string Student::get_first() const
{
	//Precondition: Initialized Student Object;
	//Postcondition: Return value of first of type string;
	return first;
}

string Student::get_last() const
{
	//Precondition: Initialized Student Object;
	//Postcondition: Return value of last of type string;
	return last;
}

int Student::get_ID() const
{
	//Precondition: Initialized Student Object;
	//Postcondition: Return value of ID of type unsigned int;
	return ID;
}

void Student::Clear()
{
	//Precondition: Initialized Student Object;
	//Postcondition: Object of class student updated to ID = 0, first = "", last = "", items_out = 0, deleted dynamic array of p, and p = NULL;
	first = "";
	last = "";
	ID = 0;
	items_out = 0;
	delete[] p;
	p = NULL;
}

int Student::CheckoutCount() const
{
	//Precondition: Initialized Student Object;
	//Postcondition: Return value of items_out of type unsigned int;
	return items_out;
}

bool Student::CheckOut(const string & item)
{
	//Precondition: Initialized Student Object; Pass item to checkout of type string;
	//Postcondition: If no items out: allocate dynamic array of size 5, set max, checkout item, increment items_out, return true;
	//				 Else if item already checked out: return false;
	//				 Else If dynamic array full: increase size, checkout item, increment items_out, return true;
	//				 Else: Checkout item, increment items_out, return true;
	if (items_out == 0)
	{
		p = new string[5];
		max = 5;
		p[0] = item;
		items_out++;
		return true;
	}
	else if (HasCheckedOut(item))
		return false;
	else if (items_out == max)
	{
		increase_size();
		p[items_out] = item;
		items_out++;
		return true;
	}
	else
	{
		p[items_out] = item;
		items_out++;
		return true;
	}

}

bool Student::CheckIn(const string & item)
{
	//Precondition: Initialized Student Object; Pass item to check in of type string;
	//Postcondition: If student array contains item and items_out > 1: remove first occurence, decrement index of all items to the right of item, decrement items_out, and return true;
	//				 Else if student array contains item and items_out == 1: remove first occurrence, decrement items_out, delete p, p = null, and return true;
	//				 Else: Return false;
	for (int i = 0; i < items_out; i++)
	{
		if (p[i] == item)
		{
			for (int j = i; j < (items_out-1); j++)
			{
				p[j] = p[j + 1];
			}
			items_out--;
			if (items_out == 0)
			{
				delete[] p;
				p = NULL;
			}
			return true;
		}
	}
	return false;
}

bool Student::HasCheckedOut(const string & item)
{
	//Precondition: Initialized object of type student; Pass item of type string to see if already checked out;
	//Postcondition: If item in objects array: return true; Else: return false;
	for (int i = 0; i < items_out; i++)
	{
		if (p[i] == item)
			return true;
	}
	return false;
}

void Student::print_info()
{
	//Precondition: Initialized object of type student;
	//Postcondition: Output values of member variables in object separated by spaces with each item checked out on its own line;
	cout << first << " " << last << " " << ID << " " << items_out << endl;
	for (int i = 0; i < items_out; i++)
		cout << p[i] << endl;
}

void Student::increase_size()
{
	//Precondition: Initialized object of type student;
	//Postcondition: Size of dynamic array p doubled; max doubled;
	string *new_p = new string[items_out * 2];

	for (int i = 0; i < items_out; i++)
	{
		new_p[i] = p[i];
	}
	delete[] p;
	p = new_p;
	max *= 2;
}


Student Student::operator+(string& item)
{
	//Precondition: LHS: initialized object of type student; RHS: item to check out of type string;
	//Postcondition: Return copy of object updated to have item passed checked out;
	Student stu_updated(*this);
	stu_updated.CheckOut(item);
	return stu_updated;
}

void Student::operator+=(string & item)
{
	//Precondition: Assigned to: initialized object of type student; RHS: item to check out of type string;
	//Postcondition: Object updated with checked out item;
	CheckOut(item);
}

bool Student::operator==(const Student rhs) const
{
	//Precondition: Two objects of type student on either side;
	//Postcondition: If LHS ID == RHS ID: return true; Else: return false;
	if (ID != rhs.ID)
		return false;
	return true;
}

bool Student::operator!=(const Student rhs)
{
	//Precondition: Two objects of type student on either side;
	//Postcondition: If LHS ID != RHS ID: return true; Else: return false;
	if (ID == rhs.ID)
		return false;
	return true;
}

const Student& Student::operator=(const Student& rhs)
{
	//Precondition: Assigned to: Initialized object of type student; RHS: Initialized object of type student;
	//Postcondition: Copies member variables of LHS to object assigned to;
	if (*this == rhs)
		return *this;
	else
	{
		Clear();
		first = rhs.first;
		last = rhs.last;
		ID = rhs.ID;
		max = rhs.max;
		items_out = rhs.items_out;
		p = new string[max];
		for (int i = 0; i < items_out; i++)
			p[i] = rhs.p[i];
		return *this;
	}
	
}

istream & operator>>(istream & in, Student & item)
{
	//Precondition: LHS: Open input stream with desired member variables separated by whitespace in the following order: ID, first, last, # items_to_checkout, item 1, item 2...; RHS: Initialized object of type student;
	//Postcondition: Object updated with values read in; retun input file stream;
	string check;
	bool success;
	int items_to_checkout;

	item.Clear();
	in >> item.ID >> item.first >> item.last >> items_to_checkout;

	for (int i = 0; i < items_to_checkout; i++)
	{
		in >> check;
		success = item.CheckOut(check);
		if (!success)
			cout << "Error checking out " << check << " for " << item.first << endl;
	}
	return in;
}

ostream & operator<<(ostream & out, const Student & item)
{
	//Precondition: LHS: Open output stream; RHS: initialized object of type student;
	//Postcondition: Output values of member variables in object separated by spaces with items checked out on its own line; return output stream;
	out << item.ID << " " << item.first << " " << item.last  << " "  << endl;
	out << item.items_out << endl;
	for (int i = 0; i < item.items_out; i++)
		out << item.p[i] << " ";
	return out;
}
