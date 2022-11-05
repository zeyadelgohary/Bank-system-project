#pragma once
#include <iostream>
#include "EmployeeManager.h"

using namespace std;

Admin* adminLoggedIn;

class AdminManager : public EmployeeManager {
public:
    static Admin* loginAdmin(int id, string password) {
        for (ait = allAdmins.begin(); ait != allAdmins.end(); ait++) {
            if (ait->getId() == id && ait->getPassword() == password) {
                return ait._Ptr;
            }
        }
        return NULL;
    }

    static void updatePassword(Admin* a) {
        string password;
        cout << "Enter the new password: ";
        cin >> password;
        for (ait = allAdmins.begin(); ait != allAdmins.end(); ait++) {
            if (ait->getId() == a->getId() && ait->getName() == a->getName()) {
                ait->setPassword(password);
                break;
            }
        }
    }

    static void addNewEmployee(Admin* a) {
        string name, password;
        double salary;
        int id = FilesHelper::getLast("employeeLastId.txt");
        FilesHelper::saveLast("employeeLastId.txt", id + 1);
        cout << "Enter the name of the new employee: ";
        cin >> name;
        cout << "Enter the password of the new employee: ";
        cin >> password;
        cout << "Enter the salary of the new employee: ";
        cin >> salary;
        Employee newEmp(name, password, id + 1, salary);
        a->addEmployee(newEmp);
    }

    static void listEmployees(Admin* a) {
        a->listEmployee();
    }

    static void searchForEmployee(Admin* a) {
        int id;
        cout << "Enter the id of the employee: ";
        cin >> id;
        Employee* searchedEmployee = a->searchEmployee(id);
        if (searchedEmployee == NULL) {
            cout << "This employee doesn't exist" << endl;
            return;
        }
        searchedEmployee->display();
    }

    static void editEmployeeInfo(Admin* a) {
        int id;
        string name, password;
        double salary;
        cout << "Enter the id of the employee to edit: ";
        cin >> id;
        cout << "Enter the name of the employee after edit: ";
        cin >> name;
        cout << "Enter the password of the employee after edit: " << endl;
        cin >> password;
        cout << "Enter the salary of the employee after edit: " << endl;
        cin >> salary;
        a->editEmployee(id, name, password, salary);
    }

    static void removeEmployee() {
        int id, index = 0;
        cout << "Enter the id to remove the employee: ";
        cin >> id;
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++) {
            if (eit->getId() == id) {
                allEmployess.erase(allEmployess.begin() + index);
                break;
            }
            index++;
        }
    }
    static void assignNewAdmin() {
        string name, password;
        int id = FilesHelper::getLast("adminLastId.txt");
        FilesHelper::saveLast("adminLastId.txt", id + 1);
        double salary;
        cout << "Enter the name of the new Admin: ";
        cin >> name;
        cout << "Enter the password of the new Admin: ";
        cin >> password;
        cout << "Enter the salary of the new Admin: ";
        cin >> salary;
        Admin a(name, password, id + 1, salary);
        allAdmins.push_back(a);
    }

    static void printAdminMenu() {
        cout << endl;
        cout << "1- Add new client" << endl;
        cout << "2- Search for a client" << endl;
        cout << "3- Edit info of a client" << endl;
        cout << "4- Remove existing client" << endl;
        cout << "5- List all clients" << endl;
        cout << "6- Add new employee" << endl;
        cout << "7- Search for an employee" << endl;
        cout << "8- Edit info of an employee" << endl;
        cout << "9- Remove existing employee" << endl;
        cout << "10- List all employees" << endl;
        cout << "11- Assign new admin" << endl;
        cout << "12- Display my info" << endl;
        cout << "13- Clear clients file" << endl;
        cout << "14- Clear employees file" << endl;
        cout << "15- Update password" << endl;
        cout << "16- Check my salary" << endl;
        cout << "17- Logout" << endl;
    }

    static void adminOptions(int choice) {
        switch (choice) {
        case 1:
            addNewClient(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 2:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            searchForClient(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 3:
            editClientInfo(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 4:
            removeClient();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 5:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            listAllClients(adminLoggedIn);
            cout << endl << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 6:
            addNewEmployee(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 7:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            searchForEmployee(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 8:
            editEmployeeInfo(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 9:
            removeEmployee();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 10:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            listEmployees(adminLoggedIn);
            cout << endl << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 11:
            assignNewAdmin();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 12:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Your Info: " << endl;
            adminLoggedIn->display();
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 13:
            FileManager::removeAllClients();
            FileManager::removeClientLastID();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 14:
            FileManager::removeAllEmployees();
            FileManager::removeEmployeeLastID();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 15:
            updatePassword(adminLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 16:
            cout << adminLoggedIn->getSalary();
            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 17:
            system("cls");
            cout << "you are logged out the system" << endl;
            break;
        default:
            cout << "Invalid number" << endl;
            break;

        }
    }

};
