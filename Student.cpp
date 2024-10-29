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
    os << "ID ��������: " << student.studentId << endl;
    os << "���������: " << student.faculty << endl;
    os << "����: " << student.course << endl;
    os << "�����: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {

    in >> static_cast<Teacher&>(student);
    cout << "������ ���������: ";
    in >> student.faculty;
    cout << "������ ����: ";
    in >> student.course;
    cout << "������ �����: ";
    in >> student.group;

    return in;
}

