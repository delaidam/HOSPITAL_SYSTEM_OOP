#pragma once

#include <iostream>
#include<string>
#include "Person.h"
using namespace std;

class Doctor:public Person
{
private:
	string doctor_timming;
	int cabin;
	double fees;

public:
	Doctor();
	Doctor(string, int, double, char* , char* , int , char , string );
    virtual void display();
	~Doctor();
};