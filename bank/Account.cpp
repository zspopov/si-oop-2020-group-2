#include "Account.h"

double Account::getFunds() const {
    return this->funds;
}

string Account::getID() const {
    return this->id;
}

void Account::setID(const string& id) {
    this->id = id;
}

bool Account::isNegative(double amount) {
    return amount < 0;
}

bool Account::overflows(double funds, double amount) {
    return amount > funds;
}

Account::~Account() {
    //cout << "~Account()\n";
}