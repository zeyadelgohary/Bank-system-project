#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;
class Client : public Person
{
private:
    double balance;
public:
    Client(string name, string password, int id, double balance) :Person(name, password, id)
    {
        setBalance(balance);
    }
    Client()
    {
        balance = 0;
    }
    void setBalance(double balance)
    {
        if (Validation::checkBalance(balance))
            this->balance = balance;
        else
        {
            cout << "balance can't be less than 1500" << endl;
            this->balance = 0;
        }
    }
    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount > balance || amount < 0)
        {
            cout << "Can't withdraw this amount" << endl;
            return;
        }
        balance -= amount;
    }
    void transferTo(double amount, Client& recipient)
    {
        if (amount > balance || amount < 0)
        {
            cout << "Can't transfer this amount" << endl;
            return;
        }
        balance -= amount;
        recipient.balance += amount;
    }
    void checkBalance()
    {
        cout << "Your balance is : " << balance << endl;
    }
    void display()
    {
        displayPerson();
        cout << "Balance : " << balance << endl;
    }
};

static vector<Client> allClients;
vector<Client> ::iterator cit;


