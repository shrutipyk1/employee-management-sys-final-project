#ifndef ATTENDANCE_H
#define ATTENDANCE_H

class Employee; //forward declarations
class Attendance {
private:
    float attendance = 0;
    int daysPresent;
    int total_workingdays;

    // daysPresent(daysPresent) {};

    // int getEmployeeId() const;
protected:

    Attendance();
    int getDaysPresent() const;
    void setDaysPresent();
    void setAttendance();
    int getAttendance();
    // void displayAttendance();

    friend Employee;

};

#endif // ATTENDANCE_H
