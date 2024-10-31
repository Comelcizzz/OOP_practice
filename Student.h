#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    string faculty;
    int course;
    string group;

public:
    Student();
    Student(int id, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber, const vector<string>& subjects,
        const string& faculty, int course, const string& group);

    virtual ~Student();

    void showInfo() const override; 
    void inputInfo() override;       
};

#endif // STUDENT_H
