#pragma once
#include <iostream>

using namespace std;
class Validation
{
public:
    static bool checkName(string name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            bool checkAlpha = false;
            if (name[i] >= 65 && name[i] <= 95 || name[i] >= 97 && name[i] <= 122)
            {
                checkAlpha = true;
            }
            if (!checkAlpha)
            {
                return false;
            }

        }
        if (name.size() >= 5 && name.size() <= 20)
            return true;
        else
            return false;

    }
    static bool checkPassword(string password)
    {
        if (password.size() >= 8 && password.size() <= 20)
            return true;
        else
            return false;

    }
    static bool checkBalance(double balance)
    {
        if (balance >= 1500)
            return true;
        else
            return false;

    }
    static bool checkSalary(double salary)
    {
        if (salary >= 5000)
            return true;
        else
            return false;

    }

};
