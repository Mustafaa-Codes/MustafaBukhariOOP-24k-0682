/*
24k-0682
Syed Mustafa Bukhari
Lab 6 Question 4 
*/
#include <iostream>

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNumber, float bal) : accountNumber(accNumber), balance(bal) {}

    virtual void displayDetails() const {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << "\n";
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNumber, float bal, float interestRate) 
        : Account(accNumber, bal), interestRate(interestRate) {}

    void displayDetails() const override {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance 
                  << "\nInterest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNumber, float bal, float overdraftLimit) 
        : Account(accNumber, bal), overdraftLimit(overdraftLimit) {}

    void displayDetails() const override {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance 
                  << "\nOverdraft Limit: $" << overdraftLimit << "\n";
    }
};

int main() {
    SavingsAccount savings(1001, 5000.0, 3.5);
    CheckingAccount checking(2001, 1500.0, 1000.0);

    std::cout << "Savings Account Details:\n";
    savings.displayDetails();
    std::cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
