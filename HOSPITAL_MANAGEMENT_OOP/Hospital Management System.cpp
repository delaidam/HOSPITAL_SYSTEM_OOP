#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"Account.h"
#include"Hospital.h"
#include"Person.h"
#include"Surgeon.h"
#include"Gynecologist.h"
#include"Child_Specialist.h"
#include"Patient.h"
#include"Worker.h"
#include"Staff.h"
#include"Receptionist.h"
#include "DoctorsSupport.h"
#include <sstream>
#include "Feedback.h"
#include <algorithm>
#include <iomanip>

using namespace std;



void create_doctor_surgeon_file()
{
    ofstream docout("Doctors.txt");

    docout << "Afan Ceco  ";
    docout << "Odmut ";
    docout << "43  ";
    docout << "M  ";
    docout << "061-089-879  ";
    docout << "11:22-12:00  ";
    docout << "7 ";
    docout << "2500 ";
    docout << "Psihijatar  ";
    docout << endl;

    docout << "Sanid Muhic  ";
    docout << "Travnicka  ";
    docout << "43  ";
    docout << "F  ";
    docout << "062-410-410  ";
    docout << "1:22-5:00  ";
    docout << "9 ";
    docout << "5000  ";
    docout << "Neurohirurg ";
    docout << endl;

    docout << "Amila Suljic  ";
    docout << "Jalija  ";
    docout << "28  ";
    docout << "F  ";
    docout << "063-048-275  ";
    docout << "9:00-3:00  ";
    docout << "5 ";
    docout << "3500  ";
    docout << "Dermatolog ";
    docout << endl;

    docout << "Emina Spahic  ";
    docout << "Crkvice  ";
    docout << "35  ";
    docout << "F  ";
    docout << "061-352-876  ";
    docout << "8:00-5:00  ";
    docout << "10 ";
    docout << "5500  ";
    docout << "Kardiolog ";
    docout << endl;

    docout << "Nadja Basic  ";
    docout << "Radakovo  ";
    docout << "27  ";
    docout << "F  ";
    docout << "062-225-883  ";
    docout << "12:00-7:00  ";
    docout << "11 ";
    docout << "2800  ";
    docout << "Patolog ";
    docout << endl;
}
void create_staff_file()
{
    ofstream pout("Staff.txt");

    pout << "Amar Hadzic" << endl;
    pout << "Odmut"<<endl;
    pout << "43"<<endl;
    pout << "M"<<endl;
    pout << "061576487" << endl;
    pout << "11:00-1:00"<<endl;
    pout << "500"<<endl;
    pout << "Vozac"<<endl;


    pout << "Lejla Buro" << endl;
    pout << "Jalija" << endl;
    pout << "33" << endl;
    pout << "F" << endl;
    pout << "062785098" << endl;
    pout << "2:00=5:00" << endl;
    pout << "800" << endl;
    pout << "Vozacica" << endl;

    pout << "Edina Zec" << std::endl;
    pout << "Bilmisce" << std::endl;
    pout << "50" << std::endl;
    pout << "F" << std::endl;
    pout << "065432109" << std::endl;
    pout << "8:00-4:00" << std::endl;
    pout << "1000" << std::endl;
    pout << "Spremacica" << std::endl;

    pout << "Adnan Music" << std::endl;
    pout << "Radakovo" << std::endl;
    pout << "58" << std::endl;
    pout << "M" << std::endl;
    pout << "063987654" << std::endl;
    pout << "9:00-5:00" << std::endl;
    pout << "1200" << std::endl;
    pout << "Portir" << std::endl;
}

void update_doctor_file(char *type, string time /*(string)*/, int cab, double f/*fees (double)*/, char* name, char* res, int ag/*age (int)*/, char g, string con /*(string)*/)
{
    ofstream docout("Doctors.txt",ios::app);

    docout << name<<"  "  ;
    docout << res<<"  ";
    docout << ag<<"  ";
    docout << g<<"  ";
    docout << con<<"  ";
    docout << time<<"  ";
    docout << cab<<"  ";
    docout << f<<"  ";
    docout << type<<"  ";
    docout << endl;

    docout.close();

}
void display_all_doctors()
{
    ifstream docin("Doctors.txt");

    cout << left << setw(20) << "Ime" << setw(10) << "Adresa" << setw(6) << "God." << setw(6) << "Spol"
         << setw(15) << "Tel." << setw(10) << "Vrijeme" << setw(12) << "Ordinacija" << setw(8) << "  Plata" << setw(10) << "  Spec." << endl;
    cout << "************************************************************************************" << endl;

    char data[200];
    while (docin.getline(data, 200))
    {
        istringstream iss(data);
        string ime, adresa, godine, spol, tel, vrijeme, ordinacija, plata, spec;

        iss >> ime;
        if (iss.peek() != '\n')
        {
            string druga_rijec;
            iss >> druga_rijec;
            ime = ime + " " + druga_rijec;
        }

        iss >> adresa >> godine >> spol >> tel >> vrijeme >> ordinacija >> plata >> spec;

        cout << left << setw(20) << ime << setw(10) << adresa << setw(6) << godine << setw(6) << spol
             << setw(15) << tel << setw(10) << vrijeme << setw(14) <<"   "+ ordinacija << setw(8) << plata << setw(10) << spec << endl;
        cout << "************************************************************************************" << endl;
    }
}



void create_Patient()
{
    ofstream pout("Patients.txt");

    pout << "Amina Kovac" << endl;
    pout << "Jalija 3"<<endl;
    pout << "43"<<endl;
    pout << "F"<<endl;
    pout << "063-576-096" << endl;
    pout << "Gripa"<<endl;
    pout << "12:00"<<endl;
    pout << "2:00"<<endl;
    pout <<  "1200"<<endl;
    pout << "1"<<endl;

    pout << "Adnan Hodzic" << endl;
    pout << "Dzemalabb" << endl;
    pout << "33" << endl;
    pout << "M" << endl;
    pout << "061-066-991" << endl;
    pout << "Flu" << endl;
    pout << "8:00" << endl;
    pout << "1:00" << endl;
    pout << "1600" << endl;
    pout << "2" << endl;

    pout << "Emina Karic" << std::endl;
    pout << "Tuzla" << std::endl;
    pout << "55" << std::endl;
    pout << "F" << std::endl;
    pout << "063-111-222" << std::endl;
    pout << "Aritmije" << std::endl;
    pout << "9:15" << std::endl;
    pout << "14:30" << std::endl;
    pout << "2500" << std::endl;
    pout << "3" << std::endl;

    pout << "Haris Civic" << std::endl;
    pout << "Sarajevo" << std::endl;
    pout << "40" << std::endl;
    pout << "M" << std::endl;
    pout << "066-333-444" << std::endl;
    pout << "Alergija" << std::endl;
    pout << "11:45" << std::endl;
    pout << "16:00" << std::endl;
    pout << "1800" << std::endl;
    pout << "4" << std::endl;

    pout << "Selma Dizdar" << std::endl;
    pout << "Zenica" << std::endl;
    pout << "35" << std::endl;
    pout << "F" << std::endl;
    pout << "061-555-666" << std::endl;
    pout << "Migrena" << std::endl;
    pout << "13:30" << std::endl;
    pout << "18:45" << std::endl;
    pout << "1200" << std::endl;
    pout << "5" << std::endl;

}

int main() {


    Account Acc;
    Acc.display();

    create_doctor_surgeon_file();
    create_Patient();
    create_staff_file();


    int log = 0;

    while (log == 0) {
        cout << endl << "\t\t\t\t\t    1)REGISTRACIJA          2)PRIJAVA" << endl;
        int choice;

        do {
            cout << "Unesi izbor: " << endl;
            cin >> choice;
            if (choice < 0 || choice > 2 || !cin) {
                cout << "Pogresan izbor!" << endl;
                cin.clear();
                cin.ignore();
            }
        } while (choice < 0 || choice > 2 || !cin);


        system("pause");
        system("cls");
        if (choice == 1) {
            Acc.sign_up();
            Acc.display();
        } else if (choice == 2) {
            Acc.sign_in_display();
            log = Acc.sign_in();
        }

    }

    Person per;
    Room room;
    Hospital hospital(per);
    hospital.setRooms(); // Postavljanje soba u bolnici
    vector<Room> &hospitalRooms = hospital.getRooms(); // Dobijanje pristupa sobama
    Snacks snacks;
    Medicine medicine;
    medicine.create_file_medicine();
    snacks.create_snack_file();

    Acc.setHospital(hospital);
    Acc.hospital_display();

    int choose = 0;
    cout << endl;

    while (choose != 7) {
        cout << "Unos: ";
        cin >> choose;

        if (choose <= 0 || choose > 6 || !cin) {
            cout << "Pogresan unos!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        for (int i = 0; choose != 7; i++) {
            if (choose == 1) {

                hospital.set_choose(choose);
                cin >> hospital;
                cout << hospital;
                system("pause");
                system("cls");
            } else if (choose == 2) {
                system("pause");
                system("cls");
                cout << "\t\t\t\t\t**********************" << endl;
                cout << "\t\t\t\t\t1) Dodaj doktora" << endl;
                cout << "\t\t\t\t\t2) Popis doktora " << endl;
                cout << "\t\t\t\t\t**********************" << endl;
                int ch = 0;
                cin >> ch;
                if (ch == 1) {
                    cout << "\t\t\t\t\t*******************" << endl;
                    cout << "\t\t\t\t\t Tip doktora:" << endl;
                    cout << "\t\t\t\t\t1) Hirurg" << endl;
                    cout << "\t\t\t\t\t2) Ginekolog" << endl;
                    cout << "\t\t\t\t\t3) Pedijatar" << endl;
                    cout << "\t\t\t\t\t*******************" << endl;
                    int ch2 = 0;
                    cin >> ch2;
                    if (ch2 == 1) {

                        system("pause");
                        system("cls");
                        char *type = new char[30];
                        cout << endl;
                        cout << "Unesite tip hirurga: ";
                        cin.ignore();
                        cin.getline(type, 30);

                        cout << "Radno vrijeme (0:00-0:00): " << endl;
                        string time;
                        getline(cin, time);
                        int cab;
                        do {
                            cout << "Unesite broj ordinacije: " << endl;
                            cin >> cab;

                            if (!cin) {
                                cout << "Invalid Entry" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);



                        cout << "Unesite naknadu po pacijentu: " << endl;
                        double f;
                        do {
                            cin >> f;
                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);



                        cin.ignore();
                        char *name = new char[30];
                        cout << "Unesite ime i prezime: " << endl;
                        cin.getline(name, 30);

                        char *res = new char[30];
                        cout << "Unesite prebivaliste: " << endl;
                        cin.getline(res, 30);

                        cout << "Unesite godine: " << endl;
                        int ag;
                        do {
                            cin >> ag;
                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);



                        cout << "Unesite spol (M/F): " << endl;
                        char g;
                        cin >> g;

                        cout << "Unesite kontakt tel.: " << endl;
                        string con;
                        cin >> con;

                        update_doctor_file(type, time, cab, f, name, res, ag, g, con);
                        Surgeon surgeon(type, time, cab, f, name, res, ag, g, con);

                        Hospital h(surgeon);

                        h.set_class_person();

                    } else if (ch2 == 2) {
                        system("pause");
                        system("cls");

                        char *type = new char[30];
                        cout << endl;
                        cout << "Unesite specijalizaciju: ";
                        cin.ignore();
                        cin.getline(type, 30);

                        cout << "Radno vrijeme (0:00-0:00): " << endl;
                        string time;
                        getline(cin, time);

                        cout << "Unesite broj ordinacije: " << endl;
                        int cab;
                        do {
                            cin >> cab;
                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);


                        cout << "Unesite naknadu po pacijentu: " << endl;
                        double f;
                        do {
                            cin >> f;
                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);


                        cin.ignore();
                        char *name = new char[30];
                        cout << "Unesite ime i prezime: " << endl;
                        cin.getline(name, 30);

                        char *res = new char[30];
                        cout << "Unesite prebivaliste: " << endl;
                        cin.getline(res, 30);

                        cout << "Unesite godine: " << endl;
                        int ag;
                        do {
                            cin >> ag;
                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);


                        cout << "Unesite spol (M/F): " << endl;
                        char g;
                        cin >> g;

                        cout << "Unesite kontakt tel.: " << endl;
                        string con;
                        cin >> con;

                        update_doctor_file(type, time, cab, f, name, res, ag, g, con);
                        Gynecologist gye(type, time, cab, f, name, res, ag, g, con);
                        Hospital h(gye);
                        h.set_class_person_gye();


                    } else if (ch2 == 3) {
                        system("pause");
                        system("cls");


                        char *type = new char[30];
                        cout << endl;
                        cout << "Unesite tip pedijatra: ";
                        cin.ignore();
                        cin.getline(type, 30);

                        cout << "Radno vrijeme (0:00-0:00): " << endl;
                        string time;
                        getline(cin, time);

                        cout << "Broj ordinacije: " << endl;
                        int cab;
                        do {
                            cin >> cab;
                            if (!cin) {
                                cout << "Pogresan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);


                        cout << "Unesite naknadu po pacijentu: " << endl;
                        double f;
                        do {
                            cin >> f;
                            if (!cin) {
                                cout << "Pogresan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);



                        cin.ignore();
                        char *name = new char[30];
                        cout << "Unesite ime i prezime: " << endl;
                        cin.getline(name, 30);

                        char *res = new char[30];
                        cout << "Unesite prebivaliste: " << endl;
                        cin.getline(res, 30);

                        cout << "Unesite godine: " << endl;
                        int ag;
                        do {
                            cin >> ag;
                            if (!cin) {
                                cout << "Pogresan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        } while (!cin);


                        cout << "Unesite spol (M/F): " << endl;
                        char g;
                        cin >> g;

                        cout << "Unesite kontakt tel. " << endl;
                        string con;
                        cin >> con;

                        update_doctor_file(type, time, cab, f, name, res, ag, g, con);
                        Child_Specialist CS(type, time, cab, f, name, res, ag, g, con);
                        Hospital h(CS);
                        h.set_class_person_gye();

                    }

                } else if (ch == 2) {
                    display_all_doctors();
                }

                system("pause");
                system("cls");
            } else if (choose == 3) {

                system("pause");
                system("cls");
                cout << "1) Dodaj pacijenta" << endl << "2) Pregled pacijenata" << endl << "3) Trazenje  pacijenta "
                     << endl << "4) Pregled soba" << endl << "5) Otpustanje pacijenata" << endl;
                int ch = 0;
                cin >> ch;
                if (ch == 1) {

                    cout << "Unesite dijagnozu: " << endl;
                    string dis;
                    cin >> dis;
                    cout << "Unesite vrijeme prijema" << endl;
                    string ta;
                    cin >> ta;
                    cout << "Unesite vrijeme otpusta: " << endl;
                    string td;
                    cin >> td;
                    cout << "Cijena pregleda: " << endl;
                    double charge;
                    do {
                        cin >> charge;
                        if (!cin) {
                            cout << "Pogresan unos!" << endl;
                            cin.clear();
                            cin.ignore();
                        }
                    } while (!cin);

                    Acc.amount = Acc.amount + charge;


                    int check = 0;
                    int r;
                    do {
                        cout << "Unesite broj sobe za smjestaj pacijenta: " << endl;
                        cin >> r;


                        if (!cin) {
                            cout << "Pogresan unos!" << endl;
                            cin.clear();
                            cin.ignore();
                            continue;
                        }

                        check = room.checK_room_avail(r);

                        if (check == 0) {
                            cout << "Soba vec zauzeta, pokusajte ponovo!" << endl;
                        }

                    } while (check == 0 || !cin);

                    cin.ignore();
                    char *name = new char[30];
                    cout << "Unesite ime i prezime: " << endl;
                    cin.getline(name, 30);

                    char *res = new char[30];
                    cout << "Unesite prebivaliste: " << endl;
                    cin.getline(res, 30);

                    cout << "Unesite godine: " << endl;
                    int ag;

                    do {
                        cin >> ag;

                        if (!cin) {
                            cout << "Pogresan unos" << endl;
                            cin.clear();
                            cin.ignore();
                            cout << "Unesite godine: " << endl;
                        }

                    } while (!cin);


                    cout << "Unesite spol (M/F): " << endl;
                    char g;
                    cin >> g;

                    cout << "Unesite kontakt tel.: " << endl;
                    string con;
                    cin >> con;


                    Patient patient(room, dis, ta, td, charge, r, name, res, ag, g, con);
                    patient.update_patient_file(dis, ta, td, charge, r, name, res, ag, g, con);
                    Hospital h(patient);
                    h.set_class_Patient();


                } else if (ch == 2) {
                    Patient p_dis;

                    p_dis.display_all_patients();
                } else if (ch == 3) {
                    Patient p_search;
                    p_search.search_patient();
                }
                Patient p;
                p.set_room(room);
                if (ch == 4) {
                    p.display_rooms();
                } else if (ch == 5) {
                    p.discharge_patient();
                }

                system("pause");
                system("cls");
            } else if (choose == 4) {
                cout << "\t\t\t\t\t************************" << endl;
                cout << "\t\t\t\t\t1) Dodaj osoblje" << endl;
                cout << "\t\t\t\t\t2) Prikazi osoblje" << endl;
                cout << "\t\t\t\t\t************************" << endl;
                int choice;
                cout << "Enter: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "\t\t\t\t\t************************" << endl;
                    cout << "\t\t\t\t\t1) Dodaj uposlenika" << endl;
                    cout << "\t\t\t\t\t2) Dodaj portira" << endl;
                    cout << "\t\t\t\t\t************************" << endl;
                    cout << "Enter: ";
                    int c;
                    cin >> c;
                    if (c == 1) {
                        //cin.ignore();
                        cout << "Radno vrijeme (hh:mm-hh:mm): " << endl;
                        string time;
                        cin >> time;
                        cout << "Unesite platu: " << endl;
                        double p;

                        do {
                            cin >> p;

                            if (!cin) {
                                cout << "Pogrešan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                                cout << "Unesite platu: " << endl;
                            }

                        } while (!cin);


                        cin.ignore();
                        cout << "Unesite poziciju: " << endl;
                        string work;
                        getline(cin, work);
                        //cin.ignore();
                        char *name = new char[30];
                        cout << "Unesite ime i prezime: " << endl;
                        cin.getline(name, 30);

                        char *res = new char[30];
                        cout << "Unesite prebivaliste: " << endl;
                        cin.getline(res, 30);

                        cout << "Unesite godine: " << endl;
                        int ag;

                        do {
                            cin >> ag;

                            if (!cin) {
                                cout << "Pogrešan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                                cout << "Unesite godine: " << endl;
                            }

                        } while (!cin);


                        cout << "Unesite spol (M/F): " << endl;
                        char g;
                        cin >> g;

                        cout << "Unesite kontakt tel.: " << endl;
                        string con;
                        cin >> con;

                        Worker worker(work, time, p, name, res, ag, g, con);
                        Hospital h(worker);
                        h.set_class_staff();
                        worker.update_Worker(work, time, p, name, res, ag, g, con);

                        system("pause");
                        system("cls");
                    } else if (c == 2) {
                        //cin.ignore();
                        cout << "Unesite radno vrijeme (hh:mm-hh:mm): " << endl;
                        string time;
                        cin >> time;
                        cout << "Unesite platu: " << endl;
                        double p;

                        do {
                            cin >> p;

                            if (!cin) {
                                cout << "Pogrešan unos!" << endl;
                                cin.clear();
                                cin.ignore();
                                cout << "Unesite platu: " << endl;
                            }

                        } while (!cin);

                        cin.ignore();
                        cout << "Unesite struku: " << endl;
                        string ed;
                        getline(cin, ed);

                        char *name = new char[30];
                        cout << "Unesite ime: " << endl;
                        cin.getline(name, 30);

                        char *res = new char[30];
                        cout << "Unesite prebivaliste: " << endl;
                        cin.getline(res, 30);

                        cout << "Unesite godine: " << endl;
                        int ag;

                        do {
                            cin >> ag;

                            if (!cin) {
                                cout << "Pogresan unos" << endl;
                                cin.clear();
                                cin.ignore();
                                cout << "Unesite godine: " << endl;
                            }

                        } while (!cin);


                        cout << "Unesite spol (M/F): " << endl;
                        char g;
                        cin >> g;

                        cout << "Unesite broj tel.: " << endl;
                        string con;
                        cin >> con;

                        Receptionist recep(ed, time, p, name, res, ag, g, con);
                        Hospital h(recep);
                        h.set_class_staff();
                        recep.update_recep_file(ed, time, p, name, res, ag, g, con);

                        system("pause");
                        system("cls");
                    }

                } else if (choice == 2) {
                    Staff s;
                    s.display_all_staff();
                }
                system("pause");
                system("cls");


            } else if (choose == 5) {
                std::ifstream file("lijekovi.txt");
                if (!file.is_open()) {
                    std::cerr << "Nije moguće otvoriti datoteku.\n";
                    return 1;
                }

                std::vector<Medic>medbase;
                std::string line;

                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    std::string med_name;
                    std::vector<std::string> diagnosis;
                    std::string diagnosiss;

                    iss >> med_name;
                    while (iss >> diagnosiss) {

                        std::replace(diagnosiss.begin(), diagnosiss.end(), '_', ' ');
                        diagnosis.push_back(diagnosiss);
                    }

                    medbase.emplace_back(med_name, diagnosis);
                }


                std::string choice1;
                std::cout << "Unesi dijagnozu: ";
                std::cin.ignore();  // Ignoriraj preostali znak novog reda nakon prethodnog unosa
                std::getline(std::cin, choice1);

                bool writtenmeds = false;

                for (const auto &lijek: medbase) {
                    lijek.recommendMed(choice1);
                    writtenmeds = true;
                }

                if (!writtenmeds) {
                    std::cout << "Nema preporučenih lijekova za unesenu dijagnozu.\n";
                }
            } else if (choose == 6) {
                std::string doctorName;
                std::cout << "Unesite ime doktora: ";
                std::cin >> doctorName;

                Feedback doctor(doctorName);

                char choice;
                do {
                    std::cout << "1. Unesi ocenu i komentar\n";
                    std::cout << "2. Ispisi ocene i komentare\n";
                    std::cout << "3. Izlaz\n";
                    std::cout << "Izaberite opciju: ";
                    std::cin >> choice;

                    switch (choice) {
                        case '1':
                            doctor.giveFeedback();
                            break;
                        case '2':
                            doctor.displayFeedback();
                            break;
                        case '3':
                            std::cout << "Izlaz iz programa.\n";
                            break;
                        default:
                            std::cout << "Nepoznata opcija.\n";
                    }
                } while (choice != '3');

            }


            Acc.hospital_display();
            cout << endl;
            cout << "Unos: ";
            cin >> choose;
        }
    }
}