#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Teacher.h"

using namespace std;

class Student : public Teacher {
private:
    int id;
    string faculty;
    int course;
    string group;

public:
    Student();  
    Student(int id, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const vector<string>& subjects,
        const string& faculty, int course, const string& group); 

    ~Student();  

    int getId() { return id; }

    void showInfo();
    void inputInfo();

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& in, Student& student);
};

#endif // STUDENT_H
