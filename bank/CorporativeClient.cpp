#include "CorporativeClient.h"

CorporativeClient::CorporativeClient() {
    this->name = "unknown";
    this->address = "unknown";
}

CorporativeClient::CorporativeClient(const string& name, const string& address) {
    this->name = name;
    this->address = address;
}

void CorporativeClient::printInfo() const {
    cout << "Name: " << this->name << "; address:" << this->address << ";\n";
    cout << "Accounts info: ";
    this->printAccountsInfo();
}