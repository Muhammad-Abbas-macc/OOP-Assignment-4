#include <iostream>
#include <string>

using namespace std;

// Simple BankAccount class with exception handling
class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor - throws exception if balance is negative
    BankAccount(string name, double initialBalance) {
        cout << "Constructor Creating account for: " << name << endl;

        // Check if balance is negative
        if (initialBalance < 0) {
            cout << "Constructor Error: Negative balance!" << endl;
            throw string("Cannot create account with negative balance!");
        }

        accountHolder = name;
        balance = initialBalance;
        cout << "Constructor Account created! Balance: " << balance << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Destructor Deleting account: " << accountHolder << endl;
    }

    // Withdraw money - throws exception if not enough money
    void withdraw(double amount) {
        cout << "Trying to withdraw : " << amount << endl;

        // Check if enough money available
        if (amount > balance) {
            cout << "Error: Not enough money!" << endl;
            throw string("Insufficient funds!");
        }

        balance = balance - amount;
        cout << "Successful! Withdraw $" << amount << endl;
        cout << "New balance: $" << balance << endl;
    }

    // Show account info
    void display() {
        cout << "--- Account Info ---" << endl;
        cout << "Name: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
        cout << "--------------------" << endl;
    }
};

int main() {
    cout << "=== Bank Account Demo ===" << endl;

    cout << "Valid Account\n";
    cout << "------------------------" << endl;

    BankAccount* acc1 = nullptr;

    try {
        acc1 = new BankAccount("John", 1000.0);  // Dynamic object creation using 'new'
        acc1->display();
        acc1->withdraw(200.0);  // This will work
        acc1->display();

        delete acc1;  // Clean up memory - IMPORTANT!
        acc1 = nullptr;
    }
    catch (string error) {
        cout << "Caught error: " << error << endl;
        if (acc1 != nullptr) {
            delete acc1;
        }
    }

    cout << endl;
    cout << "Negative Balance (ERROR)" << endl;
    cout << "------------------------------------" << endl;

    BankAccount* acc2 = nullptr;

    try {
        acc2 = new BankAccount("Jane", -500.0);  // Dynamic object creation - will throw exception!
        acc2->display();  // This line won't run
    }
    catch (string error) {
        cout << " Caught error: " << error << endl;
        cout << " Account was not created.\n" << endl;
    }

    cout << endl;
    cout << "Withdraw Too Much (ERROR)\n";
    cout << "-------------------------------------" << endl;

    BankAccount* acc3 = nullptr;

    try {
        acc3 = new BankAccount("Bob", 300.0);  // Dynamic object creation using 'new'
        acc3->display();

        acc3->withdraw(100.0);
        acc3->display();

        acc3->withdraw(500.0);  // This will throw exception!

        acc3->display();
    }
    catch (string error) {
        cout << "Caught error: " << error << endl;
        if (acc3 != nullptr) {
            acc3->display();
            delete acc3;  // Clean up memory - IMPORTANT!
        }
    }
    return 0;
}
