#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "StaffMember.h"

class HourlyEmployee : public StaffMember {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(int id, string name, string phone, string email, string ssn, double hourlyRate, double hoursWorked)
        : StaffMember(id, name, phone, email), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }

    void Print() const override {
        StaffMember::Print();
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
    }

    double Pay() const override {
        return hourlyRate * hoursWorked;
    }
};

#endif // HOURLYEMPLOYEE_H