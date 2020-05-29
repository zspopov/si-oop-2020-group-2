#include "Bank.h"

Bank::Bank() {
    this->name = "unknown";
    this->address = "unknown";
}

Bank::Bank(const string& name, const string& address) {
    this->name = name;
    this->address = address;
}

Bank::Bank(const Bank& rhs) {
    this->name = rhs.name;
    this->address = rhs.address;
    for(int i = 0; i < rhs.clients.size(); i++) {
        this->addClient(rhs.clients[i]);
    }
}
    
Bank& Bank::operator=(const Bank& rhs) {
    if(this != &rhs) {
        this->name = rhs.name;
        this->address = rhs.address;
        this->clients.clear();
        for(int i = 0; i < rhs.clients.size(); i++) {
            this->addClient(rhs.clients[i]);
        }
    }   
    return *this;
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
    RegularClient * regularClient = dynamic_cast<RegularClient *>(client);
    CorporativeClient * corporativeClient = dynamic_cast<CorporativeClient *>(client);
    if(regularClient) {
        this->clients.push_back(new RegularClient(*regularClient));
    }
    if(corporativeClient) {
        this->clients.push_back(new CorporativeClient(*corporativeClient));
    }
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
    //cout << "~Bank()\n";
    for (Client * client : this->clients) {
        delete client;
    }
}