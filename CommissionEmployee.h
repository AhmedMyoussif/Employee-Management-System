#pragma once
#include<iostream>
#include "Employee.h"
using namespace std;

class CommissionEmployee : public Employee {
private:
    double salesAmount;  
    double commissionRate;

public:
    CommissionEmployee(int id, string name, string phone, string email, string ssn, double salesAmount, double commissionRate)
        : Employee(id, name, phone, email, ssn), salesAmount(salesAmount), commissionRate(commissionRate) {
    }

    void Print()  {
        Employee::Print();
        cout << "Sales Amount: " << salesAmount << endl;
        cout << "Commission Rate: " << commissionRate << "%" << endl;
    }

    double Pay() const override {
        return salesAmount * commissionRate / 100;
    }
};
