#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Admin.h"

using namespace std;

class Parser
{
private:
    static vector<string> split(string line)
    {
        stringstream ss(line);
        string part;
        vector<string> splitVector;
        while (getline(ss, part, ','))
        {
            splitVector.push_back(part);
        }
        return splitVector;
    }
public:
    static Client parseToclient(string line)
    {
        vector<string> clientVector = split(line);
        Client c;
        c.setId(stoi(clientVector[0]));
        c.setName(clientVector[1]);
        c.setPassword(clientVector[2]);
        c.setBalance(stod(clientVector[3]));
        return c;
    }

    static Employee parseToemployee(string line)
    {
        vector<string> employeeVector = split(line);
        Employee emp;
        emp.setId(stoi(employeeVector[0]));
        emp.setName(employeeVector[1]);
        emp.setPassword(employeeVector[2]);
        emp.setSalary(stod(employeeVector[3]));
        return emp;
    }
    static Admin parseToadmin(string line)
    {
        vector<string> adminVector = split(line);
        Admin a;
        a.setId(stoi(adminVector[0]));
        a.setName(adminVector[1]);
        a.setPassword(adminVector[2]);
        a.setSalary(stod(adminVector[3]));
        return a;
    }
};
