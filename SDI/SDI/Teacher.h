#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

using namespace std;

class Teacher : public Person {
public:
    Teacher();
    Teacher(const string& lastName, const string& firstName,
            const string& middleName, const string& birthDate,
            const string& phoneNumber, const string& cycleCommission);
    ~Teacher();

    void showInfo() const override;
    void inputInfo() override;

private:
    string cycleCommission;
};

#endif // TEACHER_H
