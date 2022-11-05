#pragma once
#include <iostream>
#include <fstream>
#include "Parser.h"

using namespace std;

class FilesHelper
{
public:
    static void saveLast(string fileName, int id)
    {
        ofstream saveid;
        saveid.open(fileName);
        saveid << id;
        saveid.close();
    }

    static int getLast(string fileName)
    {
        ifstream getid;
        getid.open(fileName);
        int id;
        getid >> id;
        getid.close();
        return id;
    }
    static void saveClient(Client c)
    {
        int id = getLast("clientLastId.txt");
        ofstream save;
        save.open("clients.txt", ios::app);
        save << id + 1 << ',' << c.getName() << ',' << c.getPassword() << ',' << c.getBalance() << endl;
        save.close();
        saveLast("clientLastId.txt", id + 1);
    }
    static void saveEmployee(string filename, string lastIdfile, Employee e)
    {
        int id = getLast(lastIdfile);
        ofstream file;
        file.open(filename, ios::app);
        file << id + 1 << ',' << e.getName() << ',' << e.getPassword() << ',' << e.getSalary() << endl;
        file.close();
        saveLast(lastIdfile, id + 1);
    }
    static void getClients()
    {
        string line;
        ifstream file;
        file.open("clients.txt");
        while (getline(file, line))
        {
            Client c = Parser::parseToclient(line);
            allClients.push_back(c);
        }
        file.close();
    }
    static void getEmployees()
    {
        string line;
        ifstream file;
        file.open("employees.txt");
        while (getline(file, line))
        {
            Employee emp = Parser::parseToemployee(line);
            allEmployess.push_back(emp);
        }
        file.close();
    }
    static void getAdmins()
    {
        string line;
        ifstream file;
        file.open("admins.txt");
        while (getline(file, line))
        {
            Admin a = Parser::parseToadmin(line);
            allAdmins.push_back(a);

        }
        file.close();
    }

  /*  static void clearFile(string fileName, string lastIdfile)
    {
        fstream file1, file2;
        file1.open(fileName, ios::out);
        file1.close();
        file2.open(lastIdfile, ios::out);
        file2 << 0;
        file2.close();
    }*/
    static void clearFile(string fileName)
    {
        fstream file1;
        file1.open(fileName, ios::out);
        file1.close();
    }
    static void clearLastID(string fileName) {
        fstream file2;
        file2.open(fileName, ios::out);
        file2 << 0;
        file2.close();

    }



};



