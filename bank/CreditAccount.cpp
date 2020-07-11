#include "CreditAccount.h"

CreditAccount::CreditAccount() {
    this->funds = -1;
    this->creditInterest = 0.10;
    this->due = 0;
    this->id = "uninitialized";
}

CreditAccount::CreditAccount(double funds, double creditInterest, const string& id) {
    this->funds = funds;
    this->creditInterest = creditInterest;
    this->due = 0;
    this->id = id;
}

double CreditAccount::getCreditInterest() const {
    return this->creditInterest;
}

void CreditAccount::setCreditInterest(double creditInterest) {
    this->creditInterest = creditInterest;
} 

double CreditAccount::getDue() const {
    return this->due;
}

void CreditAccount::deposit(double amount) {
    if(isNegative(amount)) {
        throw "Deposited amount is negative\n";
    }
    this->due -= amount;
    cout << "Successfully deposited " << amount << "!\n";
}

void CreditAccount::withdraw(double amount) {
    if(isNegative(amount)) {
        cerr << "Withdrawn amount is negative\n";
        return;
    }
    if(overflows(this->funds, amount)) {
        cerr << "Cannot withdraw amount higher than funds\n";
        return;
    }
    this->funds -= amount;
    this->due += amount + amount * this->creditInterest;
    cout << "Successfully withdrawn amount " << amount << "!\n";
}

void CreditAccount::printInfo() const {
    cout << "ID: " << this-> id <<  "funds: " << this->funds << "; due: " << this->due << "; intrestRate: " << this->creditInterest << "\n";
}

CreditAccount::~CreditAccount() {
    cout << "~CreditAccount()\n";
}