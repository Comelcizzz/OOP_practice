﻿#include "Student.h"
#include <Windows.h>
        
int main()
{   
    SetConsoleOutputCP(1251);

    Student object1, object2, object3; 
    cin >> object1 >> object2 >> object3;

    cout << object1 << endl << object2 << endl << object3;

    if (object1 == object2) {
        cout << "Студенти однакові." << endl;
    }
    else {
        cout << "Студенти різні." << endl;
    }
}
