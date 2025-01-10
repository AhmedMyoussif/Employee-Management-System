#ifndef BUDGET_H
#define BUDGET_H

class Budget {
private:
    int id;
    double value;

public:
    Budget(int id, double value) : id(id), value(value) {}

    void increaseBudget(double amount) {
        value += amount;
    }

    double getValue() const {
        return value;
    }

    void setValue(double newValue) {
        value = newValue;
    }

    int getId() const {
        return id;
    }

    void setId(int newId) {
        id = newId;
    }
};

#endif // BUDGET_H