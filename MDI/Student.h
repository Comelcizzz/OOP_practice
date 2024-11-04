#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

using namespace std;

class Student : public Person {
private:
    Student *student;
    string faculty;
    int course;
    string group;

public:
    Student();
    Student(const string& lastName, const string& firstName,
            const string& middleName, const string& birthDate,
            const string& phoneNumber, const string& faculty, int course, const string& group);
    ~Student();

    string toString() const;

    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getBirthDate() const { return birthDate; }
    string getPhoneNumber() const { return phoneNumber; }
    string getFaculty() const { return faculty; }
    int getCourse() const { return course; }
    string getGroup() const { return group; }

    void showInfo() const override;
    void inputInfo() override;

};

#endif // STUDENT_H
