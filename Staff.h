#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "StaffMember.h"
using namespace std;

class Staff {
private:
    vector<unique_ptr<StaffMember>> StaffList;

public:
    void AddMember(unique_ptr<StaffMember> member) {
        StaffList.push_back(std::move(member));
    }

    void DeleteMember(int EmployeeID) {
        for (auto it = StaffList.begin(); it != StaffList.end(); ++it) {
            if ((*it)->getID() == EmployeeID) {
                StaffList.erase(it);
                break;
            }
        }
    }

    void CalcPayroll() const {
        double totalPayroll = 0.0;
        cout << "=====================================\n";
        cout << "           Payroll Summary           \n";
        cout << "=====================================\n";
        for (const auto& member : StaffList) {
            double pay = member->Pay();
            cout << member->getName() << ": $" << pay << endl;
            totalPayroll += pay;
        }
        cout << "-------------------------------------\n";
        cout << "Total Payroll: $" << totalPayroll << endl;
    }

    void ShowAll() const {
        cout << "=====================================\n";
        cout << "           Staff Members List        \n";
        cout << "=====================================\n";
        for (const auto& member : StaffList) {
            member->Print();
            cout << "-------------------------------------\n";
        }
    }
};