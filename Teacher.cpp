#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : lastName(lastName), firstName(firstName), middleName(middleName),
    birthDate(birthDate), phoneNumber(phoneNumber), cycleCommission(cycleCommission),
    subjects(subjects) {}

void Teacher::showInfo() {
    cout << "�������: " << lastName << "\n"
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

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << "�������: " << teacher.lastName << "\n"
        << "��'�: " << teacher.firstName << "\n"
        << "���������: " << teacher.middleName << "\n"
        << "���� ����������: " << teacher.birthDate << "\n"
        << "�������: " << teacher.phoneNumber << "\n"
        << "������� �����: " << teacher.cycleCommission << "\n"
        << "��������: ";
    for (const auto& subject : teacher.subjects) {
        os << subject << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& in, Teacher& teacher) {
    cout << "������ �������: ";
    in >> teacher.lastName;
    cout << "������ ��'�: ";
    in >> teacher.firstName;
    cout << "������ ���������: ";
    in >> teacher.middleName;
    cout << "������ ���� ����������: ";
    in >> teacher.birthDate;
    cout << "������ �������: ";
    in >> teacher.phoneNumber;
    cout << "������ ������� �����: ";
    in >> teacher.cycleCommission;

    cout << "������ ������� ��������: ";
    int count;
    in >> count;
    teacher.subjects.resize(count);
    for (int i = 0; i < count; ++i) {
        cout << "������ ������� #" << (i + 1) << ": ";
        in >> teacher.subjects[i];
    }
    return in;
}