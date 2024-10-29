#include "Student.h"

Student::Student() : studentId(0), lastName(""), firstName(""),
middleName(""), birthDate(""),
phoneNumber(""), faculty(""),
course(0), group("") {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& faculty,
    int course, const string& group)
    : studentId(id), lastName(lastName), firstName(firstName),
    middleName(middleName), birthDate(birthDate),
    phoneNumber(phoneNumber), faculty(faculty),
    course(course), group(group) {}

Student::Student(const Student& other)
    : studentId(other.studentId), lastName(other.lastName),
    firstName(other.firstName), middleName(other.middleName),
    birthDate(other.birthDate), phoneNumber(other.phoneNumber),
    faculty(other.faculty), course(other.course), group(other.group) {}

Student::~Student() {}

ostream& operator<<(ostream& os, const Student& student) {
    os << "ID: " << student.studentId << endl;
    os << "Прізвище: " << student.lastName << endl;
    os << "Ім'я: " << student.firstName << endl;
    os << "По батькові: " << student.middleName << endl;
    os << "Дата народження: " << student.birthDate << endl;
    os << "Номер телефону: " << student.phoneNumber << endl;
    os << "Факультет: " << student.faculty << endl;
    os << "Курс: " << student.course << endl;
    os << "Група: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) { 
    cout << "Введіть ID студента: ";
    in >> student.studentId;
    cout << "Введіть прізвище: ";
    in >> student.lastName;
    cout << "Введіть ім'я: ";
    in >> student.firstName;
    cout << "Введіть по батькові: ";
    in >> student.middleName;
    cout << "Введіть дату народження: ";
    in >> student.birthDate;
    cout << "Введіть номер телефону: ";
    in >> student.phoneNumber;
    cout << "Введіть факультет: ";
    in >> student.faculty;
    cout << "Введіть курс: ";
    in >> student.course;
    cout << "Введіть групу: ";
    in >> student.group;
    return in;
}

bool operator==(const Student& obj1, const Student& obj2) {
        return obj1.studentId == obj2.studentId &&
            obj1.lastName == obj2.lastName &&
            obj1.firstName == obj2.firstName &&
            obj1.middleName == obj2.middleName &&
            obj1.birthDate == obj2.birthDate &&
            obj1.phoneNumber == obj2.phoneNumber &&
            obj1.faculty == obj2.faculty &&
            obj1.course == obj2.course &&
            obj1.group == obj2.group;
}
