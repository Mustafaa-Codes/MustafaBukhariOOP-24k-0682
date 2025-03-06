/*
24k-0682
Syed Mustafa Bukhari
Lab 6 Question 1  
*/
#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    float salary;

public:
    Employee(std::string name, float salary) : name(name), salary(salary) {}

    virtual void displayDetails() const {
        std::cout << "Name: " << name << "\nSalary: " << salary << "\n";
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(std::string name, float salary, float bonus) 
        : Employee(name, salary), bonus(bonus) {}

    void displayDetails() const override {
        std::cout << "Name: " << name << "\nSalary: " << salary 
                  << "\nBonus: " << bonus << "\n";
    }
};

int main() {
    Manager mgr("Alice Johnson", 75000, 10000);
    mgr.displayDetails();

    return 0;
}
