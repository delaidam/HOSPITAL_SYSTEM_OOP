
#ifndef HOSPITAL_MANAGEMENT_OOP_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_OOP_HOSPITAL_H
#pragma once//s ovim nam ne trebaju dodaci za header fajlove #ifndef???

#include<string>
#include<iostream>
#include"Apoteka.h"
#include"Soba.h"
#include"Osoba.h"
using namespace std;

class Hospital
{
private:
    const string name;
    const string address;
    const string phone_num;
    int choose;
    Apoteka pharmacy;
    Soba room;
    Osoba *person;

public:

    Hospital();
    Hospital(Osoba &);
    void set_choose(int);
    friend istream& operator>>(istream&,Hospital&);
    friend ostream& operator<<(ostream&,Hospital&);
    void hospital_dis();
    void set_class_person();
    void set_class_person_gye();
    void set_class_person_cs();
    void set_class_Patient();
    void set_class_staff();
    ~Hospital();
};


#endif //HOSPITAL_MANAGEMENT_OOP_HOSPITAL_H
