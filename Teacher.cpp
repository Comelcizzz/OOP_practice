#include "Teacher.h"

using namespace std;

Teacher::Teacher() : teacherId(0), lastName(""), firstName(""),
middleName(""), birthDate(""),
phoneNumber(""), cycleCommission("") {}

Teacher::Teacher(int id, const string& lastName, const string& firstName,
    const string& middleName, const string& birthDate,
    const string& phoneNumber, const string& cycleCommission,
    const vector<string>& subjects)
    : teacherId(id), lastName(lastName), firstName(firstName),
    middleName(middleName), birthDate(birthDate),
    phoneNumber(phoneNumber), cycleCommission(cycleCommission),
    subjects(subjects) {}

Teacher::~Teacher() {}

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << "ID: " << teacher.teacherId << endl;
    os << "Прізвище: " << teacher.lastName << endl;
    os << "Ім'я: " << teacher.firstName << endl;
    os << "По батькові: " << teacher.middleName << endl;
    os << "Дата народження: " << teacher.birthDate << endl;
    os << "Номер телефону: " << teacher.phoneNumber << endl;
    os << "Циклова комісія: " << teacher.cycleCommission << endl;
    os << "Навчальні предмети: ";
    for (const auto& subject : teacher.subjects) {
        os << subject << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& in, Teacher& teacher) {
    cout << "Введіть ID: ";
    in >> teacher.teacherId;
    cout << "Введіть прізвище: ";
    in >> teacher.lastName;
    cout << "Введіть ім'я: ";
    in >> teacher.firstName;
    cout << "Введіть по батькові: ";
    in >> teacher.middleName;
    cout << "Введіть дату народження: ";
    in >> teacher.birthDate;
    cout << "Введіть номер телефону: ";
    in >> teacher.phoneNumber;
    cout << "Введіть циклову комісію: ";
    in >> teacher.cycleCommission;
    cout << "Введіть кількість навчальних предметів: ";
    int n;
    in >> n;
    teacher.subjects.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Введіть предмет #" << (i + 1) << ": ";
        in >> teacher.subjects[i];
    }
    return in;
}
