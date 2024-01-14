#pragma once

#include"Snacks.h"
#include "Medicine.h"

class Pharmacy
{
private:
	Medicine medicine;
	Snacks snacks;
	int choose;
	const int floor;
public:
	Pharmacy();
	Pharmacy(Medicine&,Snacks&,const int);
	friend istream& operator>>(istream& stream,Pharmacy& p);
	friend ostream& operator<<(ostream& stream,Pharmacy& p);
	~Pharmacy();
};

