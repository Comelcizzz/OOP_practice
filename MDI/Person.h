#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <Qvector>
#include <Qlist>
#include <Qmap>
#include <Windows.h>
#include <sstream>

using namespace std;

class Person {
protected:
    int id;
    string lastName;
    string firstName;
    string middleName;
    string birthDate;
    string phoneNumber;

public:
    Person();

    Person(int id, const string& lastName, const string& firstName,
        const string& middleName, const string& birthDate,
        const string& phoneNumber);

    virtual ~Person() = default;  

    virtual void showInfo() const = 0;  
    virtual void inputInfo();

    int getId() const { return id; }  

    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& in, Person& person);
};

#endif // PERSON_H
