#include "Osoba.h"

Osoba::Osoba()
{
    person_name=new char[30];
    residence=new char[30];
    age=0;
    gender='\0';
}
Osoba::Osoba(char* p, char* r, int a, char g, string ph)
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
void Osoba::set_person_name(char* p)
{
    int count=0;
    for(int i=0;p[i]!='\0';i++)
    {
        person_name[i]=p[i];
        count++;
    }
    person_name[count]='\0';


}
void Osoba::set_residence(char* r)
{
    int count=0;
    for(int i=0;r[i]!='\0';i++)
    {
        residence[i]=r[i];
        count++;
    }
    residence[count]='\0';
}
void Osoba::set_age(int a)
{
    age=a;
}
void Osoba::set_gender(char g)
{
    gender=g;
}
void Osoba::set_person_phone(string p)
{
    person_phone=p;
}
char* Osoba::get_person_name()
{
    return person_name;
}
char* Osoba::get_residence()
{
    return residence;
}
int Osoba::get_age()
{
    return age;
}
char Osoba::get_gender()
{
    return gender;
}
string Osoba::get_person_phone()
{
    return person_phone;
}
void Osoba::display()
{
    cout << "Name: " << person_name << endl;
    cout << "Residence: " << residence << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "phone: " << person_phone << endl;


}
Osoba::~Osoba() {
}