/* Q2.Create a C++ program for a simple banking system.You need to implement a class called
1. BankAccount with the following data members:
2. AccountNumber(int):
Number(int): The account number of the bank account.
3. accountHolderName(string): The name of the account holder.
4. balance (double):The current balance in the account.
The BankAccount class should have the following member functions:
1. Getter and Setter Methods:
2. Deposit method: A method that allows the user to deposit money into the account.
It should take an amount as a parameter and update the balance accordingly.
3. withdraw method: A method that allows the user to withdraw
withdraw money from the
account. It should take an amount as a parameter and update the balance. Make sure to
check if there is sufficient balance before allowing the withdrawal.
4. displayAccountDetails
ccountDetails method: A method that displays the account details (
account number, account holder name, and balance).
Now, create a menu-driven program in the `main` function that allows the user to perform
the following operations:
1. Deposit money into an existing account.
2. Withdraw money from an existing
existin account.
3. Display the account details.
4. Exit the program. */

#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    void setAccountHolderName(const string& name) { accountHolderName = name; }
    void setBalance(double bal) { balance = bal; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited Rs " << amount << endl;
        } else {
            cout << "Invalid deposit amount. " << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Successfully withdrew Rs" << amount << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void displayAccountDetails() const {
        if (accountNumber == 0) {
            cout << "No account details available." << endl;
            return;
        }
        cout << "\n--- A/C Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: Rs" << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    account.setAccountNumber(123456);
    account.setAccountHolderName("Ritik Garhewal");
    account.setBalance(10000);

    do {
        cout << "\n--- Bank Menu ---" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account Details : " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";

        while (!(cin >> choice)) {
            cout << "Please enter a number: ";
            cin.clear();
            while (cin.get() != '\n');
        }

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: Rs";
                while (!(cin >> amount)) {
                    cout << " Please enter a valid number: Rs";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: Rs";
                while (!(cin >> amount)) {
                    cout << "Invalid input.";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                account.withdraw(amount);
                break;
            case 3:
                account.displayAccountDetails();
                break;
            case 4:
                cout << "Bye Bye TATA Gaya" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
