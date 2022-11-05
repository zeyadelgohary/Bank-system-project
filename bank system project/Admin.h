#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

class Admin : public Employee
{
public:
    Admin(string name, string password, int id, double salary) :Employee(name, password, id, salary) {}
    Admin() {}
    void addEmployee(Employee& e)
    {
        allEmployess.push_back(e);
    }
    Employee* searchEmployee(int id)
    {
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++)
        {
            if (eit->getId() == id)
            {
                return eit._Ptr;
            }
        }
        return NULL;
    }
    void editEmployee(int id, string name, string password, double salary)
    {
        searchEmployee(id)->setName(name);
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);
    }
    void listEmployee()
    {
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++)
        {
            eit->display();
            cout << endl;
        }
    }

};

static vector<Admin> allAdmins;
static vector<Admin> ::iterator ait;

