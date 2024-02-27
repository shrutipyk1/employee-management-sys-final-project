#include "Employee.h"

#include <iostream>
using namespace std;

void Employee::display() const
{
    cout << endl;
    cout << endl;
    cout << "Name : " << name << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Base Salary: $" << baseSalary << endl;

}

void Employee::setAtt() {
    eAttendance = new Attendance();
    eAttendance->setDaysPresent();
    eAttendance->setAttendance();
}

int Employee::getEAtt() {
    return eAttendance->getAttendance();
}

int Employee::getEmployeeId()
{
    return employeeId;
}

void Employee::setBaseSalary(double salary) {
    baseSalary = salary;
}
//-------------------------------------------------------------------------------------------------------------//

double RegularEmployee::calculateSalary() const {
    return baseSalary + perks + allowances;
}


void RegularEmployee::display() const {
    Employee::display();
    cout << "Perks: $" << perks << ", Allowances: $" << allowances << endl;
}

//--------------------------------------------------------------------------------------------------------------//

double ContractEmployee::calculateSalary() const {
    return baseSalary + incentives;
}

void ContractEmployee::display() const {
    Employee::display();
    cout << "Incentives: $" << incentives << endl;
}
//-------------------------------------------------------------------------------------------------------------------// 
//-------------------------------------------------------------------------------------------------------------------------//
//functions to update employee details 

void Employee::setupdatedNewname(string name)
{
    newname = name;
}

void Employee::setupdatesperks(double perks)
{
    newperks = perks;
}

void Employee::setupdatesallowances(double allowances)
{
    newallowances = allowances;
}
