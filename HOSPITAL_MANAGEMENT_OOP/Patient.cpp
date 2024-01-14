#include "Patient.h"
#include <iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;


Patient::Patient()
{
	room_allot=0;
}
Patient::Patient(Room & ro,string prob, string ta, string td, double f,int room, char* p, char* r, int a, char g, string ph) :Person(p, r, a, g, ph)
{
	this->rooms = &ro;
	problem = prob;
	time_admit = ta;
	time_discharge = td;
	fee_charged = f;
	room_allot = room;
}

int Patient::check_file_size()
{
	int count = 0;
	ifstream scan("Patients.txt");

	for (int i = 0; !scan.eof(); i++)
	{
		char *temp = new char[30];
		scan.getline(temp, 30);
		count++;
	}
	return count / 10;
	
}
void Patient::discharge_file_update(string *n, string *r, string *ag , string *g, string *ph, string *pro , string *taa, string *tdd, string *f, string *roo, int size,int skip)
{
	ofstream out("Patients.txt");

	for (int i = 0; i < size; i++)
	{
		if (i != skip)
		{

			out << n[i] << endl;
			out << r[i] << endl;
			out << ag[i] << endl;
			out << g[i] << endl;
			out << ph[i] << endl;
			out << pro[i] << endl;
			out << taa[i] << endl;
			out << tdd[i] << endl;
			out << f[i] << endl;
			out << roo[i] << endl;
		}
	}
}
void Patient::discharge_patient()
{
	int size = 0;
	size=check_file_size();
	string *temp_name = new string[size];
	string *temp_res = new string[size];
	string *temp_age = new string[size];
	string *temp_gender = new string[size];
	string *temp_con = new string[size];
	string *temp_prob = new string[size];
	string *temp_ta = new string[size];
	string *temp_td = new string[size];
	string *temp_fee = new string[size];
	string *temp_room = new string[size];

	ifstream input("Patients.txt");

	for (int i = 0; i < size; i++)
	{
		getline(input, temp_name[i]);
		getline(input, temp_res[i]);
		getline(input, temp_age[i]);
		getline(input, temp_gender[i]);
		getline(input, temp_con[i]);
		getline(input, temp_prob[i]);
		getline(input, temp_ta[i]);
		getline(input, temp_td[i]);
		getline(input, temp_fee[i]);
		getline(input, temp_room[i]);
	}
	cout << "Otpusti pacijenta na osnovu: " << endl;
	cout << "1) imena " << endl << "2) prebivalista" << endl;
	int choice = 0;
	cin >> choice;
	int index = 0;
	if (choice == 1) // by name
	{
		int check = 0;
		cout << "Unesite ime: " << endl;
		cin.ignore();
		string dis_name;
		getline(cin, dis_name);
		for (int i = 0; i < size; i++)
		{
			if (dis_name == temp_name[i])
			{
				index = i;
				cout << "\t\t\t\t\t************************" << endl;
				cout << "\t\t\t\t\t  Pacijent otpusten!" << endl;
				cout << "\t\t\t\t\t************************" << endl;
				check++;
				int a = std::stoi(temp_room[index]);
				this->rooms->set_free_r(a);
				discharge_file_update(temp_name, temp_res, temp_age, temp_gender, temp_con, temp_prob, temp_ta, temp_td, temp_fee, temp_room, size,index);
				break;
				
			}
		}
		if (check == 0)
		{
			cout << "\t\t\t\t\t***************************" << endl;
			cout << "\t\t\t\t\t  Pacijent nije pronadjen!" << endl;
			cout << "\t\t\t\t\t***************************" << endl;
		}

	}
	else if (choice == 2)
	{
		int check = 0;
		cout << "Unesite prebivaliste: " << endl;
		cin.ignore();
		string re;
		getline(cin, re);
		for (int i = 0; i < size; i++)
		{
			if (re == temp_res[i])
			{
				index = i;
				cout << "\t\t\t\t\t************************" << endl;
				cout << "\t\t\t\t\t  Pacijent otpusten!" << endl;
				cout << "\t\t\t\t\t************************" << endl;
				check++;
				int a = std::stoi(temp_room[index]);
				this->rooms->set_free_r(a);
				discharge_file_update(temp_name, temp_res, temp_age, temp_gender, temp_con, temp_prob, temp_ta, temp_td, temp_fee, temp_room, size, index);
				break;

			}
		}
		if (check == 0)
		{
			cout << "\t\t\t\t\t**************************" << endl;
			cout << "\t\t\t\t\t  Pacijent nije pronadjen!" << endl;
			cout << "\t\t\t\t\t***************************" << endl;
		}
	}
}
int Patient::find_length(char *arr)
{
	int len = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
void Patient::set_room(Room& object)
{
	this->rooms = &object;
}
void Patient::display_rooms()
{
	this->rooms->display_rooms();
}
int Patient::compare(char *to_find,char *to_find_in,int size)
{
	for (int i = 0; to_find_in[i] != '\0'; i++)
	{
		if (to_find[0] == to_find_in[i])
		{
			int index = i;
			int count = 0;
			for (int j = 0; to_find[j] != '\0'; j++)
			{
				if (to_find[j] == to_find_in[index])
				{
					count++;
					index++;
				}
			}
			if (count == size)
			{
				return 1;
			}

		}
	}
	return 0;
}
void Patient::search_patient()
{
    int choose=0;
    cout<<"Na osnovu cega zelite pretraziti? "<<endl;
    cout<<"1. Ime"<<endl;
    cout<<"2. Prebivaliste" << endl;
    cout<<endl<<"Unos: "<<endl;
    cin >> choose;
    ifstream pscan("Patients.txt");

    if (choose==1)// by name
    {
        int flag = 0;
        char* name = new char[30];
        cout << "Unesite ime: ";
        cin.ignore();
        cin.getline(name, 30);
        int size=find_length(name);

        int count = 0;
        for (int i = 0; !pscan.eof(); i++)
        {

            char *temp = new char[100];
            pscan.getline(temp, 100);
            if (count == 0)
            {

                flag = compare(name, temp, size);
                if (flag > 0)
                {
                    cout << "Podaci:" << endl;
                    cout << left << setw(15) << "Ime" << '\t' << setw(15) << "Adresa" << '\t' << setw(8) << "Godine"
                         << '\t' << setw(8) << "Spol" << '\t' << setw(15) << "Kontakt" << '\t' << setw(15) << "Bolest"
                         << '\t' << setw(15) << "Prijem" << '\t' << setw(15) << "Otpust" << '\t' << setw(5) << "Cijena"
                         << '\t' << setw(10) << "Soba" << endl;
                    cout << "********************************************************************************************************************************" << endl;

                    cout << left << setw(15) << temp << '\t' << setw(15) << right;

                    int print = 9;
                    for (int j = 0; j < print; j++) {
                        char *p = new char[50];
                        pscan.getline(p, 50);
                        cout << left << setw(15) << p << '\t';
                    }

                    cout << endl;
                    break;
                }
            }
            count++;
            if (count == 10){
                count = 0;
            }

        }
        if (flag == 0)
        {
            cout << "Nije pronadjena!" << endl;
        }
    }
    else if (choose==2) // by residence
    {
        int flag = 0;

        char* res = new char[30];
        cout << "Unesite prebivaliste: ";
        cin.ignore();
        cin.getline(res, 30);
        int size = find_length(res);

        int count = 0;
        for (int i = 0; !pscan.eof(); i++)
        {
            char* name = new char[30];
            char *temp = new char[100];
            pscan.getline(name, 30);
            pscan.getline(temp, 100);
            if (count == 0)
            {

                flag = compare(res, temp, size);
                if (flag > 0)
                {
                    cout << "Podaci: " << endl;
                    cout << name << endl;
                    cout << temp << endl;

                    int print = 8;
                    for (int j = 0; j < print; j++)
                    {
                        char *p = new char[50];
                        pscan.getline(p, 50);
                        cout << p << endl;
                    }
                    break;
                }
            }
            count++;
            if (count == 5)
            {
                count = 0;
            }

        }
        if (flag == 0)
        {
            cout << "Nije pronadjeno!" << endl;
        }
    }}
void  Patient::display()
{
	cout << "Dijagnoza: " << problem<<endl;
	cout << "Vrijeme prijema: " << time_admit << endl;
	cout << "Vrijeme otpusta: " << time_discharge << endl;
	cout << "Cijena pregleda: " << fee_charged << endl;
	cout << "Broj sobe: " << room_allot << endl;
	Person::display();
}
void Patient::display_all_patients()
{
    ifstream pin("Patients.txt");

    cout << left << setw(15) << "Ime" << setw(15) << "Adresa" << setw(8) << "God"
         << setw(8) << "Spol" << setw(15) << "Kontakt" << setw(15) << "Bolest"
         << setw(15) << "Prijem" << setw(15) << "Otpust" << setw(8) << "Cijena"
         << setw(10) << "Soba" << endl;

    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    while (!pin.eof())
    {
        string name, residence, age, gender, contact, disease, timeIn, timeOut, fee, roomNo;

        getline(pin, name);
        getline(pin, residence);
        getline(pin, age);
        getline(pin, gender);
        getline(pin, contact);
        getline(pin, disease);
        getline(pin, timeIn);
        getline(pin, timeOut);
        getline(pin, fee);
        getline(pin, roomNo);

        cout << left << setw(15) << name << setw(15) << residence << setw(8) << age
             << setw(8) << gender << setw(15) << contact << setw(15) << disease
             << setw(15) << timeIn << setw(15) << timeOut << setw(8) << fee
              << roomNo << endl;
    }

    pin.close();
}

void Patient::update_patient_file(string prob, string ta, string td, double f, int room, char* p, char* r, int a, char g, string ph)
{
	ofstream docout("Patients.txt", ios::app);

	docout << p <<endl;
	docout << r << endl;
	docout << a << endl;
	docout << g << endl;
	docout << ph << endl;
	docout << prob << endl;
	docout << ta << endl;
	docout << td << endl;
	docout << f << endl;
	docout << room << endl;
	

	docout.close();
}
Patient::~Patient()
{
}