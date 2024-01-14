#pragma once
#include<string>
#include"Hospital.h"
using namespace std;


class Account
{
private:
	string name;
	Hospital *hos;
public:
	static double amount;
	Account();
	void display();
	void setHospital(Hospital&);
	void create_acc_display();
	void sign_up();
	int sign_in();
	int forgot_password();
	int change_password();
	void sign_in_display();

	void hospital_display();
	int check_repeat_username(string);
	~Account();
};

