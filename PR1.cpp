#include "Teacher.h"
#include "Student.h"
#include "Vector.h"

int showMenu() {
    int choice;
    cout << "Виберіть тип об'єкта для створення:\n";
    cout << "1. Вчитель\n";
    cout << "2. Студент\n";
    cout << "3. Вивести об'єкт з контейнера\n";
    cout << "4. Вихід\n";
    cout << "Ваш вибір: ";
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleOutputCP(1251);

    list<int> list1;
    for (int i = 1; i <= 20; i += 2) {
        list1.push_back(i);
    }

    list<int> list2;
    for (int i = 2; i <= 20; i += 2) {
        list2.push_back(i);
    }

    list<int> list3;
    merge(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(list3));

    cout << "List 1: ";
    for (auto n : list1) cout << n << " ";
    cout << endl;

    cout << "List 2: ";
    for (auto n : list2) cout << n << " ";
    cout << endl;

    cout << "List 3: ";
    for (auto n : list3) cout << n << " ";
    cout << endl;

    map<int, Teacher*> teacherMap;
    map<int, Student*> studentMap;
    int choice = 0;

    while (choice != 4) {
        choice = showMenu();
        switch (choice) {
        case 1: {
            Teacher* teacher = new Teacher();
            cin >> *teacher; 
            teacherMap[teacher->getId()] = teacher;
            break;
        }
        case 2: {
            Student* student = new Student();
            cin >> *student; 
            studentMap[student->getId()] = student;
            break;
        }
        case 3: {
            int id;
            cout << "Введіть id: ";
            cin >> id;
            if (auto* student = dynamic_cast<Student*>(studentMap[id])) {
                student->showInfo();
            }
            else if (auto* teacher = dynamic_cast<Teacher*>(teacherMap[id])) {
                teacher->showInfo(); 
            }
            else {
                cout << "Об'єкт з таким id не знайдено." << endl;
            }
            break;
        }
        case 4:
            break;
        default:
            cout << "Невірний вибір" << endl;
        }
    }

    for (auto& pair : teacherMap) {
        delete pair.second;
    }
    for (auto& pair : studentMap) {
        delete pair.second;
    }

    return 0;
}
