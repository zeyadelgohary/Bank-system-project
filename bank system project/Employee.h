#pragma once
#include <iostream>
#include <vector>
#include "Client.h"

using namespace std;
class Employee : public Person
{
protected:
    double salary;
public:
    Employee(string name, string password, int id, double salary) : Person(name, password, id)
    {
        setSalary(salary);
    }
    Employee()
    {
        salary = 0;
    }
    void setSalary(double salary)
    {
        if (Validation::checkSalary(salary))
            this->salary = salary;
        else
        {
            cout << "salary can't be less than 5000" << endl;
            this->salary = 0;
        }
    }
    double getSalary()
    {
        return salary;
    }
    void display()
    {
        displayPerson();
        cout << "Salary : " << salary << endl;
    }

    void addClient(Client& client)
    {
        allClients.push_back(client);
    }

    Client* searchClient(int id)
    {
        for (cit = allClients.begin(); cit != allClients.end(); cit++)
        {
            if (cit->getId() == id)
            {
                return cit._Ptr;
            }
        }
        return NULL;

    }
    void listClient()
    {
        for (cit = allClients.begin(); cit != allClients.end(); cit++)
        {
            cit->display();
            cout << endl;
        }
    }

    void editClient(int id, string name, string password, double balance)
    {
        searchClient(id)->setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalance(balance);
    }


};

static vector<Employee> allEmployess;
static vector<Employee> ::iterator eit;


