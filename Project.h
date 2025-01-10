#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <vector>
#include "Budget.h"

class Employee; 

class Project {
private:
    int projectID;
    std::string location;
    Employee* manager;
    double currentCost;
    std::vector<Budget> budgetList;

public:
    Project(int projectID, std::string location, Employee* manager)
        : projectID(projectID), location(location), manager(manager), currentCost(0.0) {
    }

    void addBudget(const Budget& budget) {
        budgetList.push_back(budget);
    }

    double getTotalBudget() const {
        double total = 0.0;
        for (const auto& budget : budgetList) {
            total += budget.getValue();
        }
        return total;
    }

    void print() const {
        std::cout << "Project ID: " << projectID << std::endl;
        std::cout << "Location: " << location << std::endl;
        std::cout << "Current Cost: " << currentCost << std::endl;
        std::cout << "Total Budget: " << getTotalBudget() << std::endl;
    }
};

#endif // PROJECT_H