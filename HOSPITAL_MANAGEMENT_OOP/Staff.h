#pragma once

#include <iostream>
#include<string>
#include "Person.h"
using namespace std;

class Staff:public Person
{
private:
	string timming;
	double pay;
	string position;
public:
	Staff();
	Staff(string,double,char*,char*,int,char,string);
	void display_all_staff();
	virtual void display();
	
	~Staff();
};