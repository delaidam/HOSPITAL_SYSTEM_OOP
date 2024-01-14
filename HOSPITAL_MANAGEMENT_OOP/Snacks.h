#pragma once


#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class Snacks
{
private:
	string snack_type;
public:
	Snacks();
	void create_snack_file();
	void display_snack_file();
	friend istream& operator>>(istream& stream,Snacks& s);
	friend ostream& operator<<(ostream& stream,Snacks& s);
	~Snacks();
};