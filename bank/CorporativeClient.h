#ifndef _CORPORATIVE_CLIENT_H
#define _CORPORATIVE_CLIENT_H

#include "Client.h"

class CorporativeClient : public Client {
public:
    CorporativeClient();
    CorporativeClient(const string& name, const string& address);

    CorporativeClient(const CorporativeClient& rhs);
    CorporativeClient& operator=(const CorporativeClient& rhs);

    void printInfo() const;

    //~CorporativeClient();
};


#endif //_CORPORATIVE_CLIENT_H