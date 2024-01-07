#include "Osoblje.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
Osoblje::Osoblje()
{
    pay=0;
}
Osoblje::Osoblje(string t,double in,char* p, char* r, int a, char g, string ph) :Osoba(p,r,a,g,ph)
{
    time=t;
    pay=in;

}
void Osoblje::set_time(string t)
{
    time=t;
}
void Osoblje::set_pay(double p)
{
    pay=p;
}
void Osoblje::display_all_staff() {
    ifstream pin("Staff.txt");
    cout << "Ime\tAdresa\tGodine\tSpol\tKontakt\tRadno vrijeme   Plata\tPozicija" << endl;
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
string Osoblje::get_time()
{
    return time;
}
double Osoblje::get_pay()
{
    return pay;
}
void Osoblje::set_position(string p)
{
    position=p;
}
string Osoblje::get_position()
{
    return position;
}
void Osoblje::hire()
{
    char *n=new char[30];
    char* r=new char[30];
    int a=0;
    char g='\0';
    string p_p;
    cout<<"Ime: "<<endl;
    cin.getline(n,29);
    set_person_name(n);
    cout<<"Adresa: "<<endl;
    cin.getline(r,29);
    set_residence(r);
    cout<<"Godine: "<<endl;
    cin>>a;
    set_age(a);
    cout<<"Spol: "<<endl;
    cin>>g;
    set_gender(g);
    cout<<"Kontakt (broj): "<<endl;
    cin>>p_p;
    set_person_phone(p_p);
    cout<<"Pozicija: "<<endl;
    cin>>position;
}
void Osoblje::display()
{
    cout<<"Radno vrijeme: "<<time<<endl;
    cout<<"Plata: "<<pay<<endl;
    //cout<<"Position: "<<position<<endl;
    Osoba::display();
}
Osoblje::~Osoblje()
{
}