#ifndef HOSPITAL_MANAGEMENT_OOP_OSOBA_H
#define HOSPITAL_MANAGEMENT_OOP_OSOBA_H
#pragma once

#include <string>
#include <iostream>
using namespace std;

class Osoba
{
private:
    char* person_name;
    char* residence;
    int age;
    char gender;
    string person_phone;
public:
    Osoba();
    Osoba(char*,char*,int,char,string);
    void set_person_name(char*);
    void set_residence(char*);
    void set_age(int);
    void set_gender(char);
    void set_person_phone(string);
    char* get_person_name();
    char* get_residence();
    int get_age();
    char get_gender();
    virtual void display();
    string get_person_phone();
    ~Osoba();
};
#endif //HOSPITAL_MANAGEMENT_OOP_OSOBA_H
