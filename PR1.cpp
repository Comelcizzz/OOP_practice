#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "Teacher.h"
#include "Student.h"
#include "Vector.h"

using namespace std;

void showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Створити студента\n";
    cout << "2. Створити вчителя\n";
    cout << "0. Вихід\n";
    cout << "Оберіть опцію: ";
}

vector<int> generateEvenNumbers() {
    vector<int> evenNumbers;
    for (int i = 0; i < 10; ++i) {
        evenNumbers.push_back(2 * (rand() % 50)); 
    }
    return evenNumbers;
}

vector<int> generateOddNumbers() {
    vector<int> oddNumbers;
    for (int i = 0; i < 10; ++i) {
        oddNumbers.push_back(2 * (rand() % 50) + 1); 
    }
    return oddNumbers;
}

void displayVector(const vector<int>& vec, const string& name) {
    cout << name << ": ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(1251);

    vector<int> oddNumbers = generateOddNumbers();
    vector<int> evenNumbers = generateEvenNumbers();

    sort(oddNumbers.begin(), oddNumbers.end());
    sort(evenNumbers.begin(), evenNumbers.end());

    vector<int> mergedVector(oddNumbers.size() + evenNumbers.size());
    merge(oddNumbers.begin(), oddNumbers.end(), evenNumbers.begin(), evenNumbers.end(), mergedVector.begin());

    displayVector(oddNumbers, "Непарні числа");
    displayVector(evenNumbers, "Парні числа");
    displayVector(mergedVector, "Об'єднаний вектор");

    Vector<Teacher*> teacherVector;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            Student* student = new Student();
            student->inputInfo();
            teacherVector.push_back(student); 
            break;
        }
        case 2: {
            Teacher* teacher = new Teacher();
            teacher->inputInfo();
            teacherVector.push_back(teacher); 
            break;
        }
        case 0:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір, спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);

    cout << "\nСписок об'єктів:\n";
    for (int i = 0; i < teacherVector.getSize(); i++) {
        if (teacherVector[i]) {
            teacherVector[i]->showInfo();
            cout << endl;
        }
    }

    for (auto it = teacherVector.begin(); it != teacherVector.end();) {
        if (dynamic_cast<Student*>(*it)) {
            delete* it; 
            it = teacherVector.erase(it); 
        }
        else {
            ++it;
        }
    }

    cout << "Вектор після видалення студентів:\n";
    for (const auto& obj : teacherVector) {
        if (obj) {
            obj->showInfo(); 
            cout << endl;
        }
    }

    for (int i = 0; i < teacherVector.getSize(); i++) {
        delete teacherVector[i]; 
    }

    return 0;
}
