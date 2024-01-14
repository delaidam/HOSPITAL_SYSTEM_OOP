//
// Created by smajl on 10/01/2024.
//

#ifndef NOVIAKOBOGDAPOSLJEDNJI_DOCTORSSUPPORT_H
#define NOVIAKOBOGDAPOSLJEDNJI_DOCTORSSUPPORT_H
#include <string>
#include <vector>
#include <algorithm>

// Klasa koja predstavlja lijek
class Medic {
public:
    std::string med_name;
    std::vector<std::string> connectedDiagnosis;

    Medic(const std::string& i, const std::vector<std::string>& pd);

    void recommendMed(const std::string& diagnosis)const;
};
#endif
