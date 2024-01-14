#pragma once

#include <iostream>
#include<string>
#include "Person.h"
#include"Room.h"
using namespace std;

class Patient:public Person
{
private:
	
	string problem;
	string time_admit;
	string time_discharge;
	double fee_charged;
	int room_allot;
	Room *rooms;
public: 
	Patient();
	Patient(Room &,string, string, string,double, int, char*, char*, int, char, string);
	void set_room(Room&);
	void discharge_patient();
    void search_patient();
	void display();
	void update_patient_file(string, string, string, double, int, char*, char*, int, char, string);
	void display_all_patients();
	int find_length(char*);
	int compare(char*,char*,int);
	int check_file_size();
	void discharge_file_update(string*, string*, string*, string*, string*, string*, string*, string*, string*, string*,int, int);
	void display_rooms();
	~Patient();
};