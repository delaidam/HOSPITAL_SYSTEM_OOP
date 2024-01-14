#include "Pharmacy.h"
#include <iomanip>
Pharmacy::Pharmacy():floor(2)
{
	choose = 0;
}
Pharmacy::Pharmacy(Medicine &m,Snacks &s,const int f):floor(f)
{
	medicine=m;
	snacks=s;
}
istream& operator>>(istream& stream, Pharmacy& p)
{
    while (true)
    {
        cout << endl << "\t\t\t\t\t_______________________________" << endl;
        cout << "\t\t\t\t\t\t   Opcija?" << endl;
        cout << "\t\t\t\t\t   1. Snacks" << endl;
        cout << "\t\t\t\t\t   2. Lijekovi" << endl;
        cout << "\t\t\t\t\t   3. Napusti!" << endl;
        cout << "\t\t\t\t\t_______________________________" << endl;

        cin >> p.choose;

        if (p.choose >= 1 && p.choose <= 3 && cin)
        {
            if (p.choose == 1)
            {
                system("pause");
                system("cls");
                stream >> p.snacks;
                break;
            }
            else if (p.choose == 2)
            {
                system("pause");
                system("cls");
                stream >> p.medicine;
                break;
            }
            else
            {
                // opcija 3 - napusti
                break;
            }
        }
        else
        {
            cout << endl << "Pogresan unos!" << endl;
            cin.clear();
            cin.ignore();
        }
    }

    return stream;
}

ostream& operator<<(ostream& stream,Pharmacy& p)
{
	if (p.choose == 1)
	{

		stream << p.snacks;
		return stream;
	}
	else if (p.choose == 2)
	{

		stream << p.medicine;
		return stream;
	}
	
}
Pharmacy::~Pharmacy()
{
}