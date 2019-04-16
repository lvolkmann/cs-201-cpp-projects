#pragma once
#include<iostream>
#include"Product.h"
using namespace std;

class Register
{
public:
	Register();
	void addProduct(Product * &add);
	void printReceipt(ostream & out);
	double calculateGrandTotal();
	int getItemsSold();
private:
	int numProducts;
	Product * products [50];
};