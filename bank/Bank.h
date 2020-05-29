#ifndef _BANK_H
#define _BANK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "BankSystemUtilities.h"

class Bank{
private:
    string name;
    string address;
    vector<Client *> clients;
public:
    Bank(const string& name, const string& address);

    Client* getClient(const string& name);
    void addClient(Client * client);

    void printBankInfo() const;
    void printClientsInfo() const;
    void printInfo() const;

    ~Bank();
};


#endif //_BANK_H