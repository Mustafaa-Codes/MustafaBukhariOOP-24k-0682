/*
24k-0682
Syed Mustafa Bukhari
Lab 6 Question 3
*/
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(name), age(age) {}

    virtual void displayDetails() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\n";
    }
};

class Teacher : public Person {
protected:
    std::string subject;

public:
    Teacher(std::string name, int age, std::string subject) 
        : Person(name, age), subject(subject) {}

    void displayDetails() const override {
        std::cout << "Name: " << name << "\nAge: " << age 
                  << "\nSubject Expertise: " << subject << "\n";
    }
};

class Researcher : public Person {
protected:
    std::string researchArea;

public:
    Researcher(std::string name, int age, std::string researchArea) 
        : Person(name, age), researchArea(researchArea) {}

    void displayDetails() const override {
        std::cout << "Name: " << name << "\nAge: " << age 
                  << "\nResearch Area: " << researchArea << "\n";
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(std::string name, int age, std::string subject, std::string researchArea, int publications) 
        : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() const override {
        std::cout << "Name: " << name << "\nAge: " << age 
                  << "\nSubject Expertise: " << subject 
                  << "\nResearch Area: " << researchArea 
                  << "\nPublications: " << publications << "\n";
    }
};

int main() {
    Professor prof("Dr. John Smith", 50, "Computer Science", "Artificial Intelligence", 45);
    prof.displayDetails();

    return 0;
}
