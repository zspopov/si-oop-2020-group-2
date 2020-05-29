#include <iostream>
using namespace std;

#include "Bank.h"

int main() {
    Bank * bank = new Bank("FIbank", "Bulgaria, Sofia, G.M.Dimitrov, No. 15");
    bank->addClient(new RegularClient("Stefan Popov", "Bulgaria, Svilengrad, Ivan Vazov, No. 11a", "0878644859"));
    bank->getClient("Stefan Popov")->addAccount(new DepositAccount(0, 0.10, "sp_dp_1"));
    bank->getClient("Stefan Popov")->addAccount(new CreditAccount(2500, 0.10, "sp_cr_1"));
    bank->getClient("Stefan Popov")->getAccount("sp_cr_1")->withdraw(400);
    bank->getClient("Stefan Popov")->getAccount("sp_cr_1")->withdraw(-50);
    CreditAccount * temp = dynamic_cast<CreditAccount *>(bank->getClient("Stefan Popov")->getAccount("sp_cr_1"));
    cout << temp->getCreditInterest() << "\n";
    bank->printInfo();

    delete bank;
    return 0;
}
