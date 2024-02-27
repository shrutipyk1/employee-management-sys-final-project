#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include<string>
#include "Employee.h"
#include "Attendance.h"
#include "Payrollsystem.h"
using namespace std;

void displayMenu() {
    cout << "------------------------------------------------------------";
    cout << "\nPayroll Processing System Menu:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Display all employees' records" << endl;
    cout << "3. Search employee by ID and display details" << endl;
    cout << "4. Update employee data" << endl;
    cout << "5. Delete employee by ID" << endl;
    cout << "6. Exit" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    PayrollSystem payrollSystem;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "Enter type of employee (1 for Regular, 2 for Contract): ";
            cin >> type;
            cout << "------------------------------------------------------------" << endl;

            string name;
            int employeeId;
            double baseSalary;

            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter employee ID: ";
            cin >> employeeId;

            cout << "Enter base salary: ";
            cin >> baseSalary;

            if (type == 1) {
                double perks, allowances;
                cout << "Enter perks: ";
                cin >> perks;

                cout << "Enter allowances: ";
                cin >> allowances;

                payrollSystem.addEmployee(new RegularEmployee(name, employeeId, baseSalary, perks, allowances));
            }
            else if (type == 2) {
                double incentives;
                cout << "Enter incentives: ";
                cin >> incentives;

                payrollSystem.addEmployee(new ContractEmployee(name, employeeId, baseSalary, incentives));
            }
            else {
                cout << "Invalid employee type." << endl;
            }

            cout << "------------------------------------------------------------" << endl;
            break;

        }
        case 2:
            payrollSystem.displayAllEmployees();
            break;
        case 3: {
            int id;
            cout << "Enter employee ID to search: ";
            cin >> id;
            {
                pair<Employee*, int> result = payrollSystem.searchEmployeeById(id);
                Employee* emp = result.first;
                int attendance = result.second;
                if (emp != nullptr) {
                    emp->display();
                    cout << "Attendance: " << attendance << "%" << endl;
                }
                else {
                    cout << "Employee with ID " << id << " not found." << endl;
                }
            }
            cout << "------------------------------------------------------------" << endl;
            break;
        }

        case 4: {
            int id;
       
            cout << "Enter employee ID to update data: ";
            cin >> id;
          

            payrollSystem.updateEmployeeData(id);
            cout << "------------------------------------------------------------" << endl;
            break;

        }
        case 5: {
            int id;
            cout << "Enter employee ID to delete: ";
            cin >> id;
            payrollSystem.deleteEmployee(id);
            cout << "------------------------------------------------------------" << endl;
            break;

        }
        case 6:
            cout << "Exiting..." << endl;
            cout << "------------------------------------------------------------" << endl;
            break;
 


        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << "------------------------------------------------------------";
        }
    } while (choice != 6);

    return 0;
}