#pragma once
#include<iostream>
#include "Employee.h"
using namespace std;

class Volunteer : public Employee {
private:
    double amount;

public:
    Volunteer(int id, string name, string phone, string email, string socialSecurityNumber, double amount)
        : Employee(id, name, phone, email, socialSecurityNumber), amount(amount) {
    }

    void Print()  {
        Employee::Print(); 
        cout << "Amount: " << amount << endl; 
    }

    double Pay() const override {
        return 0;
    }
};
