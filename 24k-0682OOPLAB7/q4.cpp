#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name, contactNumber, address;
    int age;
public:
    Person(string n, int a, string contact, string addr = "") 
        : name(n), age(a), contactNumber(contact), address(addr) {}
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber;
        if (!address.empty()) cout << "\nAddress: " << address;
        cout << endl;
    }
    virtual void updateInfo(string newContact, string newAddress = "") {
        contactNumber = newContact;
        if (!newAddress.empty()) address = newAddress;
    }
};

class Patient : public Person {
    string patientID, medicalHistory, doctorAssigned;
public:
    Patient(string n, int a, string contact, string id, string history, string doctor, string addr = "")
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "\nPatient ID: " << patientID << "\nMedical History: " << medicalHistory 
             << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    vector<string> patientsList;
public:
    Doctor(string n, int a, string contact, string spec, double fee, string addr = "")
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee) {}
    void addPatient(string patientName) { patientsList.push_back(patientName); }
    void displayInfo() override {
        Person::displayInfo();
        cout << "\nSpecialization: " << specialization << "\nConsultation Fee: $" << consultationFee << "\nPatients: ";
        for (const string& p : patientsList) cout << p << " ";
        cout << endl;
    }
};

class Nurse : public Person {
    string assignedWard, shiftTimings;
public:
    Nurse(string n, int a, string contact, string ward, string shift, string addr = "")
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "\nAssigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;
public:
    Administrator(string n, int a, string contact, string dept, double sal, string addr = "")
        : Person(n, a, contact, addr), department(dept), salary(sal) {}
    void updateInfo(string newContact, double newSalary, string newAddress = "") {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }
    void displayInfo() override {
        Person::displayInfo();
        cout << "\nDepartment: " << department << "\nSalary: $" << salary << endl;
    }
};

int main() {
    Patient patient("Alice", 30, "123-456-7890", "P001", "Diabetes", "Dr. Smith");
    Doctor doctor("Dr. Smith", 45, "987-654-3210", "Cardiology", 200.0);
    Nurse nurse("Emma", 28, "555-123-4567", "ICU", "Night");
    Administrator admin("John", 50, "777-888-9999", "HR", 60000.0);
    
    doctor.addPatient("Alice");
    
    patient.displayInfo();
    doctor.displayInfo();
    nurse.displayInfo();
    admin.displayInfo();
    
    return 0;
}
