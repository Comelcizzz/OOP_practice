#include <iostream>
#include <vector>
#include <Windows.h>
#include "Teacher.h"
#include "Student.h"

using namespace std;

void displayMenu() {
    cout << "1. Додати студента\n";
    cout << "0. Вийти\n";
}

int main() {
    SetConsoleOutputCP(1251);
    const int size = 5;
    Teacher** teachers = new Teacher* [size];

    int choice;
    for (int i = 0; i < size; ++i) {
        displayMenu();
        cout << "Оберіть опцію: ";
        cin >> choice;

        if (choice == 1) {
            teachers[i] = new Student; 
            teachers[i]->inputInfo();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            --i; 
        }
    }

    cout << "\nВведена інформація про студентів:\n";
    for (int i = 0; i < size; ++i) {
        if (teachers[i]) {
            cout << *teachers[i]; 
        }
    }

    cout << "\nВиклик методу showInfo для кожного студента:\n";
    for (int i = 0; i < size; ++i) {
        if (teachers[i]) {
            teachers[i]->showInfo(); 
        }
    }

    return 0;
}
