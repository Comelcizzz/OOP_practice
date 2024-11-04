#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

using namespace std;

class Teacher : public Person {
private:
    string cycleCommission;
public:
    Teacher();
    Teacher(const string& lastName, const string& firstName,
            const string& middleName, const string& birthDate,
            const string& phoneNumber, const string& cycleCommission);
    ~Teacher();

    string toString() const;

    void showInfo() const override;
    void inputInfo() override;

    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getBirthDate() const { return birthDate; }
    string getPhoneNumber() const { return phoneNumber; }
    string getCycleCommission() const { return cycleCommission; }

};

#endif // TEACHER_H
