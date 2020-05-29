#ifndef _REGULAR_CLIENT_H
#define _REGULAR_CLIENT_H

#include "Client.h"

class RegularClient : public Client {
private:
    string telephoneNumber;
public:
    RegularClient();
    RegularClient(const string& name, const string& address, const string& telephoneNumber);

    RegularClient(const RegularClient& rhs);
    RegularClient& operator=(const RegularClient& rhs);

    void setTelephoneNumber(const string& telephoneNumber);

    void printInfo() const;

    //~RegularClient();
};


#endif //_REGULAR_CLIENT_H