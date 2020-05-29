#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    double funds;
    string id;
    bool isNegative(double amount); // check if deposited or withdrawn amount is negative
    bool overflows(double funds, double amount); // check if withdrawn amount is not higher than funds
public:
    double getFunds() const;
    string getID() const;
    void setID(const string& id);

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void printInfo() const = 0;
    
    ~Account();
};

#endif //_ACCOUNT_H