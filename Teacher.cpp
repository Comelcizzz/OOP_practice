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
    cout << "Прізвище: " << lastName << "\n"
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

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << "Прізвище: " << teacher.lastName << "\n"
        << "Ім'я: " << teacher.firstName << "\n"
        << "Побатькові: " << teacher.middleName << "\n"
        << "Дата народження: " << teacher.birthDate << "\n"
        << "Телефон: " << teacher.phoneNumber << "\n"
        << "Циклова комісія: " << teacher.cycleCommission << "\n"
        << "Предмети: ";
    for (const auto& subject : teacher.subjects) {
        os << subject << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& in, Teacher& teacher) {
    cout << "Введіть прізвище: ";
    in >> teacher.lastName;
    cout << "Введіть ім'я: ";
    in >> teacher.firstName;
    cout << "Введіть побатькові: ";
    in >> teacher.middleName;
    cout << "Введіть дату народження: ";
    in >> teacher.birthDate;
    cout << "Введіть телефон: ";
    in >> teacher.phoneNumber;
    cout << "Введіть циклову комісію: ";
    in >> teacher.cycleCommission;

    cout << "Введіть кількість предметів: ";
    int count;
    in >> count;
    teacher.subjects.resize(count);
    for (int i = 0; i < count; ++i) {
        cout << "Введіть предмет #" << (i + 1) << ": ";
        in >> teacher.subjects[i];
    }
    return in;
}