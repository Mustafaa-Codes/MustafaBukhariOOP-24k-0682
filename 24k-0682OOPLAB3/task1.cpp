/*
24k-0682
Syed Mustafa Bukhari
OOP Lab 3
*/
#include <iostream>  
#include <string>  

using namespace std;  

class Wallet {  
private:  
    string ownerName;  
    double totalBalance;  
    string transactionHistory[10]; // Fixed size array for transaction history  
    int transactionCount; // To keep track of the number of transactions  

public:  
    // Constructor  
    Wallet(const string& name) : ownerName(name), totalBalance(0.0), transactionCount(0) {}  

    //  add money  
    void addMoney(double amount) {  
        if (amount > 0) {  
            totalBalance += amount;  
            if (transactionCount < 10) {  
                transactionHistory[transactionCount++] = "Added: " + to_string(amount);  
            }  
            cout << "Added " << amount << ". New balance: " << totalBalance << endl;  
        } else {  
            cout << "Invalid amount!" << endl;  
        }  
    }  

    //  spend  
    void spendMoney(double amount) {  
        if (amount > 0 && amount <= totalBalance) {  
            totalBalance -= amount;  
            if (transactionCount < 10) {  
                transactionHistory[transactionCount++] = "Spent: " + to_string(amount);  
            }  
            cout << "Spent " << amount << ". New balance: " << totalBalance << endl;  
        } else {  
            cout << "Invalid amount or insufficient balance!" << endl;  
        }  
    }  

    //  transaction history  
    void displayTransactionHistory() const {  
        cout << "Transaction History for " << ownerName << ":\n";  
        for (int i = 0; i < transactionCount; ++i) {  
            cout << transactionHistory[i] << endl;  
        }  
    }  
    
    // bal check 
    double checkBalance() const {  
        return totalBalance;  
    }  
};  

int main() {  
    Wallet saadsWallet("Saad");  

    saadsWallet.addMoney(100);  
    saadsWallet.spendMoney(30);  
    saadsWallet.addMoney(50);  
    saadsWallet.spendMoney(80);  
    saadsWallet.displayTransactionHistory();  

    return 0;  
}