#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : Person(0, lastName, firstName, middleName, birthDate, phoneNumber),
    cycleCommission(cycleCommission), subjects(subjects) {}

void Teacher::showInfo() const {
    cout << "Інформація про вчителя:\n";
    cout << "ID: " << id << "\n"
        << "Прізвище: " << lastName << "\n"
        << "Ім'я: " << firstName << "\n"
        << "Побатькові: " << middleName << "\n"
        << "Дата народження: " << birthDate << "\n"
        << "Телефон: " << phoneNumber << "\n"
        << "Циклова комісія: " << cycleCommission << "\n"
        << "Предмети: ";
    for (const auto& subject : subjects) {
        cout << subject << " ";
    }
    cout << endl;
}

void Teacher::inputInfo() {
    Person::inputInfo();
    cout << "Введіть циклову комісію: ";
    cin >> cycleCommission;

    cout << "Введіть кількість предметів: ";
    int count;
    cin >> count;
    subjects.resize(count);
    for (int i = 0; i < count; ++i) {
        cout << "Введіть предмет #" << (i + 1) << ": ";
        cin >> subjects[i];
    }
}

