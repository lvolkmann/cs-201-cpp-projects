#include "Shirt.h"

Shirt::Shirt()
{
	//Precondition: N/A
	//Postcondition: Initialized object of type Shirt with price = 0, quantity = 0, description = "", size = ""
	price = 0;
	quantity = 0;
	description = "";
	size = "";
}

void Shirt::setSize(string xsize)
{
	//Precondition: Initialized object of type Shirt; Pass in xsize of type string
	//Postcondition: Size is set equal to xsize
	size = xsize;
}

void Shirt::print(ostream & out)
{
	//Precondition: Pass in out of type ostream
	//Postcondition: Output formatted row of item containing quanity, description, size, and total price
	out << std::right;
	out << std::setw(3) << quantity << " ";

	out << std::left;
	out << std::setw(28) << size + " " + description;

	out << std::fixed << std::setprecision(2);
	out << "$ " << std::setw(6) << calculateTotal() << endl;
}

double Shirt::calculateTotal()
{
	//Precondition: Initialized object of type Shirt
	//Postcondition: If size equivalent to 2XL or 3XL, return price incremented by 1 then multiplied by quantity;
	//				 Else, return price multiplied by quantity
	if(size == "2XL" || size == "3XL")
		return (price + 1) * quantity;
	else
		return price * quantity;
}
