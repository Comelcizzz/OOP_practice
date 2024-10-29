#ifndef STUDENT_H
#define STUDENT_H

#include "Teacher.h"

using namespace std;

class Student : public Teacher {
private:
    int studentId;
    string faculty;
    int course;
    string group;

public:
    Student();
    Student(int studentId, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const string& cycleCommission,
        const vector<string>& subjects, const string& faculty,
        int course, const string& group);
    ~Student();

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& in, Student& student);
};


#endif // STUDENT_H
