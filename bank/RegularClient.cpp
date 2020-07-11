#include "RegularClient.h"

RegularClient::RegularClient() {
    this->name = "unknown";
    this->address = "unknown";
    this->telephoneNumber = "unknown";
}

RegularClient::RegularClient(const string& name, const string& address, const string& telephoneNumber) {
    this->name = name;
    this->address = address;
    this->telephoneNumber = telephoneNumber;
}

RegularClient::RegularClient(const RegularClient& rhs) {
    this->name = rhs.name;
    this->address = rhs.address;
    this->telephoneNumber = rhs.telephoneNumber;
    for(int i = 0; i < rhs.accounts.size(); i++) {
        this->addAccount(rhs.accounts[i]);
    }
}

RegularClient& RegularClient::operator=(const RegularClient& rhs) {
    if(this != &rhs){
        this->name = rhs.name;
        this->address = rhs.address;
        this->telephoneNumber = rhs.telephoneNumber;
        for(auto * account : this->accounts) {
            delete account;
        }
        this->accounts.clear();
        for(int i = 0; i < rhs.accounts.size(); i++) {
            this->addAccount(rhs.accounts[i]);
        }
    }
    return *this;
}

void RegularClient::setTelephoneNumber(const string& telephoneNumber) {
    this->telephoneNumber = telephoneNumber;
}

void RegularClient::printInfo() const {
    cout << "Name: " << this->name << "; address: " << this->address << "; telephone number: " << this->telephoneNumber << "\n";
    cout << "Accounts info:\n";
    this->printAccountsInfo();
}

RegularClient::~RegularClient() {
    cout << "~RegularClient()\n";
}