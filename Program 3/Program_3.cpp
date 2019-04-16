//Landon Volkmann
//Student Num: 16221373
//CS 201
//Program 3
//03/04/2018

#include<iostream>
#include <string>
#include<fstream>
#include"Members.h"
#include"Faculty.h"
#include"Student.h"

using namespace std;

int main()
{
	//initialize and open input file stream
	string input_file_name = "input.txt";
	ifstream fin(input_file_name);

	//Check to see if file opened correctly; Else exit;
	if (fin.fail())
	{
		cout << "Failed to open file.";
		system("Pause");
		return 0;
	}

	//Initialize and open output file streams
	string fac_file = "FacultyOutput.txt";
	string stu_file = "StudentOutput.txt";

	ofstream fout_f, fout_s;
	fout_f.open(fac_file);
	fout_s.open(stu_file);

	//Initialize type variable
	char cur_type;

	//Initialize classes for readWriteMembers function call
	Faculty fac;
	Student stu;

	//Counter for error message
	int line_num = 0;

	while (!fin.eof())
	{
		line_num += 1;
		fin >> cur_type;

		//Read and Write if faculty
		if (cur_type == 'f')
		{
			fac.readWriteMembers(fin, fout_f);
		}

		//Read and Write if student
		else if (cur_type == 's')
		{
			stu.readWriteMembers(fin, fout_s);
		}

		//Type not recognized; Error message and exit
		else
		{
			cout << "Did not recognize identification character on line #" << line_num <<"\nCheck input and try again.";
			system("Pause");
			return 0;
		}
	}

	//Close all streams
	fin.close();
	fout_f.close();
	fout_s.close();

	//Completion message
	cout << "Data successfully read in from " << input_file_name << " and written out to " << fac_file << " & " << stu_file << endl;

	system("Pause");
	return 0;
}