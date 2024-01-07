#ifndef HOSPITAL_MANAGEMENT_OOP_OSOBLJE_H
#define HOSPITAL_MANAGEMENT_OOP_OSOBLJE_H
#pragma once

#include <iostream>
#include<string>
#include "Osoba.h"
using namespace std;

class Osoblje:public Osoba
{
private:
    string time;
    double pay;
    string position;
public:
    Osoblje();
    Osoblje(string,double,char*,char*,int,char,string);
    void set_time(string);
    void set_pay(double);
    void set_position(string);
    string get_position();
    string get_time();
    double get_pay();
    void hire();
    void display_all_staff();
    virtual void display();

    ~Osoblje();
};
#endif //HOSPITAL_MANAGEMENT_OOP_OSOBLJE_H
