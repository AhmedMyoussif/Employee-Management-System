#pragma once
#include<iostream>
#include "Employee.h"
using namespace std;

class ExecutiveEmployee : public Employee {
private:
    double baseSalary;
    double bonusPercentage;
    string title;

public:
    ExecutiveEmployee(int id, string name, string phone, string email, string ssn, double baseSalary, double bonusPercentage, string title)
        : Employee(id, name, phone, email, ssn), baseSalary(baseSalary), bonusPercentage(bonusPercentage), title(title) {
    }

    void Print()  {
        Employee::Print();
        cout << "Title: " << title << endl;
        cout << "Base Salary: " << baseSalary << endl; 
        cout << "Bonus Percentage: " << bonusPercentage << "%" << endl;
    }
    double Pay() const override {
        return baseSalary + (baseSalary * bonusPercentage / 100);
    }
};
