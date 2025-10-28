#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accNumber;
    char accType;   // 's' = savings, 'c' = current
    double balance;

public:
    // A. To initialize (input from user)
    void initialize() {
        cout << "\nEnter Name of Depositor: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cout << "Enter Account Type (s for savings, c for current): ";
        cin >> accType;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // B. To deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    // C. For withdrawal (only if balance after withdrawal >= 10000)
    void withdraw(double amount) {
        if (balance - amount >= 10000) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal denied! Balance must remain >= 10000." << endl;
        }
    }

    // D. To display data members
    void display() {
        cout << "\nAccount Holder: " << name;
        cout << "\nAccount Number: " << accNumber;
        cout << "\nAccount Type  : " << (accType == 's' ? "Savings" : "Current");
        cout << "\nBalance       : " << balance << endl;
    }
};

int main() {
    const int SIZE = 10;
    BankAccount customers[SIZE];


    for (int i = 0; i < SIZE; i++) {
        cout << "\n--- Enter details for Customer " << i + 1 << " ---";
        customers[i].initialize();
    }

    cout << "\n--- All Customer Details ---";
    for (int i = 0; i < SIZE; i++) {
        customers[i].display();
    }
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";
    return 0;
}
