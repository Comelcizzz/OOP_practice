#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
                 const string& middleName, const string& birthDate,
                 const string& phoneNumber, const string& cycleCommission)
    : Person(0, lastName, firstName, middleName, birthDate, phoneNumber),
    cycleCommission(cycleCommission) {}

Teacher::~Teacher() {}

void Teacher::showInfo() const {
    cout << "���������� ��� ���������:\n";
    cout << "ID: " << id << "\n"
         << "�������: " << lastName << "\n"
         << "��'�: " << firstName << "\n"
         << "�� �������: " << middleName << "\n"
         << "���� ����������: " << birthDate << "\n"
         << "�������: " << phoneNumber << "\n"
         << "������� �����: " << cycleCommission << "\n";
}

void Teacher::inputInfo() {
    Person::inputInfo();
    cout << "������ ������� �����: ";
    cin >> cycleCommission;
}
