//
// Created by Delaida Muminovic on 1/5/2024.
//

#ifndef HOSPITAL_MANAGEMENT_OOP_LOGIN_H
#define HOSPITAL_MANAGEMENT_OOP_LOGIN_H
#pragma once
#include<string>
using namespace std;


class Login
{
private:
    string name;
    Hospital *hos;
public:
    static double amount;
    Login();
    void disp();
    void set_hospital(Hospital&);
    void create_acc_disp();
    void sign_up();
    int sign_in();
    int forgot_password();
    int change_password();
    void sign_in_disp();

    void hospital_dis();
    int check_repeat_username(string);
    ~Login();
};


#endif //HOSPITAL_MANAGEMENT_OOP_LOGIN_H
