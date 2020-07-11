#ifndef _CREDIT_ACCOUNT_H
#define _CREDIT_ACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
private:
    double creditInterest;
    double due; //what we owe to the bank
public:
    CreditAccount();
    CreditAccount(double funds, double creditInteres, const string& id); // these parameters are result of negotiation between the bank and the client

    double getCreditInterest() const;
    void setCreditInterest(double creditInterest); // if conditions are changed or after a period creditIntrest value should be changed

    double getDue() const; 
    //no need to set due

    void deposit(double amount);
    void withdraw(double amount);
    void printInfo() const;

    ~CreditAccount();
};

#endif //_CREDIT_ACCOUNT_