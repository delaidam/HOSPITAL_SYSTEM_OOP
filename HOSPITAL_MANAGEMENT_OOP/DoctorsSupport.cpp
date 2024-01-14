//
// Created by smajl on 10/01/2024.
//
#include "DoctorsSupport.h"
#include <iostream>

Medic::Medic(const std::string& i, const std::vector<std::string>& pd) : med_name(i), connectedDiagnosis(pd) {}

void Medic::recommendMed(const std::string& diagnosis)const{
    auto it = std::find(connectedDiagnosis.begin(), connectedDiagnosis.end(), diagnosis);

    if (it != connectedDiagnosis.end()) {
        std::cout << "- " << med_name << '\n';
    }
}
