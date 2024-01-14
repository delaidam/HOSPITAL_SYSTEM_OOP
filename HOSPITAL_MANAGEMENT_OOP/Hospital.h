#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Pharmacy.h"
#include"Room.h"
#include"Person.h"
using namespace std;

class Hospital
{
private:
    const string name;
    const string address;
    const string phone_num;
    int choose;
    Pharmacy pharmacy;
    Room room;
    Person *person;
    vector<Room> rooms;
public:

    Hospital();
    Hospital(Person &);
    void set_choose(int);
    friend istream& operator>>(istream& stream,Hospital& h);
    friend ostream& operator<<(ostream& stream,Hospital& h);
    void hospital_dis();
    void set_class_person();
    void set_class_person_gye();
    void set_class_Patient();
    void set_class_staff();
    vector<Room> &getRooms();
    void setRooms();
    ~Hospital();
};

