#include "Product.h"

Product::Product()
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies
	//Postcondition: Referenced object's price = 0, quantity = 0, and description = "";
	price = 0;
	quantity = 0;
	description = "";
}

Product::Product(double xprice, int xquantity)
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies; Pass in xprice of type double and xquantity of type int;
	//Postcondition: Referenced object's price = xprice and quantity = xquantity;
	price = xprice;
	quantity = xquantity;
}

void Product::setPrice(double xprice)
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies; Pass in xprice of type double
	//Postcondition: Referenced object's price = xprice;
	price = xprice;
}

void Product::setQuantity(int xquantity)
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies; Pass in xquantity of type int;
	//Postcondition: Referenced object's quantity = xquantity;
	quantity = xquantity;
}

void Product::setDescription(string xdescription)
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies; Pass in xdescription of type string;
	//Postcondition: Referenced object's description = xdescription;
	description = xdescription;
}

double Product::calculateTotal()
{
	//Precondition: Pointer of type Product pointing to initialized object of type Shirt or OfficeSupplies
	//Postcondition: Return price multiplied by quantity
	return quantity * price;
}
