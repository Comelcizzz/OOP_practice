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
    cout << "���������� ��� ��������:\n" << *this;
    cout << "���������: " << faculty << "\n"
        << "����: " << course << "\n"
        << "�����: " << group << endl;
}

void Student::inputInfo() {
    cout << "������ ID ��������: ";
    cin >> studentId;
    cout << "������ ���������: ";
    cin >> faculty;
    cout << "������ ����: ";
    cin >> course;
    cout << "������ �����: ";
    cin >> group;
    cin >> static_cast<Teacher&>(*this); 
}

ostream& operator<<(ostream& os, const Student& student) {
    os << static_cast<const Teacher&>(student);
    os << "ID ��������: " << student.studentId << "\n"
        << "���������: " << student.faculty << "\n"
        << "����: " << student.course << "\n"
        << "�����: " << student.group << endl;
    return os;
}

istream& operator>>(istream& in, Student& student) {
    student.inputInfo();
    return in;
}
