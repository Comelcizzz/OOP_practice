#include "Student.h"

Student::Student() : Person(), course(0) {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const vector<string>& subjects,
    const string& faculty, int course, const string& group)
    : Person(id, lastName, firstName, middleName, birthDate, phoneNumber),
    faculty(faculty), course(course), group(group) {}

Student::~Student() {}

void Student::showInfo() const {
    cout << "≤нформац≥€ про студента:\n" << *this;
}

void Student::inputInfo() {
    Person::inputInfo(); 
    cout << "¬вед≥ть факультет: ";
    cin >> faculty;
    cout << "¬вед≥ть курс: ";
    cin >> course;
    cout << "¬вед≥ть групу: ";
    cin >> group;
}

