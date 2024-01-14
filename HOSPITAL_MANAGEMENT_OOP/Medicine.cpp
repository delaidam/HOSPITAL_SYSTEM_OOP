#include "Medicine.h"
#include"Account.h"
Medicine::Medicine()
{
}
istream& operator>>(istream& stream, Medicine& med)
{
    Account ac;
    med.display_file_medicine();
    cout << endl << "Dostupan budzet " << ac.amount << endl << endl;

    string input;

    while (true)
    {
        cout << endl << "Unesite lijek koji zelite nabaviti: ";
        stream >> med.medicine_type;

        ifstream mread("MEDICINES.txt");
        int check = 0;
        string bolest, kolicina, cijena;

        while (mread >> input)
        {
            mread >> bolest;
            mread >> kolicina;
            mread >> cijena;

            if (med.medicine_type == input)
            {
                check++;
                break;
            }
        }

        if (check == 0)
        {
            cout << endl << "\t\t\t\t**********************************************" << endl;
            cout << "\t\t\t\t   Lijek nije pronadjen, pokusajte ponovo!" << endl;
            cout << endl << "\t\t\t\t**********************************************" << endl;
        }
        else
        {
            int quantity = stoi(kolicina);
            int buy;

            while (true)
            {
                cout << "Unesite kolicinu lijeka: ";
                stream >> input;

                try
                {
                    buy = stoi(input);
                    if (buy < 0)
                    {
                        throw invalid_argument("Pogresan unos!");
                    }

                    if (buy > quantity)
                    {
                        cout << "Unesena kolicina nije dostupna, pokusajte ponovo!" << endl << endl;
                    }
                    else
                    {
                        int a = stoi(cijena);
                        if (ac.amount <= 0 || ac.amount - (buy * a) < 0)
                        {
                            cout << "\t\t\t\tKupovina nije moguca!" << endl;
                            cout << "\t\t\t\tNedovoljan budzet" << endl;
                            cout << "\t\t\t\tIzlaz" << endl << endl;
                        }
                        else
                        {
                            cout << endl << "\t\t\t\t   ************************************" << endl;
                            cout << "\t\t\t\t\t Kupovina uspjesna  " << endl;
                            cout << "\t\t\t\t\t Kupili ste: " << med.medicine_type << endl;
                            cout << "\t\t\t\t   ************************************" << endl;
                            ac.amount = ac.amount - (buy * a);
                        }
                        cout << endl << "Dostupan budzet: " << ac.amount << endl;
                        return stream;
                    }
                }
                catch (const invalid_argument& e)
                {
                    cout << e.what() << endl;
                    stream.clear();
                    stream.ignore();
                }
            }
        }
    }
}


ostream& operator<<(ostream& stream,Medicine& med)
{
	stream << "Povratak" << endl;
	return stream;
}
void Medicine::create_file_medicine()
{
	ofstream mout("MEDICINES.txt");

	mout << "Lijek\t\tBolest\t\tKolicina\t\tCijena";
	mout << endl;
	mout << "Promethazine\t\t Alergija\t\t 25\t\t 60";
	mout << endl;
	mout << "Methadone\t\t Bolovi \t\t 19\t\t 75";
	mout << endl;
	mout << "Acefyl\t\t\t Kasalj \t\t 23\t\t 45";
	mout << endl;
	mout << "Midazolam\t\t Anksioznost \t\t 12\t\t 112";
	mout << endl;
	mout << "Trazodone\t\t Depresija \t 14\t\t 152";
	mout << endl;
	mout << "Phenytoin\t\t Epilepsija \t\t 7\t\t 250";
	mout << endl;
	mout << "Actos\t\t\t Diabetes \t\t  33\t\t 220";
	mout << endl;
	mout << "Disprin\t\t\t Glavobolja \t 50\t\t 20";
	mout << endl;
	mout << "Flagyl\t\t\t Bolovi \t 45\t\t 70";


	
}
void Medicine::display_file_medicine()
{

	ifstream min("MEDICINES.txt");
	string m, c, q,p;
	min >> m;
	min >> c;
	min >> q;
	min >> p;
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
	cout << "\t\t\t\t" << m << "\t\t" << c << "\t\t" << q << "\t" << p << endl;
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
	for (int i = 0; !min.eof(); i++)
	{
		min >> m;
		min >> c;
		min >> q;
		min >> p;
		cout << endl;
		int a = m.length();
		int a2 = c.length();
		if (a < 8)
		{
			if (a2 < 8)
			{

				cout << "\t\t\t\t" << m << "\t\t\t" << c << "\t\t" << q << "\t\t" << p;
			}
			else if (a2>7)
			{
				cout << "\t\t\t\t" << m << "\t\t\t" << c << "\t" << q << "\t\t" << p;
			}
		}
		else
		{
			if (a2 < 8)
			{
				cout << "\t\t\t\t" << m << "\t\t" << c << "\t\t" << q << "\t\t" << p;
			}
			else if (a2>7)
			{
				cout << "\t\t\t\t" << m << "\t\t" << c << "\t" << q << "\t\t" << p;
			}
		}
	}
	cout << endl << "\t\t\t" << "*************************************************************************" << endl;
}
Medicine::~Medicine()
{
}