#include "Login.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

double Login::amount = 1000;

Login::Login()
{

}
void Login:: disp()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                       DOBRODOSLI                         * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                   VitaCare Hospital                      * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                      SignUp  /  SingIn                   * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}
void Login::set_hospital(Hospital& obj)
{
    this->hos = &obj;

}
void Login::hospital_dis()
{
    this->hos->hospital_dis();
}

void Login:: create_acc_disp()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                    CREATE AN Login                       * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}

void Login::sign_in_disp()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                          SIGN IN                         * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}
int Login::check_repeat_username(string namee)
{
    ifstream scan("usernames.txt");

    int check = 0;

    for (int i = 0; !scan.eof(); i++)
    {
        string n;
        getline(scan, n);
        if (n == namee)
        {
            check++;
            break;
        }
    }
    if (check == 1)
    {
        return 1;
    }
    else
        return 0;



}

void Login::sign_up()
{

    create_acc_disp();
    //username
    ofstream scan("usernames.txt", ios::app);
    scan.close();
    ofstream scan1("passwords.txt", ios::app);
    scan1.close();

    string namee;
    cin.ignore();
    enter_u:
    cout << "Unesite korisnicko ime: " << endl;
    getline(cin,namee);

    int x = check_repeat_username(namee);

    if ( x==1)
    {
        cout << "\t\t\t\t\t********************************" << endl;
        cout << "\t\t\t\t\t  Korisnicko ime zauzeto, unesite ponovo: " << endl;
        cout << "\t\t\t\t\t********************************" << endl;
        goto enter_u;
    }


    pass_enter:
    cout << "Unesite sifru: " << endl;
    string pass = "";
    string pass2 = "";

    char ch;
    ch = _getch();
    while (ch != 13) //character 13 is enter
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl << "Potvrdite sifru: " << endl;

    char ch2;
    ch2 = _getch();
    while (ch2 != 13) //character 13 is enter
    {
        pass2.push_back(ch2);
        cout << '*';
        ch2 = _getch();
    }

    if (pass2 == pass)
    {
        cout << endl;
        cout << "\t\t\t\t\t ***********************" << endl;
        cout << "\t\t\t\t\t *  Racun kreiran!   *" << endl;
        cout << "\t\t\t\t\t * Mozete se prijaviti! *" << endl;
        cout << "\t\t\t\t\t ***********************" << endl;
        ofstream fname("usernames.txt", ios::app);
        ofstream fpass("passwords.txt", ios::app);

        fname << namee;
        fname << endl;
        fpass << pass;
        fpass << endl;

        fname.close();
        fpass.close();

        system("pause");
        system("cls");
    }
    else
    {

        cout << "Sifre se ne poklapaju, unesite ponovo!" << endl;
        goto pass_enter;
    }

}
int Login:: sign_in()
{
    cin.ignore();
    username_again:
    ifstream readN("usernames.txt");
    if (!readN.is_open())
    {
        cout << "\t\t\t\t\tMorate prvo napraviti racun!" << endl;
        system("pause");
        system("cls");
        return 0;

    }
    ifstream readP("passwords.txt");

    string pass;


    int check = 0;
    cout << "Unesite korisnicko ime: " << endl;

    getline( cin,this->name);
    for (int i = 0; !readN.eof(); i++)
    {
        string n, p;
        getline(readN,n);

        getline(readP,p);
        if (n == this->name)
        {
            check++;
            pass = p;
            break;
        }
    }
    if (check == 0)
    {
        cout << endl<<"\t\t\t\t\t**********************"<<endl;
        cout << "\t\t\t\t\t Korisnicko ime nije pronadeno!" << endl;
        cout << "\t\t\t\t\t**********************" << endl;
        goto username_again;
    }
    else
    {
        pass_again:
        cout << endl << "Unesite sifru: " << endl;
        string p;
        char ch2;
        ch2 = _getch();
        while (ch2 != 13) //character 13 is enter
        {
            p.push_back(ch2);
            cout << '*';
            ch2 = _getch();
        }
        if (p == pass)
        {
            cout << endl << "\t\t\t\t\t**************************" << endl;
            cout <<"\t\t\t\t\t  Uspjesan login!   " << endl;
            cout <<  "\t\t\t\t\t**************************" << endl;
        }
        else
        {
            cout<<endl << "Pogresna sifra!" << endl;
            cout << "\t\t\t 1) Ponovni unos 2) Forgot Password" << endl;
            int c = 0;
            cin >> c;

            if (c == 1)
            {
                goto pass_again;
            }
            else
            {
                system("pause");
                system("cls");
                forgot_password();

                return 0;

            }


        }
    }

    system("pause");
    system("cls");
    return 1;

}
int Login::forgot_password()
{
    ofstream fpass("Reset_Password.txt");

    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        int a=0;
        a = rand()%10+1;
        fpass << a;
    }
    fpass << endl;
    cout <<endl<< "Unesite kod iz Reset Password file-a " << endl;
    cout << "Kod: ";
    ifstream rpass("Reset_Password.txt");
    string check_code;
    rpass >> check_code;

    enter_code_again:
    string code;
    cin >> code;

    if (check_code == code)
    {
        cout<<endl << "  Kod se poklapa!" << endl;
        cout << "  Promijenite sifru: " << endl;
        change_password();
        return 0;

    }
    else
    {
        cout<<endl<< "  Kod se ne poklapa!" << endl;
        cout << "  Unesite ponovo: " << endl;
        goto enter_code_again;
    }



}
int Login::change_password()
{
    ifstream cname("usernames.txt");
    ifstream cpass("passwords.txt");
    int size = 0;
    cin.ignore();
    for (int i = 0; !cname.eof(); i++)
    {
        string temp;
        getline(cname,temp);
        size++;

    }
    size = size - 1;
    /*string *temp_name = new string[size];
    string *temp_pass = new string[size];*/
    string temp_name[100];
    string temp_pass[100];
    cname.close();
    cname.open("usernames.txt");
    for (int i = 0; i<size; i++)
    {
        string temp;
        string temp2;
        getline(cname, temp);
        getline(cpass, temp2);

        temp_name[i] = temp;
        temp_pass[i] = temp2;

    }

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (name == temp_name[i])
        {
            index = i;
            break;
        }
    }

    cout << endl << endl;


    pass_enter2:
    cout << "Unesite novu sifru: " << endl;
    string pass = "";
    string pass2 = "";

    char ch;
    ch = _getch();
    while (ch != 13) //character 13 is enter
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl << "Potvrdite sifru: " << endl;

    char ch2;
    ch2 = _getch();
    while (ch2 != 13) //character 13 is enter
    {
        pass2.push_back(ch2);
        cout << '*';
        ch2 = _getch();
    }

    if (pass2 == pass)
    {
        cout << endl<<"Sifra uspjesno promijenjena" << endl;
        temp_pass[index] = pass;
        ofstream wpass("passwords.txt");

        for (int i = 0; i < size; i++)
        {
            wpass << temp_pass[i];
            wpass << endl;
        }
        wpass.close();
        system("pause");
        system("cls");
        return 0;
    }
    else
    {
        cout <<endl<<"Pogresna sifra, unesite ponovo: " << endl;
        goto pass_enter2;
    }

}
Login::~Login()
{
}
//
// Created by Delaida Muminovic on 1/5/2024.
//
