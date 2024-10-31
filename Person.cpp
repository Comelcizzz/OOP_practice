#include "Person.h"

Person::Person() : id(0) {}

Person::Person(int id, const string& lastName, const string& firstName, const string& middleName,
    const string& birthDate, const string& phoneNumber)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    birthDate(birthDate), phoneNumber(phoneNumber) {}

void Person::showInfo() const {
    cout << "ID: " << id << "\n"
        << "�������: " << lastName << "\n"
        << "��'�: " << firstName << "\n"
        << "���������: " << middleName << "\n"
        << "���� ����������: " << birthDate << "\n"
        << "�������: " << phoneNumber << endl;
}

void Person::inputInfo() {
    cout << "������ ID: ";
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
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "ID: " << person.id << "\n"
        << "�������: " << person.lastName << "\n"
        << "��'�: " << person.firstName << "\n"
        << "���������: " << person.middleName << "\n"
        << "���� ����������: " << person.birthDate << "\n"
        << "�������: " << person.phoneNumber << endl;
    return os;
}

istream& operator>>(istream& in, Person& person) {
    person.inputInfo();
    return in;
}