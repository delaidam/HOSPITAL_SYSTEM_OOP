
#ifndef HOSPITAL_MANAGEMENT_OOP_SOBA_H
#define HOSPITAL_MANAGEMENT_OOP_SOBA_H
#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Soba
{
private:
    int **room_arr;
    const int total_rooms;
    int free_r;
    string room_type;
public:
    Soba();
    friend istream& operator>>(istream& stream,Soba& s);
    friend ostream& operator<<(ostream& stream,Soba& s);
    void display_rooms();
    void set_free_r(int );
    void free_room();
    int checK_room_avail(int);
    ~Soba();
};


#endif //HOSPITAL_MANAGEMENT_OOP_SOBA_H
