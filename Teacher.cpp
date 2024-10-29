#include "Teacher.h"

using namespace std;

Teacher::Teacher() : teacherId(0), lastName(""), firstName(""),
middleName(""), birthDate(""),
phoneNumber(""), cycleCommission("") {}

Teacher::Teacher(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : teacherId(id), lastName(lastName), firstName(firstName),
    middleName(middleName), birthDate(birthDate),
    phoneNumber(phoneNumber), cycleCommission(cycleCommission),
    subjects(subjects) {}

Teacher::~Teacher() {}

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << "ID: " << teacher.teacherId << endl;
    os << "�������: " << teacher.lastName << endl;
    os << "��'�: " << teacher.firstName << endl;
    os << "�� �������: " << teacher.middleName << endl;
    os << "���� ����������: " << teacher.birthDate << endl;
    os << "����� ��������: " << teacher.phoneNumber << endl;
    os << "������� �����: " << teacher.cycleCommission << endl;
    os << "�������� ��������: ";
    for (const auto& subject : teacher.subjects) {
        os << subject << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& in, Teacher& teacher) {
    cout << "������ ID: ";
    in >> teacher.teacherId;
    cout << "������ �������: ";
    in >> teacher.lastName;
    cout << "������ ��'�: ";
    in >> teacher.firstName;
    cout << "������ �� �������: ";
    in >> teacher.middleName;
    cout << "������ ���� ����������: ";
    in >> teacher.birthDate;
    cout << "������ ����� ��������: ";
    in >> teacher.phoneNumber;
    cout << "������ ������� �����: ";
    in >> teacher.cycleCommission;
    cout << "������ ������� ���������� ��������: ";
    int n;
    in >> n;
    teacher.subjects.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "������ ������� #" << (i + 1) << ": ";
        in >> teacher.subjects[i];
    }
    return in;
}
