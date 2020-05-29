#include "Bank.h"

Bank::Bank(const string& name, const string& address) {
    this->name = name;
    this->address = address;
}

Client * Bank::getClient(const string& name) {
    for(auto client : this->clients) {
        if(client->getName() == name) {
            return client;
        }
    }
    cerr << "Client not found!\n";
    return nullptr;
}

void Bank::addClient(Client * client) {
    this->clients.push_back(client);
}

void Bank::printBankInfo() const {
    cout << "Bank name: " << this->name << "; Bank address: " << this->address << "\n";
}

void Bank::printClientsInfo() const {
    for(Client * client : this->clients) {
        client->printInfo();
    }
}

void Bank::printInfo() const {
    this->printBankInfo();
    this->printClientsInfo();
}

Bank::~Bank() {
    for (Client * client : this->clients) {
        delete client;
    }
}