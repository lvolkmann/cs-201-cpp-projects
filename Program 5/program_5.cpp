//Landon Volkmann
//CS 201
//Program 5

#include<iostream>
#include<fstream>
#include<string>
#include"Product.h"
#include"Shirt.h"
#include"OfficeSupplies.h"
#include"Register.h"
using namespace std;

int main()
{
	//Initialize in and out streams
	ifstream fin("products.txt");
	ofstream fout("receipt.txt");

	//If fail to open input file: QUIT
	if (fin.fail())
	{
		fout << "Failed to open file!";
		return 0;
	}

	//Temp variables for storage
	string type, description, quality, blank;
	int quantity;
	double price;

	//Initialize objects to populate
	Product * p = NULL;
	Shirt shirts[50];
	int shirtCount = 0;
	OfficeSupplies supplies[50];
	int suppliesCount = 0;
	Register reg;

	//Main Loop
	while (!fin.eof())
	{
		//Get data
		getline(fin, type);
		getline(fin, description);
		getline(fin, quality);
		fin >> quantity >> price;
		fin.ignore();
		fin.ignore();

		
		if (type == "SHIRT")
		{
			//Create object of type Shirt and set size
			shirts[shirtCount].setSize(quality);
			p = &shirts[shirtCount];
			shirtCount += 1;
		}
		else if (type == "SUPPLIES")
		{
			//Create object of type OfficeSupplies and set cout
			supplies[suppliesCount].setCount(quality);
			p = &supplies[suppliesCount];
			suppliesCount += 1;
		}
		else
		{
			//Quit Program
			fout << "Something went wrong";
			return 0;
		}

		//Populate the rest of the general member variables
		p->setDescription(description);
		p->setQuantity(quantity);
		p->setPrice(price);

		//Add product to register
		reg.addProduct(p);
	}

	//Output results
	reg.printReceipt(fout);
	
	//Close open files and quit
	fin.close();
	fout.close();
	return 0;
}