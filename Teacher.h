#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    string cycleCommission;
    vector<string> subjects;

public:
    Teacher();
    Teacher(const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const string& cycleCommission,
        const vector<string>& subjects);

    void showInfo() const override;
    void inputInfo() override;      
};

#endif // TEACHER_