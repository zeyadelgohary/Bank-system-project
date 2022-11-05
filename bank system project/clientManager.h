#pragma once
#include <iostream>
#include "FileManager.h"

using namespace std;

Client* currentLoggedIn;

class clientManager {
public:

    static Client* login(int id, string password) {
        for (cit = allClients.begin(); cit != allClients.end(); cit++) {
            if (cit->getId() == id && cit->getPassword() == password)
                return cit._Ptr;
        }
        return NULL;
    }


    static void printClientMenu() {
        cout << endl;
        cout << "1- Deposit " << endl;
        cout << "2- Withdraw " << endl;
        cout << "3- Transfer " << endl;
        cout << "4- Check your balance" << endl;
        cout << "5- Display your info" << endl;
        cout << "6- Update your password" << endl;
        cout << "7- logout" << endl;
        cout << endl;
    }

    static void updatePassword(Client* c) {
        string newPassword;
        cout << "Enter your new password : ";
        cin >> newPassword;
        for (cit = allClients.begin(); cit != allClients.end(); cit++) {
            if (cit->getId() == c->getId() && cit->getName() == c->getName()) {
                cit->setPassword(newPassword);
                break;
            }
        }
        FileManager::updateClients();
    }

    static void clientOptions(int choice) {
        double amount;
        switch (choice) {
        case 1:
            cout << "Enter the amount to deposit : ";
            cin >> amount;
            currentLoggedIn->deposit(amount);
            cout << "Done " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 2:
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            currentLoggedIn->withdraw(amount);
            cout << "Done " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 3:
            cout << "Enter the amount to tranfer : ";
            cin >> amount;
            cout << "Enter the id of the recipient client : " ;
            int id;
            cin >> id;
            for (cit = allClients.begin(); cit != allClients.end(); cit++) {
                if (cit->getId() == id) {
                    currentLoggedIn->transferTo(amount, *cit);
                    break;
                }
            }
            cout << "Done " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 4:
            currentLoggedIn->checkBalance();
            cout << "Done " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 5:
            cout << "Your Info : " << endl;
            currentLoggedIn->display();
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 6:
            updatePassword(currentLoggedIn);
            cout << "Done " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        case 7:
            system("cls");
            cout << "you are logged out the system" << endl;
            break;
        default:
            cout << "Invalid number" << endl;
            break;
        }
    }


};

