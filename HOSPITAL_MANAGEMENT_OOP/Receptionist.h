#pragma once

#include <iostream>
#include<string>
#include "Staff.h"
using namespace std;

class Receptionist:public Staff
{
private:
	string education;
public:
	Receptionist();
	Receptionist(string,string, double, char*, char*, int, char, string);
	void display();
	void update_recep_file(string, string, double, char*, char*, int, char, string);
	~Receptionist();
};