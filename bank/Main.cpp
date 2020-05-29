#include <iostream>
using namespace std;

#include "Bank.h"

void print(Account * account) {
    account->printInfo();
}

int main() {
    Bank * bank = new Bank("FIbank", "Bulgaria, Sofia, G.M.Dimitrov, No. 15");
    CorporativeClient c2("PLazza", "Studentski");
    bank->addClient(&c2);
    RegularClient * c1 = new RegularClient("Zhechko Popov", "Bulgaria, Svilengrad, Ivan Vazov, No. 11a", "08434244859");
    bank->addClient(c1);
    Account * a1 = new CreditAccount(2000, 0.10, "zhp_cr_1");
    bank->getClient("Zhechko Popov")->addAccount(a1);
    
    bank->getClient("Zhechko Popov")->getAccount("zhp_cr_1")->withdraw(400);
    bank->getClient("Zhechko Popov")->getAccount("zhp_cr_1")->withdraw(-50);

    Account * t = bank->getClient("Zhechko Popov")->getAccount("zhp_cr_1");

    print(bank->getClient("Zhechko Popov")->getAccount("zhp_cr_1"));

    CreditAccount * temp = dynamic_cast<CreditAccount *>(bank->getClient("Zhechko Popov")->getAccount("zhp_cr_1"));
    if(temp) {
        cout << temp->getDue() << "\n";
    }
    
    bank->printInfo();

    Bank bank2 = *bank;

    delete c1;
    delete a1;
    delete bank;

    return 0;
}
