#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : lastName(lastName), firstName(firstName), middleName(middleName),
    birthDate(birthDate), phoneNumber(phoneNumber), cycleCommission(cycleCommission),
    subjects(subjects) {}

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
