#include "Hospital.h"
#include <memory>
Hospital::Hospital()
{
    choose = 0;
}
Hospital::Hospital(Person &object): name("hospital"), address("Crkvice bb"), phone_num("123456789")
{
    this->person = &object;

}
void Hospital::hospital_dis()
{
    cout << "\t\t\t********************************************************************" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t* * ********************************************************** * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                    Izaberite zeljenu opciju:             * * *" << endl;
    cout << "\t\t\t* * *                                                          * * *" << endl;
    cout << "\t\t\t* * *                      1) Apoteka/Snacks                   * * *" << endl;
    cout << "\t\t\t* * *                      2) Doktori                          * * *" << endl;
    cout << "\t\t\t* * *                      3) Pacijenti                        * * *" << endl;
    cout << "\t\t\t* * *                      4) Osoblje                          * * *" << endl;
    cout << "\t\t\t* * *                      5) Dijagnoza-Lijekovi               * * *" << endl;
    cout << "\t\t\t* * *                      6) Komentari i ocjene               * * *" << endl;
    cout << "\t\t\t* ************************************************************** * *" << endl;
    cout << "\t\t\t********************************************************************" << endl;
}
void Hospital::set_choose(int c)
{
    choose = c;
}
istream& operator>>(istream& stream, Hospital& h)
{



    if (h.choose == 1)
    {
        cout << "Apoteka" << endl;
        stream >> h.pharmacy;
        return stream;
    }

    else if (h.choose == 5)
    {
        cout << "Hvala na posjeti!" << endl;
        return stream;
    }

}
ostream& operator<<(ostream& stream,Hospital& h)
{
    if (h.choose == 1)
    {

        stream << h.pharmacy;
        return stream;
    }
    else if (h.choose == 2)
    {

        stream << h.room;
        return stream;
    }


}
void Hospital::set_class_person()
{
    this->person->display();
}

void Hospital::set_class_person_gye()
{
    this->person->display();
}
void Hospital::set_class_Patient()
{
    this->person->display();
}
void Hospital::set_class_staff()
{
    this->person->display();
}


void Hospital::setRooms() {
    std::shared_ptr<Room> temp = std::make_shared<Room>();
    for (int i = 0; i < rooms.size(); i++) {
        temp->set_free_r(i);
        this->rooms.push_back(*temp);
    }
}

vector<Room> &Hospital::getRooms() {
    return this->rooms;
}

Hospital::~Hospital()
{
}
