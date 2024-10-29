#include "Student.h"
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);

    Student student1, student2;
    cout << "Введіть дані для студента 1:\n";
    cin >> student1; 

    cout << "Введіть дані для студента 2:\n";
    cin >> student2; 

    cout << "\nДані студентів:\n";
    cout << student1 << endl; 
    cout << student2 << endl; 

    Teacher teacher1, teacher2;
    cout << "Введіть дані для викладача 1:\n";
    cin >> teacher1; 

    cout << "Введіть дані для викладача 2:\n";
    cin >> teacher2; 

    cout << "\nДані викладачів:\n";
    cout << teacher1 << endl; 
    cout << teacher2 << endl; 

    return 0;
}