#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount();
    CheckingAccount(double funds, const string& id);

    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void printInfo() const override;

    //~CheckingAccount();
};

#endif //_CHECKING_ACCOUNT_H