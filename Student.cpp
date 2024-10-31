#include "Student.h"

Student::Student() : id(0), course(0) {}

Student::Student(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const vector<string>& subjects,
    const string& faculty, int course, const string& group) {}

Student::~Student() {}

void Student::showInfo() {
    cout << "���������� ��� ��������:\n" << *this;
}

void Student::inputInfo() {
    cout << "������ ID ��������: ";
    cin >> id;
    cout << "������ �������: ";
    cin >> lastName;
    cout << "������ ��'�: ";
    cin >> firstName;
    cout << "������ ���������: ";
    cin >> middleName;
    cout << "������ ���� ����������: ";
    cin >> birthDate;
    cout << "������ �������: ";
    cin >> phoneNumber;
    cout << "������ ���������: ";
    cin >> faculty;
    cout << "������ ����: ";
    cin >> course;
    cout << "������ �����: ";
    cin >> group;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "ID ��������: " << student.id << "\n"
        << "�������: " << student.lastName << "\n"
        << "��'�: " << student.firstName << "\n"
        << "���������: " << student.middleName << "\n"
        << "���� ����������: " << student.birthDate << "\n"
        << "�������: " << student.phoneNumber << "\n"
        << "���������: " << student.faculty << "\n"
        << "����: " << student.course << "\n"
        << "�����: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {
    student.inputInfo();
    return in;
}
