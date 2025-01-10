#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
using namespace std;

class StaffMember {
protected:
    int employeeID;
    string name, phone, email;

public:
    StaffMember(int employeeID = 0, string name = "", string phone = "", string email = "")
        : employeeID(employeeID), name(name), phone(phone), email(email) {
    }

    void setID(int employeeID) {
        this->employeeID = employeeID;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setEmail(string email) {
        this->email = email;
    }

    int getID() const {
        return employeeID;
    }
    string getName() const {
        return name;
    }
    string getPhone() const {
        return phone;
    }
    string getEmail() const {
        return email;
    }

    virtual void Print() const {
        cout << "Name: " << name << endl
            << "ID: " << employeeID << endl
            << "Phone: " << phone << endl
            << "Email: " << email << endl;
    }

    virtual double Pay() const = 0; 

    virtual ~StaffMember() = default;
};

#endif // STAFFMEMBER_H