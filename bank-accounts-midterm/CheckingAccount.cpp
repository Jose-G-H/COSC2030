#include "CheckingAccount.h"
#include <iostream>
using namespace std;

// constructor
CheckingAccount::CheckingAccount(double bal, double rate) : Account(bal, rate)
{  
}

// Withdraw function
void CheckingAccount::withdraw(double amount)
{
    if (balance - amount <0)
    {
        cout << "Insufficient funds. $15 fee charged.\n";
        monthlyServiceCharges += 15.0;
    }
    
    else 
    {
        Account::withdraw(amount);
    }
}

// monthly process
void CheckingAccount::monthlyProc()
{
    monthlyServiceCharges += (5 + (0.10 * numWithdrawals));
    Account::monthlyProc();
}