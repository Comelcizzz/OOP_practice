#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : Person(0, lastName, firstName, middleName, birthDate, phoneNumber),
    cycleCommission(cycleCommission), subjects(subjects) {}

void Teacher::showInfo() const {
    cout << "���������� ��� �������:\n";
    cout << "ID: " << id << "\n"
        << "�������: " << lastName << "\n"
        << "��'�: " << firstName << "\n"
        << "���������: " << middleName << "\n"
        << "���� ����������: " << birthDate << "\n"
        << "�������: " << phoneNumber << "\n"
        << "������� �����: " << cycleCommission << "\n"
        << "��������: ";
    for (const auto& subject : subjects) {
        cout << subject << " ";
    }
    cout << endl;
}

void Teacher::inputInfo() {
    Person::inputInfo();
    cout << "������ ������� �����: ";
    cin >> cycleCommission;

    cout << "������ ������� ��������: ";
    int count;
    cin >> count;
    subjects.resize(count);
    for (int i = 0; i < count; ++i) {
        cout << "������ ������� #" << (i + 1) << ": ";
        cin >> subjects[i];
    }
}

