#include "Account.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

double Account::amount = 10000;

Account::Account()
{

}
void Account:: display()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                      DOBRODOSLI!                         * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                   VitaCare Hospital                      * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *               Registracija  /  Prijava                   * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}
void Account::setHospital(Hospital& obj)
{
    this->hos = &obj;

}
void Account::hospital_display()
{
    this->hos->hospital_dis();
}

void Account:: create_acc_display()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                    KREIRAJTE RACUN                       * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}

void Account::sign_in_display()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                          PRIJAVITE SE                    * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}
int Account::check_repeat_username(string namee)
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


void Account::sign_up()
{

    create_acc_display();
    //username
    ofstream scan("usernames.txt", ios::app);
    scan.close();
    ofstream scan1("passwords.txt", ios::app);
    scan1.close();

    string namee;
    cin.ignore();

    bool success = false;

    while (!success) {
        try {
            // Username input loop
            while (true) {
                cout << "Unesite korisnicko ime: " << endl;
                getline(cin, namee);

                int x = check_repeat_username(namee);

                if (x == 1) {
                    cerr << "[Greska] Korisnicko ime zauzeto, unesite ponovo." << endl;
                } else {
                    break; // Break out of the username input loop
                }
            }

            // Password input loop
            while (true) {
                cout << "Unesite lozinku: " << endl;
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
                cout << endl << "Potvrdite lozinku: " << endl;

                char ch2;
                ch2 = _getch();
                while (ch2 != 13) //character 13 is enter
                {
                    pass2.push_back(ch2);
                    cout << '*';
                    ch2 = _getch();
                }

                if (pass2 == pass) {
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

                    success = true; // izlaz iz glavne petlje - uspjesan login
                    break;
                } else {
                    cerr << "[Greska] Lozinke se ne poklapaju, unesite ponovo." << endl;
                }
            }
        } catch (const exception& e) {
            cerr << "[Greska] " << e.what() << endl;
        } catch (...) {
            cerr << "[GRESKA] Nepoznata greska!\n";
        }
    }

    //return success;

}
int Account:: sign_in()
{
    cin.ignore();
    username_again:
    ifstream readN("usernames.txt");
    if (!readN.is_open())
    {
        cout << "\t\t\t\t\tMorate se prvo prijaviti!" << endl;
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
        cout << endl << "Unesite lozinku: " << endl;
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
            cout <<"\t\t\t\t\t  Uspjesna prijava!             " << endl;
            cout <<  "\t\t\t\t\t**************************" << endl;
        }
        else
        {
            cout<<endl << "Pogresna lozinka!" << endl;
            cout << "\t\t\t 1) Pokusajte ponovo  2) Zaboravljena lozinka" << endl;
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
int Account::forgot_password() {
    ofstream fpass("Reset_Password.txt");

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        int a = 0;
        a = rand() % 10 + 1;
        fpass << a;
    }
    fpass << endl;
    cout << endl << "Unesite kod iz Reset_Password file-a " << endl;
    cout << "Code: ";

    try {
        ifstream rpass("Reset_Password.txt");
        if (!rpass.is_open()) {
            throw runtime_error("Greska pri otvaranju Reset_Password.txt");
        }

        string check_code;
        rpass >> check_code;

        while (true) {
            string code;
            cin >> code;

            if (check_code == code) {
                cout << endl << "  Kod se poklapa!" << endl;
                cout << "  Promijenite lozinku" << endl;
                change_password();
                return 0;
            } else {
                throw runtime_error("Kod se ne poklapa!");
            }
        }
    } catch (const exception& e) {
        cerr << "[Greska] " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "[GRESKA] Nepoznata greska!\n";
        return 1;
    }
}
int Account::change_password() {
    ifstream cname("usernames.txt");
    ifstream cpass("passwords.txt");
    int size = 0;
    cin.ignore();
    try {
        for (int i = 0; !cname.eof(); i++) {
            string temp;
            getline(cname, temp);
            size++;
        }
        if (size <= 1) {
            throw runtime_error("Nisu pronadeni korisnici! Prvo se registrujte!");
        }
        size = size - 1;

        string temp_name[100];
        string temp_pass[100];
        cname.close();
        cname.open("usernames.txt");

        for (int i = 0; i < size; i++) {
            string temp;
            string temp2;
            getline(cname, temp);
            getline(cpass, temp2);

            temp_name[i] = temp;
            temp_pass[i] = temp2;
        }

        int index = -1;
        for (int i = 0; i < size; i++) {
            if (name == temp_name[i]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            throw runtime_error("Korisnik nije pronaden!");
        }

        cout << endl << endl;

        string pass = "";
        string pass2 = "";

        while (true) {
            cout << "Unesite novu lozinku" << endl;
            char ch;
            ch = _getch();
            while (ch != 13) //character 13 is enter
            {
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }

            cout << endl << "Potvrdite lozinku" << endl;
            char ch2;
            ch2 = _getch();
            while (ch2 != 13) //character 13 is enter
            {
                pass2.push_back(ch2);
                cout << '*';
                ch2 = _getch();
            }

            if (pass2 == pass) {
                cout << endl << "Lozinka uspjesno promijenjena" << endl;
                temp_pass[index] = pass;
                ofstream wpass("passwords.txt");

                for (int i = 0; i < size; i++) {
                    wpass << temp_pass[i];
                    wpass << endl;
                }
                wpass.close();
                system("pause");
                system("cls");
                break;
            } else {
                cerr << "Lozinke se ne poklapaju. Pokusajte ponovo." << endl;
                pass.clear();
                pass2.clear();
            }
        }
    } catch (const exception& e) {
        cerr << "[Greska] " << e.what() << endl;
    } catch (...) {
        cerr << "[GRESKA] Nepoznata greska!\n";
    }

    return 0;
}

Account::~Account()
{
}
