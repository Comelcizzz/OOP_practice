#include "Person.h"

Person::Person() : id(0) {}

Person::Person(int id, const string& lastName, const string& firstName, const string& middleName,
               const string& birthDate, const string& phoneNumber)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    birthDate(birthDate), phoneNumber(phoneNumber) {}

void Person::showInfo() const {
    cout << "ID: " << id << "\n"
         << "Last Name: " << lastName << "\n"
         << "First Name: " << firstName << "\n"
         << "Middle Name: " << middleName << "\n"
         << "Birth Date: " << birthDate << "\n"
         << "Phone: " << phoneNumber << endl;
}

void Person::inputInfo() {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Middle Name: ";
    cin >> middleName;
    cout << "Enter Birth Date: ";
    cin >> birthDate;
    cout << "Enter Phone: ";
    cin >> phoneNumber;
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "ID: " << person.id << "\n"
       << "Last Name: " << person.lastName << "\n"
       << "First Name: " << person.firstName << "\n"
       << "Middle Name: " << person.middleName << "\n"
       << "Birth Date: " << person.birthDate << "\n"
       << "Phone: " << person.phoneNumber << endl;
    return os;
}

istream& operator>>(istream& in, Person& person) {
    person.inputInfo();
    return in;
}
