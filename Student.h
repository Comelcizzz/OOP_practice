#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    int studentId;
    string lastName;
    string firstName;
    string middleName;     
    string birthDate;
    string phoneNumber;
    string faculty;
    int course;
    string group;

public:
    Student();

    Student(int id, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const string& faculty,
        int course, const string& group);

    Student(const Student& other);

    ~Student();

    friend ostream& operator<<(ostream& os, Student const& student);
    friend istream& operator>>(istream& in, Student& student);
};

#endif // STUDENT_H