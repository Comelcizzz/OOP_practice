#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Teacher {
protected:
    int teacherId;
    string lastName;
    string firstName;
    string middleName;
    string birthDate;
    string phoneNumber;
    string cycleCommission;
    vector<string> subjects;

public:
    Teacher();
    Teacher(int id, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const string& cycleCommission,
        const vector<string>& subjects);
    ~Teacher();

    friend ostream& operator<<(ostream& os, const Teacher& teacher);
    friend istream& operator>>(istream& in, Teacher& teacher);
};

#endif // TEACHER_H