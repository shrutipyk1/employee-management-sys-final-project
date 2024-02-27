#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include "Employee.h"
#include <vector>
using namespace std;
class PayrollSystem {
private:

    vector<Employee*> employees;


public:
    /* It is responsible for deallocating memory held by dynamically allocated Employee objects in the employees vector.
         It iterates through the employees vector and deletes each Employee object.*/


    ~PayrollSystem() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }

    void addEmployee(Employee* emp);

    void addAttendanceRecord(int employeeId, int daysPresent);

    /*This function displays details of all employees along with their attendance records.
        It sorts the employees vector based on the salary of each employee in descending order using a lambda functionand sort.
        It then iterates through the sorted employees vectorand displays each employee's details.
        For each employee, it searches for their attendance record in the attendanceRecords vectorand displays the
        number of days present if found, otherwise, it indicates that attendance is not recorded.*/
    void displayAllEmployees() const;



    /*The declaration pair<Employee*, int> searchEmployeeById(int id) const;
    indicates a function named searchEmployeeById within a class.
    It takes an integer parameter id and returns a pair consisting of a pointer to an Employee object and an integer.*/
    pair<Employee*, int> searchEmployeeById(int id) const;

    /*This function deletes an employee record by their ID.
        It takes an employee ID as an argumentand removes the corresponding Employee object from the employees vector.
        It uses the remove_if algorithm along with a lambda function to find the employee with the provided IDand remove it from the vector.
        If an employee is foundand removed, it also deallocates the memory of the corresponding Employee object.*/
    void deleteEmployee(int id);


    /*This function updates the base salary of an employee by their ID.
        It takes an employee IDand the new base salary as arguments.
        It searches for the employee with the provided ID using the searchEmployeeById function.
        If the employee is found, it updates the base salary of the employee using the setBaseSalary function.
        If the employee is not found, it prints a message indicating that the employee with the given ID was not found.*/

    void updateEmployeeData(int id);



};

#endif