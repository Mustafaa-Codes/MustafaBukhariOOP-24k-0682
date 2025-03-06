/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 5
*/
#include <iostream>
#include <string>

class Doctor {
public:
    std::string name;
    std::string specialization;
    int experience;

    Doctor(std::string name, std::string specialization, int experience)
        : name(name), specialization(specialization), experience(experience) {}
};

class Hospital {
private:
    std::string hospitalName;
    Doctor* doctors[10];
    int doctorCount;

public:
    Hospital(std::string name) : hospitalName(name), doctorCount(0) {}

    void addDoctor(Doctor* doctor) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = doctor;
        }
    }

    void displayDetails() const {
        std::cout << "Hospital: " << hospitalName << "\nDoctors:\n";
        for (int i = 0; i < doctorCount; i++) {
            std::cout << "- " << doctors[i]->name << " (" << doctors[i]->specialization 
                      << ", " << doctors[i]->experience << " years experience)\n";
        }
        std::cout << "----------------------\n";
    }
};

int main() {
    Doctor doc1("Dr. Alice", "Cardiologist", 15);
    Doctor doc2("Dr. Bob", "Neurologist", 10);
    Doctor doc3("Dr. Charlie", "Orthopedic", 8);

    Hospital hospital1("City General Hospital");
    Hospital hospital2("Downtown Medical Center");

    hospital1.addDoctor(&doc1);
    hospital1.addDoctor(&doc2);
    hospital2.addDoctor(&doc3);
    hospital2.addDoctor(&doc1);

    hospital1.displayDetails();
    hospital2.displayDetails();

    return 0;
}
