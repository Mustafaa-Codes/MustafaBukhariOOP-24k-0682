/*
24k-0682
Syed Mustafa Bukhari
OOP Lab 3
*/
#include <iostream>  
#include <string>  

using namespace std;  

class FitnessTracker {  
private:  
    string userName;  
    int dailyStepGoal;  
    int stepsTaken;  
    double caloriesBurned;  

public:  
    // Constructor  
    FitnessTracker(const string& name, int stepGoal)   
        : userName(name), dailyStepGoal(stepGoal), stepsTaken(0), caloriesBurned(0.0) {}  

    //  log steps  
    void logSteps(int steps) {  
        if (steps > 0) {  
            stepsTaken += steps;  
            caloriesBurned += steps * 0.05; //  0.05 calories burned per step  
            cout << steps << " steps logged. Total steps: " << stepsTaken << endl;  
        } else {  
            cout << "Invalid step count!" << endl;  
        }  
    }  

    // display progress  
    void displayProgress() const {  
        cout << "Progress for " << userName << ":\n";  
        cout << "Steps Taken: " << stepsTaken << endl;  
        cout << "Calories Burned: " << caloriesBurned << endl;  
        cout << "Daily Step Goal: " << dailyStepGoal << endl;  
        
        if (stepsTaken >= dailyStepGoal) {  
            cout << "Congratulations! You've met your daily step goal!" << endl;  
        } else {  
            cout << "Keep going! You need " << (dailyStepGoal - stepsTaken) << " more steps to reach your goal." << endl;  
        }  
    }  
    
    // check if goal is met  
    bool checkGoalMet() const {  
        return stepsTaken >= dailyStepGoal;  
    }  
};  

int main() {  
    FitnessTracker laibasTracker("Laiba", 10000);  

    laibasTracker.logSteps(3000);  
    laibasTracker.logSteps(5000);  
    laibasTracker.logSteps(3000);  

    laibasTracker.displayProgress();  

    return 0;  
}