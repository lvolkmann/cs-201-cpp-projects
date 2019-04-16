#include "Register.h"

Register::Register()
{
	//Precondition: N/A
	//Postcondition: Object of type Register initialized with numProducts = 0 and array of pointers to Products with a capacity of 50;
	numProducts = 0;
	Product * products[50];
}

void Register::addProduct(Product * &add)
{
	//Precondition: Initialized object of type Register; numProducts < 50; Pass in pointer to object of type Shirt or OfficeSupplies
	//Postcondition: Referenced object added to array of products;
	if (numProducts >= 50)
	{
		cout << "Error! Too many items!";
		system("pause");
	}
	else
	{
		products[numProducts] = add;
		numProducts += 1;
	}
}

void Register::printReceipt(ostream & out)
{
	//Precondition: Initialized object of type Register; Pass in out of type ostream;
	//Postcondition: Output formatted receipt  with header, footer, grand total, items sold, and rows to match print specifications for object of type Shirt and OfficeSupplies;
	out << left;
	out << setw(40) << setfill('*') << "" << endl;
	out << "*" << "  CS 201 Super Seilling Stuff Store  " << "*" << endl;
	out << setw(40) << setfill('*') << "" << endl;
	out << endl << setfill(' ');
	out << "Qty " << setw(28) << "Description" << setw(8) << "Total" << endl;
	out << "--- " << setw(27) << setfill('-') << "" << " " << setw(8) << setfill('-') <<"" << endl;
	out << setfill(' ');
	for (int i = 0; i < numProducts; i++)
		products[i]->print(out);
	out << endl;
	out << "Grand total: $" << calculateGrandTotal() << endl;
	out << "Items sold: " << getItemsSold() << endl;
	out << endl;
	out << "* Thank you for shopping at our store! *";

}

double Register::calculateGrandTotal()
{
	//Precondition: Initialized object of type Register
	//Postcondition: Returns sum of totals for each object in array products;
	double grand = 0;
	for (int i = 0; i < numProducts; i++)
		grand += products[i]->calculateTotal();
	return grand;
}

int Register::getItemsSold()
{
	//Precondition: Initialized object of type Register
	//Postcondition: Return number of objects in array products;
	return numProducts;
}
