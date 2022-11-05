#pragma once
#include <iostream>
#include "AdminManager.h"

using namespace std;
class Screens {
public:
    static void bankName() {
        cout << "*************************************" << endl << endl;
        cout << "Egypt Bank" << endl << endl;
        cout << "*************************************" << endl << endl;
    }
    static void welcome() {
        cout << "Welcome to our bank.." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }
    static void loginOptions() {
        cout << "Who are you ? " << endl;
        cout << "1- Client" << endl;
        cout << "2- Employee" << endl;
        cout << "3- Admin" << endl;
        cout << "4- Exit system" << endl;
    }
    static void invalid(int c) {
        cout << c << " is invalid number" << endl;
    }
    static int loginAs() {
        int choice;
        cout << "Enter number: ";
        cin >> choice;
        return choice;
    }
    static void menu() {
        bankName();
        welcome();
        loginOptions();
    }
    static void logOut() {
        system("cls");
        cout << "you are logged out the system" << endl;
    }


    static void loginScreen(int c) {

        cout << "(Enter -1 to return menu)" << endl;
        cout << "Enter your id : ";
        int id;
        cin >> id;
        if (id == -1) {
            system("cls");
            runApp();
        }
        cout << "Enter your password : ";
        string password;
        cin >> password;
        if (c == 1) {
            currentLoggedIn = clientManager::login(id, password);
        }
        if (c == 2) {
            employeeLoggedIn = EmployeeManager::login(id, password);
        }
        if (c == 3) {
            adminLoggedIn = AdminManager::loginAdmin(id, password);
        }
        if (c == 4) {
            logOut();
        }
    }


        static void runApp() {
        FileManager::getAlldata();
        currentLoggedIn = NULL;
        employeeLoggedIn = NULL;
        adminLoggedIn = NULL;
        system("cls");
        
    loop:
        menu();
        int choice = loginAs();
        system("cls");

        if (choice == 1) {

            while (currentLoggedIn == NULL) {
                loginScreen(1);
                if (currentLoggedIn == NULL) {
                    cout << "Wrong ID or Password , Please try again" << endl;
                }
            }
            system("cls");
            cout << "Hello " << currentLoggedIn->getName() << " what do you want ? " << endl;
            int clientChoice;
            do {
                clientManager::printClientMenu();
                cout << "Enter your choice : ";
                cin >> clientChoice;
                clientManager::clientOptions(clientChoice);
                FileManager::updateClients();
                FileManager::updateEmployees();
                FileManager::updateAdmins();

            } while (clientChoice != 7);
        }

        else if (choice == 2) {

            while (employeeLoggedIn == NULL) {
                loginScreen(2);
                if (employeeLoggedIn == NULL) {
                    cout << "Wrong ID or Password , Please try again" << endl;
                }
            }
            system("cls");
            cout << "Hello " << employeeLoggedIn->getName() << " what do you want ? " << endl;
            int employeeChoice;
            do {
                EmployeeManager::printEmployeeMenu();
                cout << "Enter your choice : ";
                cin >> employeeChoice;
                EmployeeManager::employeeOptions(employeeChoice);
                FileManager::updateClients();
                FileManager::updateEmployees();
                FileManager::updateAdmins();
            } while (employeeChoice != 9);

        }

            else if (choice == 3) {
            while (adminLoggedIn == NULL) {
                loginScreen(3);
                if (adminLoggedIn == NULL) {
                    cout << "Wrong ID or Password , Please try again" << endl;
                }
            }
            system("cls");
            cout << "Hello " << adminLoggedIn->getName() << " what do you want ? " << endl;
            int adminChoice;
            do {
                AdminManager::printAdminMenu();
                cout << "Enter your choice: ";
                cin >> adminChoice;
                AdminManager::adminOptions(adminChoice);
                if (adminChoice !=13 && adminChoice != 14) {
                FileManager::updateClients();
                FileManager::updateEmployees();
                FileManager::updateAdmins();
                }
            } while (adminChoice != 17);

        }

        else if (choice == 4) {
            logOut();
        }


        else {
            invalid(choice);
            cout << "Enter your choice again " << endl;
            goto loop;

        }

       /* FileManager::updateClients();
        FileManager::updateEmployees();
        FileManager::updateAdmins();
        */
    
        }

};

