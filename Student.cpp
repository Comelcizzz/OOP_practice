#include "Student.h"

using namespace std;

Student::Student() : Teacher(), studentId(0), faculty(""), course(0), group("") {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects, const string& faculty,
    int course, const string& group)
    : Teacher(id, lastName, firstName, middleName, birthDate, phoneNumber,
        cycleCommission, subjects), studentId(id), faculty(faculty), course(course), group(group) {}

Student::~Student() {}

ostream& operator<<(ostream& os, const Student& student) {
    os << static_cast<const Teacher&>(student);
    os << "ID студента: " << student.studentId << endl;
    os << "‘акультет: " << student.faculty << endl;
    os << " урс: " << student.course << endl;
    os << "√рупа: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {

    in >> static_cast<Teacher&>(student);
    cout << "¬вед≥ть факультет: ";
    in >> student.faculty;
    cout << "¬вед≥ть курс: ";
    in >> student.course;
    cout << "¬вед≥ть групу: ";
    in >> student.group;

    return in;
}

