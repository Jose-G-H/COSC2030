#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount:public Account
{
public:
    // constructor
    CheckingAccount(double bal = 0.0, double rate = 0.0);

    // overidden function
    void withdraw(double amount);
    void monthlyProc();
};
#endif