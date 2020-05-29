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
    cerr << "Account not found!\n";
    return nullptr;
}

void Client::addAccount(Account * account) {
    this->accounts.push_back(account);
}

void Client::printAccountsInfo() const {
    for(auto account : this->accounts) {
        account->printInfo();
    }
}

Client::~Client() {
    for(Account * account : this->accounts) {
        delete account;
    } 
}