//
// Created by smajl on 10/01/2024.
//

#ifndef NOVIAKOBOGDAPOSLJEDNJI_FEEDBACK_H
#define NOVIAKOBOGDAPOSLJEDNJI_FEEDBACK_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum Mark {
    JAKO_LOSE = 1,
    LOSE,
    PROSJECNO,
    VRLO_DOBRO,
    ODLICNO
};

class Feedback {
public:
    Feedback(const std::string& ime);
    ~Feedback();

    void giveFeedback();
    void displayFeedback();

private:
    std::string doctor_name;
    std::vector<Mark> marks;
    std::vector<std::string> comments;

    void loadFeedbackFromFile();
    void saveFeedbackToFile();
};

#endif //NOVIAKOBOGDAPOSLJEDNJI_FEEDBACK_H
