#pragma once
#include "Product.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Shirt:public Product
{
public:
	Shirt();
	void setSize(string xsize);
	void print(ostream & out);
	double calculateTotal();

protected:
	string size;
};