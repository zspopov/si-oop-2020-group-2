#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
    this->funds = -1;
    this->id = "uninitialized";
}

CheckingAccount::CheckingAccount(double funds, const string& id) {
    this->funds = funds;
    this->id = id;
}

void CheckingAccount::deposit(double amount) {
    if(isNegative(amount)) {
        cerr << "Deposited amount is negative\n";
        return;
    }
    this->funds += amount;
    cout << "Successfully deposited " << amount << "!\n";
}

void CheckingAccount::withdraw(double amount) {
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

void CheckingAccount::printInfo() const {
    cout << "ID: " << this->id << " funds: " << this->funds << "!\n";
}

// CheckingAccount::~CheckingAccount() {
//     cout << "~CheckingAccount()\n";
// }