#include "Doctor.h"
#include <iomanip>
Doctor::Doctor()
{
}
Doctor::Doctor(string t, int c, double f, char* p, char* r, int a, char g, string ph) :Person(p,r,a,g,ph)
{
	
	doctor_timming = t;
	cabin = c;
	fees = f;
	
}


void Doctor::display()
{
    cout << left << setw(20) << "Smjena:"  << doctor_timming;
    cout << left << setw(20) << "Ordinacija:" << cabin;
    cout << left << setw(20) << "Plata:" << fees << endl;

    Person::display();
}
Doctor::~Doctor()
{
}