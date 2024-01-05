#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include "Login.h"
using namespace std;

void create_doctor_surgeon_file()
{
    ofstream docout("Doctors.txt");

    docout << "Tom han  ";
    docout << "123 block 3  ";
    docout << "43  ";
    docout << "M  ";
    docout << "0333-12312312  ";
    docout << "11:22-12:00  ";
    docout << "7  ";
    docout << "12300  ";
    docout << "General Surgeon  ";
    docout << endl;

    docout << "miley han  ";
    docout << "345 block 3  ";
    docout << "33  ";
    docout << "F  ";
    docout << "0333-7898878  ";
    docout << "1:22-5:00  ";
    docout << "9 ";
    docout << "1000  ";
    docout << "Lady Surgeon  ";
    docout << endl;
}
void create_staff_file()
{
    ofstream pout("Staff.txt");

    pout << "Tom han" << endl;
    pout << "123 block 3"<<endl;
    pout << "43"<<endl;
    pout << "M"<<endl;
    pout << "0333-12312312" << endl;
    pout << "11:00-1:00"<<endl;
    pout << "500"<<endl;
    pout << "sweeper"<<endl;


    pout << "billy han" << endl;
    pout << "231 block 31" << endl;
    pout << "33" << endl;
    pout << "M" << endl;
    pout << "0334-112803992" << endl;
    pout << "2:00=5:00" << endl;
    pout << "800" << endl;
    pout << "driver" << endl;

}

void update_doctor_file(char *type, string time /*(string)*/, int cab, double f/*fees (double)*/, char* name, char* res, int ag/*age (int)*/, char g, string con /*(string)*/)
{
    ofstream docout("Doctors.txt",ios::app);

    docout << name<<"  "  ;
    docout << res<<"  ";
    docout << ag<<"  ";
    docout << g<<"  ";
    docout << con<<"  ";
    docout << time<<"  ";
    docout << cab<<"  ";
    docout << f<<"  ";
    docout << type<<"  ";
    docout << endl;

    docout.close();

}
void display_all_doctors()
{
    ifstream docin("Doctors.txt");
    cout << "Name\tResidence    age gender\tConatact    timmings\tcabin\tfee\ttype" << endl;
    for (int i = 0; !docin.eof(); i++)
    {
        char* data = new char[200];
        docin.getline(data,200);
        cout << data << endl;
        cout << "***********************************************************************************" << endl;
    }
}


int main()
{



    Login Acc;
    Room soba1;
    Acc.disp();
    soba1.display_rooms();
    create_doctor_surgeon_file();
    create_Patient();
    create_staff_file();


    int log = 0;

    while (log == 0)
    {
        cout << endl << "\t\t\t\t\t    1)SIGN UP          2)SIGN IN" << endl;
        int choice = 0;

        again1:
        cout << "Enter Choice: " << endl;
        cin >> choice;
        if (choice<0 || choice>2 || !cin)
        {
            cout << "INVALID ENTRY!" << endl;
            cin.clear();
            cin.ignore();
            goto again1;
        }

        system("pause");
        system("cls");
        if (choice == 1)
        {
            Acc.sign_up();
            Acc.disp();
        }
        else if (choice == 2)
        {
            Acc.sign_in_disp();
            log = Acc.sign_in();
        }

    }

        Acc.hospital_dis();

}