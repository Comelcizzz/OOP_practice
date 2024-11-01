#include "Student.h"

Student::Student() : Person(), course(0) {}

Student::Student(int id, const string& lastName, const string& firstName,
                 const string& middleName, const string& birthDate,
                 const string& phoneNumber, const string& faculty, int course, const string& group)
    : Person(id, lastName, firstName, middleName, birthDate, phoneNumber),
    faculty(faculty), course(course), group(group) {}

Student::~Student() {}

void Student::showInfo() const {
    cout << "Student Information:\n" << *this;
}

void Student::inputInfo() {
    Person::inputInfo();
    cout << "Enter Faculty: ";
    cin >> faculty;
    cout << "Enter Course: ";
    cin >> course;
    cout << "Enter Group: ";
    cin >> group;
}

string Student::toString() const {
    ostringstream oss;
    oss << "ID: " << id << "\n"
        << "Last Name: " << lastName << "\n"
        << "First Name: " << firstName << "\n"
        << "Middle Name: " << middleName << "\n"
        << "Birth Date: " << birthDate << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Faculty: " << faculty << "\n"
        << "Course: " << course << "\n"
        << "Group: " << group;

    return oss.str();
}
