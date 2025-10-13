#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

class Account
{
    protected:
        double balance;
        int numDeposits;
        int numWithdrawals;
        double annualInterestRate;
        double monthlyServiceCharges;
    
    public:
        // constructor 
        Account(double bal = 0.0, double rate = 0.0);

        // virtual functions
        virtual void deposit(double amount);
        virtual void withdraw(double amount);
        virtual void calcInt();
        virtual void monthlyProc();

        // acccessors
        double getBalance() const;
        int getNumDeposits() const;
        int getNumWithdrawals() const;
        double getMonthlyServiceCharges() const;

};
#endif