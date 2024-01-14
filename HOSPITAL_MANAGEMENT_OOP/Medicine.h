#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Medicine
{
private:
	string medicine_type;
public:
	Medicine();
	friend istream& operator>>(istream& stream,Medicine& med);
	friend ostream& operator<<(ostream& stream,Medicine& med);
	void create_file_medicine();
	void display_file_medicine();
	~Medicine();
};