#pragma once

#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	char* person_name;
	char* residence;
	int age;
	char gender;
	string person_phone;
public:
	Person();
	Person(char*,char*,int,char,string);
	virtual void display();
	~Person();
};