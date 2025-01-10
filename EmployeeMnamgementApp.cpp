#include <iostream>
#include <vector>
#include <memory>
#include <iomanip> 
#include <windows.h> 
#include "StaffMember.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "ExecutiveEmployee.h"
#include "Volunteer.h"
#include "Staff.h"

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayMenu() {
    cout << "\n\n\n";

    setColor(14); 
    cout << setw(50) << "=========================================\n";
    cout << setw(50) << "       Employee Management App           \n";
    cout << setw(50) << "=========================================\n";

    setColor(7); 
    cout << setw(50) << "1. Add Employee\n";
    cout << setw(50) << "2. Display All Employees\n";
    cout << setw(50) << "3. Calculate Payroll\n";
    cout << setw(50) << "4. Exit\n";

    setColor(14); 
    cout << setw(50) << "=========================================\n";

    setColor(7); 
    cout << setw(50) << "Enter your choice: ";
}

void addEmployee(Staff& staff) {
    int type;
    setColor(11);
    cout << "Select Employee Type:\n";
    cout << "1. Salaried Employee\n";
    cout << "2. Hourly Employee\n";
    cout << "3. Commission Employee\n";
    cout << "4. Executive Employee\n";
    cout << "5. Volunteer\n";
    cout << "Enter type: ";
    cin >> type;

    int id;
    string name, phone, email, ssn;
    setColor(7);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter SSN: ";
    getline(cin, ssn);

    if (type == 1) {
        double salary;
        cout << "Enter Salary: ";
        cin >> salary;
        staff.AddMember(make_unique<SalariedEmployee>(id, name, phone, email, ssn, salary));
    }
    else if (type == 2) {
        double hourlyRate, hoursWorked;
        cout << "Enter Hourly Rate: ";
        cin >> hourlyRate;
        cout << "Enter Hours Worked: ";
        cin >> hoursWorked;
        staff.AddMember(make_unique<HourlyEmployee>(id, name, phone, email, ssn, hourlyRate, hoursWorked));
    }
    else if (type == 3) {
        double salesAmount, commissionRate;
        cout << "Enter Sales Amount: ";
        cin >> salesAmount;
        cout << "Enter Commission Rate (%): ";
        cin >> commissionRate;
        staff.AddMember(make_unique<CommissionEmployee>(id, name, phone, email, ssn, salesAmount, commissionRate));
    }
    else if (type == 4) {
        double baseSalary, bonusPercentage;
        string title;
        cout << "Enter Base Salary: ";
        cin >> baseSalary;
        cout << "Enter Bonus Percentage (%): ";
        cin >> bonusPercentage;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        staff.AddMember(make_unique<ExecutiveEmployee>(id, name, phone, email, ssn, baseSalary, bonusPercentage, title));
    }
    else if (type == 5) {
        double amount;
        cout << "Enter Amount: ";
        cin >> amount;
        staff.AddMember(make_unique<Volunteer>(id, name, phone, email, ssn, amount));
    }
    else {
        setColor(12);
        cout << "Invalid type!\n";
        setColor(7);
        return;
    }
    setColor(10);
    cout << "Employee added successfully!\n";
    setColor(7);
}

int main() {
    Staff staff;
    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(staff);
            break;
        case 2:
            staff.ShowAll();
            break;
        case 3:
            staff.CalcPayroll();
            break;
        case 4:
            setColor(13);
            cout << "Exiting...\n";
            setColor(7); 
            running = false;
            break;
        default:
            setColor(12);
            cout << "Invalid choice! Please try again.\n";
            setColor(7); 
            break;
        }

        Sleep(1000);
    }

    return 0;
}