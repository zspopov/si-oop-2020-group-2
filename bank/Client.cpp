#include "Client.h"

string Client::getName() const {
    return this->name;
}

string Client::getAddress() const {
    return this->address;
}

void Client::setName(const string& name) {
    this->name = name;
}

void Client::setAddress(const string& address) {
    this->address = address;
}

Account* Client::getAccount(string id) {
    for(int i = 0; i < this->accounts.size(); i++) {
        if(accounts[i]->getID() == id) {
            return accounts[i];
        }
    }
    throw "account not found!\n";
}

void Client::addAccount(Account * account) {
    CheckingAccount * checkingAccount = dynamic_cast<CheckingAccount *>(account); 
    CreditAccount * creditAccount = dynamic_cast<CreditAccount *>(account); 
    DepositAccount * depositAccount = dynamic_cast<DepositAccount *>(account);
    if(checkingAccount) {
        this->accounts.push_back(new CheckingAccount(*checkingAccount));
    }
    if(creditAccount) {
        this->accounts.push_back(new CreditAccount(*creditAccount));
    }
    if(depositAccount) {
        this->accounts.push_back(new DepositAccount(*depositAccount));
    }
}

void Client::printAccountsInfo() const {
    for(auto account : this->accounts) {
        account->printInfo();
    }
}

Client::~Client() {
    cout << "~Client()\n";
    for(Account * account : this->accounts) {
        delete account;
    } 
}