#include "Snacks.h"
#include"Account.h"
#include <iostream>
#include <fstream>
Snacks::Snacks()
{
}
istream& operator>>(istream& stream, Snacks& s)
{
    Account ac;
    s.display_snack_file();
    cout << endl;

    cout << endl << "Trenutni budzet bolnice: " << ac.amount << endl << endl;

    while (true)
    {
        cout << "Izaberite snack: " << endl;
        stream >> s.snack_type;
        cout << endl;

        ifstream sread("SNACKS.txt");
        int check = 0;
        string sn, pr, quantity;

        while (sread >> sn)
        {
            sread >> quantity;
            sread >> pr;

            if (s.snack_type == sn)
            {
                check++;
                break;
            }
        }

        if (check == 0)
        {
            cout << endl << "\t\t\t\t**********************************************" << endl;
            cout << "\t\t\t\t    Nije pronadjeno, pokusajte ponovo!" << endl;
            cout << "\t\t\t\t**********************************************" << endl;
        }
        else
        {
            int quan, buy, a;

            try {
                quan = std::stoi(quantity);
                cout << endl << " Unesite kolicinu za kupovinu: ";
                cin >> buy;

                if (cin.fail() || buy < 0 || buy > quan)
                {
                    throw std::invalid_argument("Nedostupna unesena kolicina!");
                }

                a = std::stoi(pr);
                if (ac.amount <= 0 || ac.amount - (buy * a) < 0)
                {
                    cout << "\t\t\t\tKupovina nije moguca" << endl;
                    cout << "\t\t\t\tNedovoljan budzet" << endl;
                    cout << "\t\t\t\tIzlaz" << endl << endl;
                }
                else
                {
                    cout << endl << "\t\t\t\t   ************************************" << endl;
                    cout << "\t\t\t\t\t Kupovina uspjesna!  " << endl;
                    cout << "\t\t\t\t\t Kupili ste: " << s.snack_type << endl;
                    cout << "\t\t\t\t   ************************************" << endl;
                    ac.amount = ac.amount - (buy * a);
                    break;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Greska: " << e.what() << std::endl;
                cin.clear();
                cin.ignore();
            }
        }
        cout << endl << "Dostupan budzet : " << ac.amount << endl;
    }

    return stream;
}


ostream& operator<<(ostream& stream,Snacks& s)
{

	
	stream << "Povratak nazad" << endl;
	return stream;
}
void Snacks::create_snack_file()
{
		
	ofstream snackout("SNACKS.txt");

	snackout<<"SNACKS\t\tKolicina\tCijena";
	snackout<<endl;
	snackout<<"Cips\t\t 10\t\t 3";
	snackout<<endl;
	snackout<<"Voda\t\t 10\t\t 2";
	snackout<<endl;
	snackout<<"Cola\t\t 10\t\t 3";
	snackout<<endl;
	snackout<<"Keks\t\t 10\t\t 4";
	snackout<<endl;
	snackout<<"Caj\t\t 10\t\t 2";
    snackout<< endl;
	snackout<<"Sok\t\t 10\t\t 3";
	
	
}
void Snacks::display_snack_file()
{
	ifstream sin("SNACKS.txt");
	string s,q,p;
	sin>>s;
	sin>>q;
	sin>>p;
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
	cout << "\t\t\t\t" << s << "\t\t" << q << "\t" << p;
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
	for(int i=0;!sin.eof();i++)
	{
		sin>>s;
		sin>>q;
		sin>>p;
	 cout<<endl;
	 cout<<"\t\t\t\t"<<s<<"\t\t"<<q<<"\t\t"<<p;
	}
	cout << endl << "\t\t\t" << "*****************************************************" << endl;
}
Snacks::~Snacks()
{
}