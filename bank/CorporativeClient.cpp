#include "CorporativeClient.h"

CorporativeClient::CorporativeClient() {
    this->name = "unknown";
    this->address = "unknown";
}

CorporativeClient::CorporativeClient(const string& name, const string& address) {
    this->name = name;
    this->address = address;
}

CorporativeClient::CorporativeClient(const CorporativeClient& rhs) {
    this->name = rhs.name;
    this->address = rhs.address;
    for(int i = 0; i < rhs.accounts.size(); i++) {
        this->addAccount(rhs.accounts[i]);
    }
}

CorporativeClient& CorporativeClient::operator=(const CorporativeClient& rhs) {
    if(this != &rhs){ 
        this->name = rhs.name;
        this->address = rhs.address;
        this->accounts.clear();
        for(int i = 0; i < rhs.accounts.size(); i++) {
            this->addAccount(rhs.accounts[i]);
        }
    }
    return *this;
    
}


void CorporativeClient::printInfo() const {
    cout << "Name: " << this->name << "; address:" << this->address << ";\n";
    cout << "Accounts info: ";
    this->printAccountsInfo();
}

// CorporativeClient::~CorporativeClient() {
//     cout << "CorporativeClient()\n";
// }