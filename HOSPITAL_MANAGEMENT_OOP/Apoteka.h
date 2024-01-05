//
// Created by Delaida Muminovic on 1/5/2024.
//

#ifndef HOSPITAL_MANAGEMENT_OOP_APOTEKA_H
#define HOSPITAL_MANAGEMENT_OOP_APOTEKA_H
#pragma once

//#include"Hrana.h"
//#include "Lijekovi.h"
#include <iostream>
class Apoteka
{
private:
   // Lijekovi lijek;
   // Hrana hrana;
    int choose;
    const int floor;
public:
    Apoteka();
   // Apoteka(Lijekovi&,Hrana&,const int);
    friend std::istream& operator>>(std::istream& stream,Apoteka& a);
    friend std::ostream& operator<<(std::ostream& stream,Apoteka& a);
    ~Apoteka();
};


#endif //HOSPITAL_MANAGEMENT_OOP_APOTEKA_H
