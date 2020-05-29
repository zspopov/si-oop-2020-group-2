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

void RegularClient::setTelephoneNumber(const string& telephoneNumber) {
    this->telephoneNumber = telephoneNumber;
}

void RegularClient::printInfo() const {
    cout << "Name: " << this->name << "; address: " << this->address << "; telephone number: " << this->telephoneNumber << "\n";
    cout << "Accounts info:\n";
    this->printAccountsInfo();
}