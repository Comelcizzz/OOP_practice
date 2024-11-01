#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const int& id, const string& lastName, const string& firstName,
                 const string& middleName, const string& birthDate,
                 const string& phoneNumber, const string& cycleCommission)
    : Person(0, lastName, firstName, middleName, birthDate, phoneNumber),
    cycleCommission(cycleCommission) {}

Teacher::~Teacher() {}

void Teacher::showInfo() const {
    cout << "Teacher Information:\n";
    cout << "ID: " << id << "\n"
         << "Last Name: " << lastName << "\n"
         << "First Name: " << firstName << "\n"
         << "Middle Name: " << middleName << "\n"
         << "Birth Date: " << birthDate << "\n"
         << "Phone: " << phoneNumber << "\n"
         << "Cycle Commission: " << cycleCommission << "\n";
}

void Teacher::inputInfo() {
    Person::inputInfo();
    cout << "Enter Cycle Commission: ";
    cin >> cycleCommission;
}

string Teacher::toString() const {
    ostringstream oss;
    oss << "ID: " << id << "\n"
        << "Last Name: " << lastName << "\n"
        << "First Name: " << firstName << "\n"
        << "Middle Name: " << middleName << "\n"
        << "Birth Date: " << birthDate << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Cycle commission: " << cycleCommission;

    return oss.str();
}
