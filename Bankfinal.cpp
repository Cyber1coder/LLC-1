#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor for Account class
    Account(string accoHolder, string accNum, double initialBalance) {
        accountHolder = accoHolder;
        accountNumber = accNum;
        balance = initialBalance;
    }
        //Print account details
    void printStatement() {
    	cout<<"Enter Your Account Number: "<<endl;
    	cin>>accountNumber;
        cout << "AccountHolder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    
};

class SavingsAccount : public Account {
public:
    // Constructor for SavingsAccount (no interest rate)
    SavingsAccount(string accoHolder, string accNum, double initialBalance)
        : Account(accoHolder, accNum, initialBalance) {}

   
    void printSavingsStatement() {
        printStatement();
        cout << "Savings Account" << endl;
    }
};

class CheckingAccount : public Account {
public:
    // Constructor for CheckingAccount
    CheckingAccount(string accoHolder, string accNum, double initialBalance)
        : Account(accoHolder, accNum, initialBalance) {}

    // Print Checking account statement
    void printCheckingStatement() {
        printStatement();
        cout << "Checking Account" << endl;
    }
};

int main() {
    // Creating SavingsAccount and CheckingAccount objects
    SavingsAccount savings("Ankita", "S12345", 1000.0);   
    CheckingAccount checking("Ankita", "C12345", 500.0);
	 savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.printSavingsStatement();

    checking.deposit(300.0);
    checking.withdraw(100.0);
    checking.printCheckingStatement();
    
    Account a;
    a.printStatement();

    return 0;
}

