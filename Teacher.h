#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Teacher {
protected:
    int id;
    string lastName;
    string firstName;
    string middleName; 
    string birthDate;
    string phoneNumber;
    string cycleCommission;
    vector<string> subjects;

public:
    Teacher();
    Teacher(const string& lastName, const string& firstName, const string& middleName,
        const string& birthDate, const string& phoneNumber, const string& cycleCommission,
        const vector<string>& subjects);

    int getId() const { return id; }

    virtual ~Teacher() = default;

    virtual void showInfo();
    void inputInfo();

    friend ostream& operator<<(ostream& os, const Teacher& teacher);
    friend istream& operator>>(istream& in, Teacher& teacher);
};

#endif // TEACHER_H
