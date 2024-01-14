#include "Staff.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
Staff::Staff()
{
	pay=0;
}
Staff::Staff(string t,double in,char* p, char* r, int a, char g, string ph) :Person(p,r,a,g,ph)
{
	timming=t;
	pay=in;
	
}

void Staff::display_all_staff()
{
	ifstream pin("Staff.txt");
	cout << "Ime\t      Adresa\tGod   Spol Kontakt\tVrijeme     Plata  Pozicija" << endl;
	int count = 0;
	for (int i = 0; !pin.eof(); i++)
	{
		char* data = new char[50];
		pin.getline(data, 50);
		count++;
		cout << data << "    ";
		if (count == 8)
		{
			cout << endl;
			cout << "*****************************************************************************************************"<<endl;
			count = 0;
		}
	}
}

void Staff::display()
{
	cout<<"Radno vrijeme: "<<timming<<endl;
	cout<<"Plata: "<<pay<<endl;

	Person::display();
}
Staff::~Staff()
{
}