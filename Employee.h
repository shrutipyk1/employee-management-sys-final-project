#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Attendance.h"
#include "Payrollsystem.h"
#include <string>
#include<cstring>
#include<iostream>
using namespace std;

class Employee;    //forward declaration of classess 
class payrollSystem;


// Employee base class
class Employee {
protected:
    string name;
    int employeeId;
    double baseSalary;

    //to update a new record add another vaibles 
    int id;
    string newname;
    double newBaseSalary;
    double newperks;
    double newallowances;

    //object is created of attandance class 
    Attendance* eAttendance = NULL;

public:
    Employee(string name, int employeeId, double baseSalary) : name(name), employeeId(employeeId), baseSalary(baseSalary), eAttendance(new Attendance) {}

    virtual ~Employee() {};

    virtual double calculateSalary() const = 0;

    virtual void display() const;

    int getEmployeeId();

    void setBaseSalary(double salary);
    void setAtt();
    int getEAtt();

    //functions for update the new data---let us define in source file 
    void setupdatedNewname(string name);
    void setupdatesperks(double perks);
    void setupdatesallowances(double allowances);


    friend payrollSystem;
};
// Regular Employee derived class
class RegularEmployee : public Employee {
private:
    double perks;
    double allowances;

public:
    RegularEmployee(string name, int employeeId, double baseSalary, double perks, double allowances) : Employee(name, employeeId, baseSalary), perks(perks), allowances(allowances) {}

    double calculateSalary() const;

    void display() const;
};

//Derived class for Contract Employees


class ContractEmployee : public Employee {
private:
    double incentives;

public:
    ContractEmployee(string name, int employeeId, double baseSalary, double incentives) : Employee(name, employeeId, baseSalary), incentives(incentives) {}

    double calculateSalary() const override;

    void display() const override;
};

#endif 