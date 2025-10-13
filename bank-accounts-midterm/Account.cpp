#include "Account.h"
#include <iomanip>

// constructor
Account::Account(double bal, double rate)
{
    balance = bal;
    annualInterestRate = rate;
    numDeposits = 0;
    numWithdrawals = 0;
    monthlyServiceCharges = 0.0;
}

// Deposit function 
void Account::deposit(double amount)
{
    balance += amount;
    numDeposits++;
}

// Withdraw function
void Account::withdraw(double amount)
{
    balance -= amount;
    numWithdrawals++;
}

// calculate monthly interest
void Account::calcInt()
{
    double monthlyRate = annualInterestRate / 12;
    double monthlyInterest = balance * monthlyRate;
    balance += monthlyInterest;
}

// Monthly processing
void Account::monthlyProc()
{
    calcInt();
    balance -= monthlyServiceCharges;

    cout << fixed << setprecision(2);
    cout << "\nMonthly Processing Complete. \n";
    cout << "Service Charges: $" << monthlyServiceCharges << endl;
    cout << "Ending Balance after interest: $" << balance << endl;

    numDeposits = 0;
    numWithdrawals = 0;
    monthlyServiceCharges = 0.0;
}

// Acccesors
double Account::getBalance() const {return balance;}
int Account::getNumDeposits() const {return numDeposits;}
int Account::getNumWithdrawals() const {return numWithdrawals;}
double Account::getMonthlyServiceCharges() const {return monthlyServiceCharges;}
