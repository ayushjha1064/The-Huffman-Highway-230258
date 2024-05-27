#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Transaction {
private:
    string date;
    double amount;
public:
    Transaction(string d, double a) : date(d), amount(a) {}
    
    string getDate() const {
        return date;
    }

    double getAmount() const {
        return amount;
    }
};

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    string address;
    string accountType;
    double funds;
    vector<Transaction> transactionHistory;

public:
    Account(int num, string name, string addr, string type, double f)
        : accountNumber(num), accountHolderName(name), address(addr), accountType(type), funds(f) {}

    virtual ~Account() {}

    virtual void deposit(double amount) {
        funds += amount;
        transactionHistory.push_back(Transaction(getDate(), amount));
    }

    virtual bool withdraw(double amount) {
        if (funds >= amount) {
            funds -= amount;
            transactionHistory.push_back(Transaction(getDate(), -amount));
            return true;
        }
        cout << "Insufficient funds.\n";
        return false;
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder's Name: " << accountHolderName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Account Type: " << accountType << "\n";
        cout << "Funds: " << funds << "\n";
    }

    virtual void viewTransactionHistory() const {
        cout << "Transaction History:\n";
        for (const auto& transaction : transactionHistory) {
            cout << "Date: " << transaction.getDate() << ", Amount: " << transaction.getAmount() << "\n";
        }
    }

    string getDate() const {
        time_t now = time(nullptr);
        return ctime(&now);
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int num, string name, string addr, double f, double rate)
        : Account(num, name, addr, "Savings", f), interestRate(rate) {}

    void applyInterest() {
        funds += funds * interestRate;
    }

    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int num, string name, string addr, double f)
        : Account(num, name, addr, "Current", f) {}

    bool withdraw(double amount) override {
        return Account::withdraw(amount);
    }
};

int main() {
    SavingsAccount savings(1001, "Ayush Jha", "World street", 5000, 0.05);
    CurrentAccount current(2001, "Rahul", "Oak St", 3000);

    savings.deposit(1000);
    savings.withdraw(200);
    savings.applyInterest();

    current.deposit(500);
    current.withdraw(1000);

    savings.display();
    savings.viewTransactionHistory();

    current.display();
    current.viewTransactionHistory();

    return 0;
}
