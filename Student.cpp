#include "Student.h"

Student::Student() : studentId(0), course(0) {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects, const string& faculty,
    int course, const string& group)
    : Teacher(lastName, firstName, middleName, birthDate, phoneNumber, cycleCommission, subjects),
    studentId(id), faculty(faculty), course(course), group(group) {}

Student::~Student() {}

void Student::showInfo() {
    cout << "≤нформац≥€ про студента:\n" << *this;
    cout << "‘акультет: " << faculty << "\n"
        << " урс: " << course << "\n"
        << "√рупа: " << group << endl;
}

void Student::inputInfo() {
    cout << "¬вед≥ть ID студента: ";
    cin >> studentId;
    cout << "¬вед≥ть факультет: ";
    cin >> faculty;
    cout << "¬вед≥ть курс: ";
    cin >> course;
    cout << "¬вед≥ть групу: ";
    cin >> group;
    cin >> static_cast<Teacher&>(*this); 
}

ostream& operator<<(ostream& os, const Student& student) {
    os << static_cast<const Teacher&>(student);
    os << "ID студента: " << student.studentId << "\n"
        << "‘акультет: " << student.faculty << "\n"
        << " урс: " << student.course << "\n"
        << "√рупа: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {
    student.inputInfo();
    return in;
}
