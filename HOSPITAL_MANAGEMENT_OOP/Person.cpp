#include "Person.h"
Person::Person()
{
	person_name=new char[30];
	residence=new char[30];
	age=0;
	gender='\0';
}
Person::Person(char* p, char* r, int a, char g, string ph)
{
	person_name = new char[30];
	residence = new char[30];
	age = 0;
	gender = '\0';
	
	int count = 0;
	
	for (int i = 0; p[i] != '\0'; i++)
	{
		
		person_name[i] = p[i];
		count++;
	}

	person_name[count] = '\0';

	 count = 0;
	for (int i = 0; r[i] != '\0'; i++)
	{
		residence[i] = r[i];
		count++;
	}
	residence[count] = '\0';

	age = a;
	gender = g;
	person_phone = ph;


}

void Person::display()
{
    cout << "Ime:"  <<  person_name << endl;
    cout << "Adresa:" << residence << endl;
    cout <<  "God:"  << age << endl;
    cout << "Spol:" << gender << endl;
    cout << "Tel.:" << person_phone << endl;
}
Person::~Person()
{
}