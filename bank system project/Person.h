#pragma once
#include<iostream>
#include "Validation.h"

using namespace std;

class Person
{
protected:
    int id;
    string name, password;
public:
    Person(string name, string password, int id)
    {
        setName(name);
        setPassword(password);
        this->id = id;
    }
    Person()
    {
        name = "no name";
        password = "no password";
        id = -1;
    }
    void setName(string name)
    {
        if (Validation::checkName(name))
            this->name = name;
        else
        {
            cout << "error name" << endl;
            this->name = "no name";
        }
    }
    void setPassword(string password)
    {
        if (Validation::checkPassword(password))
            this->password = password;
        else
        {
            cout << "error password" << endl;
            this->password = "no password";
        }
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
    void displayPerson()
    {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Password : " << password << endl;
    }
};
