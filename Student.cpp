#include "Student.h"

Student::Student() : id(0), course(0) {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const vector<string>& subjects,
    const string& faculty, int course, const string& group) {}

Student::~Student() {}

void Student::showInfo() {
    cout << "Інформація про студента:\n" << *this;
}

void Student::inputInfo() {
    cout << "Введіть ID студента: ";
    cin >> id;
    cout << "Введіть прізвище: ";
    cin >> lastName;
    cout << "Введіть ім'я: ";
    cin >> firstName;
    cout << "Введіть побатькові: ";
    cin >> middleName;
    cout << "Введіть дату народження: ";
    cin >> birthDate;
    cout << "Введіть телефон: ";
    cin >> phoneNumber;
    cout << "Введіть факультет: ";
    cin >> faculty;
    cout << "Введіть курс: ";
    cin >> course;
    cout << "Введіть групу: ";
    cin >> group;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "ID студента: " << student.id << "\n"
        << "Прізвище: " << student.lastName << "\n"
        << "Ім'я: " << student.firstName << "\n"
        << "Побатькові: " << student.middleName << "\n"
        << "Дата народження: " << student.birthDate << "\n"
        << "Телефон: " << student.phoneNumber << "\n"
        << "Факультет: " << student.faculty << "\n"
        << "Курс: " << student.course << "\n"
        << "Група: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {
    student.inputInfo();
    return in;
}
