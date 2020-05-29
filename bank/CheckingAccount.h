#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount();
    CheckingAccount(double funds, const string& id);

    void deposit(double amount);
    void withdraw(double amount);
    void printInfo() const;
};

#endif //_CHECKING_ACCOUNT_H