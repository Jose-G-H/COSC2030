// sepcification file for SavingAccount class
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount:public Account
{
    private:
        bool status; // if true = activate, if false + deactivate
        void checkStatus();

    public:
        // constructor
        SavingsAccount(double bal = 0.0, double rate = 0.0);

        // overridden function
        void withdraw(double amount);
        void deposit(double amount);
        void monthlyProc();
};
#endif