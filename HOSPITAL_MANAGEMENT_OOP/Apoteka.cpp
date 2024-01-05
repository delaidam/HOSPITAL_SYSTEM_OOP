#include "Apoteka.h"
using namespace std;

Apoteka::Apoteka():floor(2)
{
    choose = 0;
}
/*
 * uz kasnije implementirane klase za lijekove i hranu
Apoteka::Apoteka(Lijekovi &l,Hrana &h,const int f):floor(f)
{
    lijekovi=m;
    hrana=s;
}*/
std::istream& operator>>(std::istream& stream,Apoteka& a)
{
    again3:
    cout << endl << "\t\t\t\t\t_______________________________" << endl;
    cout<<"\t\t\t\t\t\t   opcija?"<<endl;
    cout<<"\t\t\t\t\t   1. Hrana"<<endl;
    cout<<"\t\t\t\t\t   2. Lijekovi"<<endl;
    cout<<"\t\t\t\t\t   3. Exit"<<endl;
    cout  << "\t\t\t\t\t_______________________________" << endl;
    cin>>a.choose;
    if (a.choose <= 0 || a.choose > 3 || !cin)
    {
        cout <<endl<< "*Nepoznata opcija*" << endl;
        cin.clear();
        cin.ignore();
        goto again3;
    }
    // izbrisan for loop(int i=0;object.choose!=3;i++)
    if (a.choose == 1)
    {
        system("pause");
        system("cls");
        stream>>a.snacks;
        return stream;
    }
    if (a.choose == 2)
    {
        system("pause");
        system("cls");
        stream>>a.medicine;
        return stream;
    }
}
std::ostream& operator<<(std::ostream& stream,Apoteka& a)
{
    if (a.choose == 1)
    {

        stream << a.snacks;
        return stream;
    }
    else if (a.choose == 2)
    {

        stream << a.medicine;
        return stream;
    }

}
Apoteka::~Apoteka()
{
}
