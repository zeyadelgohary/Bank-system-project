#pragma once
#include <iostream>
#include "DataSourceInterface.h"

using namespace std;
class FileManager : public DataSourceInterface {

private:
    static void addClient(Client c)
    {
        FilesHelper::saveClient(c);
    }

    static void addEmployee(Employee e)
    {
        FilesHelper::saveEmployee("employees.txt", "employeeLastId.txt", e);
    }
    static void addAdmin(Admin a)
    {
        FilesHelper::saveEmployee("admins.txt", "adminLastId.txt", a);
    }


    static void getAllClients()
    {
        FilesHelper::getClients();
    }

    static void getAllEmployees()
    {
        FilesHelper::getEmployees();
    }

    static void getAllAdmins()
    {
        FilesHelper::getAdmins();
    }


    static void removeAllAdmins()
    {
      //  FilesHelper::clearFile("admins.txt", "adminLastId.txt");
        FilesHelper::clearFile("admins.txt");
    }
public:
    static void removeAllClients()
    {
       // FilesHelper::clearFile("clients.txt", "clientLastId.txt");
        FilesHelper::clearFile("clients.txt");
    }

    static  void removeAllEmployees()
    {
       // FilesHelper::clearFile("employees.txt", "employeeLastId.txt");
        FilesHelper::clearFile("employees.txt");
    }

    static void removeClientLastID() {
        FilesHelper::clearLastID("clientLastId.txt");
    }
    static void removeEmployeeLastID() {
        FilesHelper::clearLastID("employeeLastId.txt");
    }
    static void removeAdminLastID() {
        FilesHelper::clearLastID("adminLastId.txt");
    }

    static void getAlldata()
    {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }
    static void updateClients()
    {
       removeAllClients();
       ofstream save;
       save.open("clients.txt", ios::app);
       for (cit = allClients.begin(); cit != allClients.end(); cit++) {
            save << cit->getId() << ',' << cit->getName() << ',' << cit->getPassword() << ',' << cit->getBalance() << endl;
       }
       save.close(); 
            //addClient(*cit);
    }
    static void updateEmployees()
    {
        removeAllEmployees();
        ofstream save;
        save.open("employees.txt", ios::app);
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++) {
            save << eit->getId() << ',' << eit->getName() << ',' << eit->getPassword() << ',' << eit->getSalary() << endl;
        }
        save.close();
           // addEmployee(*eit);
    }
    static void updateAdmins()
    {
        removeAllAdmins();
        ofstream save;
        save.open("admins.txt", ios::app);
        for (ait = allAdmins.begin(); ait != allAdmins.end(); ait++) {
            save << ait->getId() << ',' << ait->getName() << ',' << ait->getPassword() << ',' << ait->getSalary() << endl;
        }
        save.close();
        //    addAdmin(*ait);
    }
};
