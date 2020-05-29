#ifndef _DEPOSIT_ACCOUNT_H
#define _DEPOSIT_ACCOUNT_H

#include "Account.h"

class DepositAccount : public Account {
private:
    double depositInterest;
public:
    DepositAccount();
    DepositAccount(double funds, double depositInterest, const string& id);

    double getDepositInterest() const;
    void setDepositInterest(double depositInterest); // if conditions are changed or after a period depositIntrest value should be changed

    void accumulateAtInterest();

    void deposit(double amount);
    void withdraw(double amount);
    void printInfo() const;
};

#endif //_DEPOSIT_ACCOUNT_H