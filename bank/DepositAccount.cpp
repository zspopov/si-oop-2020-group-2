#include "DepositAccount.h"

DepositAccount::DepositAccount() {
    this->funds = -1;
    this->depositInterest = 0.10;
    this->id = "uninitialized";
}

DepositAccount::DepositAccount(double funds, double depositInterest, const string& id){
    this->funds = funds;
    this->depositInterest = depositInterest;
    this->id = id;
}

double DepositAccount::getDepositInterest() const {
    return this->depositInterest;
}

void DepositAccount::setDepositInterest(double depositInterest) {
    this->depositInterest = depositInterest;
}

void DepositAccount::accumulateAtInterest() {
    this->funds += this->funds + this->funds * this->depositInterest;
}

void DepositAccount::deposit(double amount) {
    if(isNegative(amount)) {
        cerr << "Deposited amount is negative\n";
        return;
    }
    this->funds += amount;
    cout << "Successfully deposited " << amount << "!\n";
}

void DepositAccount::withdraw(double amount) {
    if(isNegative(amount)) {
        cerr << "Withdrawn amount is negative\n";
        return;
    }
    if(overflows(this->funds, amount)) {
        cerr << "Cannot withdraw amount higher than funds\n";
        return;
    }
    this->funds -= amount;
    cout << "Successfully withdrawn amount " << amount << "!\n";
}

void DepositAccount::printInfo() const {
    cout << "ID: " << this->id << " funds: " << this->funds << "; Deposit interest: " << this->depositInterest << "!\n";
}