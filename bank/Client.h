#ifndef _CLIENT_H
#define _CLIENT_H

#include <vector>
#include <string>
using namespace std;

#include "Account.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "DepositAccount.h"

class Client {
protected:
    string name;
    string address;
    vector<Account *> accounts; 
public:
    string getName() const;
    string getAddress() const;

    void setName(const string& name); // in case name should be changed
    void setAddress(const string& name); // in case name should be changed

    Account* getAccount(string id);
    void addAccount(Account * account);

    void printAccountsInfo() const;
    virtual void printInfo() const = 0;

    virtual ~Client();
};

#endif //_CLIENT_H