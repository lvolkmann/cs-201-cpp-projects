#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class Product
{
public:
	Product();
	Product(double xprice, int xquantity);
	void setPrice(double xprice);
	void setQuantity(int xquantity);
	void setDescription(string xdescription);
	virtual void print(ostream & out) = 0;
	virtual double calculateTotal();

protected:
	double price;
	int quantity;
	string description;
};