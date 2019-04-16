#pragma once
#include "Product.h"
#include<iostream>
#include<string>
#include<fstream>


class OfficeSupplies :public Product
{
public:
	OfficeSupplies();
	void setCount(string xcount);
	void print(ostream & out);
protected:
	string count;
};