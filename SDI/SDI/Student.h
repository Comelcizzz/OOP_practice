#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

using namespace std;

class Student : public Person {
public:
    Student();
    Student(int id, const string& lastName, const string& firstName,
            const string& middleName, const string& birthDate,
            const string& phoneNumber, const string& faculty, int course, const string& group);
    ~Student();

    void showInfo() const override;
    void inputInfo() override;
    string toString() const;

private:
    Student *student;
    string faculty;
    int course;
    string group;
};

#endif // STUDENT_H
