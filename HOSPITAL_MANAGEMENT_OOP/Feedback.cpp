#include "Feedback.h"

Feedback::Feedback(const std::string& ime) : doctor_name(ime) {
    loadFeedbackFromFile();
}

Feedback::~Feedback() {
    saveFeedbackToFile();
}

void Feedback::giveFeedback()  {
    Mark mark;
    std::string comment;

    std::cout << "Unesite ocjenu (1-JAKO LOSE, 2-LOSE, 3-PROSJECNO, 4-VRLO DOBRO, 5-ODLICNO): ";
    int mark_entry;
    std::cin >> mark_entry;


    if (mark_entry < 1 || mark_entry > 5) {
        std::cout << "Nevazeci unos ocjene.\n";
        return;
    }

    mark = static_cast<Mark>(mark_entry);

    std::cout << "Unesite komentar: ";
    std::cin.ignore();
    std::getline(std::cin, comment);

    marks.push_back(mark);
    comments.push_back(comment);

    std::cout << "Ocjena i komentar su dodani.\n";
}

void Feedback::displayFeedback() {
    std::cout << "Ocjene i komentari za doktora " << doctor_name << ":\n";

    for (size_t i = 0; i < marks.size(); ++i) {
        std::string markText;

        // Pretvori ocjenu u tekstualnu reprezentaciju
        switch (marks[i]) {
            case Mark::JAKO_LOSE:
                markText = "JAKO LOSE";
                break;
            case Mark::LOSE:
                markText = "LOSE";
                break;
            case Mark::PROSJECNO:
                markText = "PROSJECNO";
                break;
            case Mark::VRLO_DOBRO:
                markText = "VRLO DOBRO";
                break;
            case Mark::ODLICNO:
                markText = "ODLICNO";
                break;
        }

        std::cout << "Ocjena: " << markText << ", Komentar: " << markText[i] << "\n";
    }
}

void Feedback::loadFeedbackFromFile() {
    std::ifstream file(doctor_name + ".txt");

    if (file.is_open()) {
        int mark1;
        std::string comment;

        while (file >> mark1 >> std::ws && std::getline(file, comment)) {
            marks.push_back(static_cast<Mark>(mark1));
            comments.push_back(comment);
        }

        file.close();
    }
}

void Feedback::saveFeedbackToFile() {
    std::ofstream file(doctor_name + ".txt");

    for (size_t i = 0; i < marks.size(); ++i) {
        file << static_cast<int>(marks[i]) << " " << comments[i] << "\n";
    }

    file.close();}