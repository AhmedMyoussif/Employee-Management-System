#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "StaffMember.h"

class SalariedEmployee : public StaffMember {
private:
    double salary;

public:
    SalariedEmployee(int id, string name, string phone, string email, string ssn, double salary)
        : StaffMember(id, name, phone, email), salary(salary) {
    }

    void Print() const override {
        StaffMember::Print();
        cout << "Salary: " << salary << endl;
    }

    double Pay() const override {
        return salary;
    }
};

#endif // SALARIEDEMPLOYEE_H