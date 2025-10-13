#include "SavingsAccount.h"
#include <iostream>
using namespace std;

// Constructor
SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal, rate)
{
    status = (bal >= 25);
}

// check status of account
void SavingsAccount::checkStatus()
{
        status = (balance >= 25);
}

// withdraw function 
void SavingsAccount::withdraw(double amount)
{
    checkStatus();
    if (!status)
    {
        cout << "Account inactive. Withdrawal Denied.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient funds. Withdraw denied.\n";
        return;
    }
        Account::withdraw(amount);
        if (balance < 25)
        {
            status = false;
            cout << "Account is now inactive (Account below is $25).\n";
        }
}


// deposit function 
void SavingsAccount::deposit(double amount)
{
    Account::deposit(amount);
    if (!status && balance >= 25)
    {
        status = true;
        cout << "Account is now active.\n";
    }
}

// monthly process
void SavingsAccount::monthlyProc()
{
    if (numWithdrawals > 4)
    monthlyServiceCharges += (numWithdrawals - 4);

    Account::monthlyProc();
    checkStatus();
}