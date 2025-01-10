#pragma once
#include <iostream>
#include "StaffMember.h"
using namespace std;

class Employee : public StaffMember {
protected:
    string socialSecurityNumber;

public:
    Employee(int id, string name, string phone, string email, string ssn)
        : StaffMember(id, name, phone, email), socialSecurityNumber(ssn) {
    }

    virtual double Pay() const = 0;

    void Print() {
        StaffMember::Print();
        cout << "Social Security Number: " << socialSecurityNumber << endl;
    }
};
