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
    os << "�������: " << student.lastName << endl;
    os << "��'�: " << student.firstName << endl;
    os << "�� �������: " << student.middleName << endl;
    os << "���� ����������: " << student.birthDate << endl;
    os << "����� ��������: " << student.phoneNumber << endl;
    os << "���������: " << student.faculty << endl;
    os << "����: " << student.course << endl;
    os << "�����: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) { 
    cout << "������ ID ��������: ";
    in >> student.studentId;
    cout << "������ �������: ";
    in >> student.lastName;
    cout << "������ ��'�: ";
    in >> student.firstName;
    cout << "������ �� �������: ";
    in >> student.middleName;
    cout << "������ ���� ����������: ";
    in >> student.birthDate;
    cout << "������ ����� ��������: ";
    in >> student.phoneNumber;
    cout << "������ ���������: ";
    in >> student.faculty;
    cout << "������ ����: ";
    in >> student.course;
    cout << "������ �����: ";
    in >> student.group;
    return in;
}