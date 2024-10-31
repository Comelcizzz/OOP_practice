#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
                 const string& middleName, const string& birthDate,
                 const string& phoneNumber, const string& cycleCommission)
    : Person(0, lastName, firstName, middleName, birthDate, phoneNumber),
    cycleCommission(cycleCommission) {}

Teacher::~Teacher() {}

void Teacher::showInfo() const {
    cout << "Інформація про викладача:\n";
    cout << "ID: " << id << "\n"
         << "Прізвище: " << lastName << "\n"
         << "Ім'я: " << firstName << "\n"
         << "По батькові: " << middleName << "\n"
         << "Дата народження: " << birthDate << "\n"
         << "Телефон: " << phoneNumber << "\n"
         << "Циклова комісія: " << cycleCommission << "\n";
}

void Teacher::inputInfo() {
    Person::inputInfo();
    cout << "Введіть циклову комісію: ";
    cin >> cycleCommission;
}
