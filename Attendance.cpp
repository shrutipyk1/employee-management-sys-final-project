
#include "Attendance.h"
#include <iostream>
using namespace std;

Attendance::Attendance() {

}


void Attendance::setDaysPresent() {
    int d;
    cout << "Enter the days the employee was present: ";
    cin >> d;
    daysPresent = d;
}

int Attendance::getDaysPresent() const {
    return daysPresent;
}
void Attendance::setAttendance() {
    cout << "TOTAL WORKING DAYS: ";
    cin >> total_workingdays;

    attendance = (float)daysPresent / total_workingdays * 100;

}

int Attendance::getAttendance() {
    return attendance;
}