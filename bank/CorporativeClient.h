#ifndef _CORPORATIVE_CLIENT_H
#define _CORPORATIVE_CLIENT_H

#include "Client.h"

class CorporativeClient : public Client {
public:
    CorporativeClient();
    CorporativeClient(const string& name, const string& address);

    void printInfo() const;
};


#endif //_CORPORATIVE_CLIENT_H