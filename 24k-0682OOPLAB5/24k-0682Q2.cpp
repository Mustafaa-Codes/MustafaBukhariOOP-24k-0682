/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 2
*/
#include <iostream>
#include <cstring>

class Student {
private:
    int id;
    char* name;
    int* scores;
    int numScores;

public:
    Student(int id, const char* name, int* scores, int numScores)
        : id(id), numScores(numScores) {

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            this->scores[i] = scores[i];
        }
    }

    Student(const Student& other)
        : id(other.id), numScores(other.numScores) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }

    ~Student() {
        delete[] name;   
        delete[] scores;  
    }

    void display() const {
        std::cout << "Student ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < numScores; i++) {
            std::cout << scores[i] << " ";
        }
        std::cout << "\n----------------------\n";
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student student1(101, "Alice Johnson", scores1, 3);
    student1.display();

    Student student2 = student1;
    student2.display();

    return 0;
}
