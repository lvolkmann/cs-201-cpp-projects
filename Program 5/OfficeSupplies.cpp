#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies()
{
	//Precondition: N/A
	//Postcondition: Initialized object of type OfficeSupplies with price = 0, quantity = 0, description = "", count = ""
	price = 0;
	quantity = 0;
	description = "";
	count = "";
}

void OfficeSupplies::setCount(string xcount)
{
	//Precondition: Initialized object of type OfficeSupplies; Pass in xcount of type string 
	//Postcondition: Count set equal to xcount
	count = xcount;
}

void OfficeSupplies::print(ostream & out)
{
	//Precondition: Pass in out of type ostream
	//Postcondition: Output formatted row of item containing quanity, description, count, and total price
	out << std::right;
	out << std::setw(3) << quantity << " ";

	out << std::left;
	out << std::setw(28) << description + " (" + count + " count)";

	out << std::fixed << std::setprecision(2);
	out << "$ " << std::setw(6) << calculateTotal() << endl;
}
