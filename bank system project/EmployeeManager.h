#pragma once
#include <iostream>
#include "clientManager.h"

using namespace std;


Employee* employeeLoggedIn;

class EmployeeManager {
public:
    static Employee* login(int id, string password) {
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++) {
            if (eit->getId() == id && eit->getPassword() == password) {
                return eit._Ptr;
            }
        }
        return NULL;
    }
    static void addNewClient(Employee* emp) {
        string name, password;
        double balance;
        int id = FilesHelper::getLast("clientLastId.txt");
        FilesHelper::saveLast("clientLastId.txt", id + 1);
        cout << "Enter the name of the new client: ";
        cin >> name;
        cout << "Enter the password of the new client: ";
        cin >> password;
        cout << "Enter the balance of the new client: ";
        cin >> balance;
        Client newClient(name, password, id + 1, balance);
        emp->addClient(newClient);
    }

    static void listAllClients(Employee* emp) {
        emp->listClient();
    }

    static void searchForClient(Employee* emp) {
        int id;
        cout << "Enter the id of the client: ";
        cin >> id;
        Client* SearchedClient = emp->searchClient(id);
        if (SearchedClient == NULL) {
            cout << "This client doesn't exist" << endl;
            return;
        }
        SearchedClient->display();

    }
    static void editClientInfo(Employee* emp) {
        int id;
        string name, password;
        double balance;
        cout << "Enter the id of the client to edit: ";
        cin >> id;
        cout << "Enter the name of the client after edit: ";
        cin >> name;
        cout << "Enter the password of the client after edit: " << endl;
        cin >> password;
        cout << "Enter the balance of the client after edit: " << endl;
        cin >> balance;
        emp->editClient(id, name, password, balance);
    }

    static void updatePassword(Employee* emp) {
        string password;
        cout << "Enter the new password: ";
        cin >> password;
        for (eit = allEmployess.begin(); eit != allEmployess.end(); eit++) {
            if (eit->getId() == emp->getId() && eit->getName() == emp->getName()) {
                eit->setPassword(password);
                break;
            }
        }
    }

    static void removeClient() {
        int id, index = 0;
        cout << "Enter the id to remove the client: ";
        cin >> id;
        for (cit = allClients.begin(); cit != allClients.end(); cit++) {
            if (cit->getId() == id) {
                allClients.erase(allClients.begin() + index);
                break;
            }
            index++;
        }
    }

    static void printEmployeeMenu() {
        cout << endl;
        cout << "1- Add new client" << endl;
        cout << "2- Search for a client" << endl;
        cout << "3- Edit client " << endl;
        cout << "4- list all clients" << endl;
        cout << "5- Remove Client" << endl;
        cout << "6- Check my salary" << endl;
        cout << "7- Display my Info" << endl;
        cout << "8- Update password" << endl;
        cout << "9- Logout" << endl;
    }

    static void employeeOptions(int choice) {

        switch (choice) {
        case 1:
            addNewClient(employeeLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 2:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            searchForClient(employeeLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 3:
            editClientInfo(employeeLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 4:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            listAllClients(employeeLoggedIn);
            cout << endl << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 5:
            removeClient();
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 6:
            cout<<employeeLoggedIn->getSalary();
            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 7:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Your Info: " << endl;
            employeeLoggedIn->display();
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 8:
            updatePassword(employeeLoggedIn);
            cout << "Done" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 9:
            system("cls");
            cout << "you are logged out the system" << endl;
            break;
        default:
            cout << "Invalid number" << endl;
            break;
        }
    }

};

