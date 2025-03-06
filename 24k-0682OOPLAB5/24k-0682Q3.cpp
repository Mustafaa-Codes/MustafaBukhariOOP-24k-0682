/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 3 
*/
#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    std::string designation;

    Employee(std::string name, std::string designation) 
        : name(name), designation(designation) {}
};

class Project {
private:
    Employee* employees[10];
    int employeeCount;

public:
    std::string title;
    std::string deadline;

    Project(std::string title, std::string deadline) 
        : title(title), deadline(deadline), employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < 10) {
            employees[employeeCount++] = employee;
        }
    }

    void displayDetails() const {
        std::cout << "Project: " << title << "\nDeadline: " << deadline << "\nEmployees:\n";
        for (int i = 0; i < employeeCount; i++) {
            std::cout << "- " << employees[i]->name << " (" << employees[i]->designation << ")\n";
        }
        std::cout << "----------------------\n";
    }
};

int main() {
    Employee emp1("Alice", "Developer");
    Employee emp2("Bob", "Designer");
    Employee emp3("Charlie", "Manager");

    Project proj1("AI System", "2025-06-30");
    Project proj2("Web App", "2025-09-15");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp3);
    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp2);

    proj1.displayDetails();
    proj2.displayDetails();

    return 0;
}
