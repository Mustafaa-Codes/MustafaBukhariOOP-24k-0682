#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}

    virtual void calculateGrade() const = 0;
    virtual void displayInfo() const = 0;

    virtual ~Course() {}
};

// Derived Class: LectureCourse
class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr) : Course(code, cr) {}

    void calculateGrade() const override {
        cout << "Lecture Course Grade Calculation for " << courseCode << ":\n";
        cout << "- 50% Midterm, 50% Final Exam\n";
        cout << "- Final Grade: 85%\n";  // Example grade
    }

    void displayInfo() const override {
        cout << "Lecture Course: " << courseCode << " | Credits: " << credits << endl;
    }
};

// Derived Class: LabCourse
class LabCourse : public Course {
public:
    LabCourse(string code, int cr) : Course(code, cr) {}

    void calculateGrade() const override {
        cout << "Lab Course Grade Calculation for " << courseCode << ":\n";
        cout << "- 40% Lab Assignments, 60% Final Project\n";
        cout << "- Final Grade: 92%\n";  // Example grade
    }

    void displayInfo() const override {
        cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
    }
};

int main() {
    Course* c1 = new LectureCourse("CS101", 3);
    Course* c2 = new LabCourse("CS101L", 1);

    cout << "\n=== Lecture Course ===\n";
    c1->displayInfo();
    c1->calculateGrade();

    cout << "\n=== Lab Course ===\n";
    c2->displayInfo();
    c2->calculateGrade();

    delete c1;
    delete c2;

    return 0;
}
