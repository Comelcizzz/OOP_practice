#include "Person.h"

Person::Person() : id(0) {}

Person::Person(int id, const string& lastName, const string& firstName, const string& middleName,
    const string& birthDate, const string& phoneNumber)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    birthDate(birthDate), phoneNumber(phoneNumber) {}

void Person::showInfo() const {
    cout << "ID: " << id << "\n"
        << "Прізвище: " << lastName << "\n"
        << "Ім'я: " << firstName << "\n"
        << "Побатькові: " << middleName << "\n"
        << "Дата народження: " << birthDate << "\n"
        << "Телефон: " << phoneNumber << endl;
}

void Person::inputInfo() {
    cout << "Введіть ID: ";
    cin >> id;
    cout << "Введіть прізвище: ";
    cin >> lastName;
    cout << "Введіть ім'я: ";
    cin >> firstName;
    cout << "Введіть побатькові: ";
    cin >> middleName;
    cout << "Введіть дату народження: ";
    cin >> birthDate;
    cout << "Введіть телефон: ";
    cin >> phoneNumber;
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "ID: " << person.id << "\n"
        << "Прізвище: " << person.lastName << "\n"
        << "Ім'я: " << person.firstName << "\n"
        << "Побатькові: " << person.middleName << "\n"
        << "Дата народження: " << person.birthDate << "\n"
        << "Телефон: " << person.phoneNumber << endl;
    return os;
}

istream& operator>>(istream& in, Person& person) {
    person.inputInfo();
    return in;
}