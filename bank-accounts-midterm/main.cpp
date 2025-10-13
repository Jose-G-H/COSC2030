//
// Jose Garcia 
// 10/12/25
// Bank Accounts Midterm Programming Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

void displayStatistics(Account &);

int main()
{
    double amount;
    int num;
    cout << fixed << setprecision(2);

    // make saving and checking account
    SavingsAccount savings(50.0, 0.05);
    CheckingAccount checking(100.0, 0.03);

    cout << "------ Savings Account ------\n";
    cout << "\nHow many deposits this month? ";
    cin >> num;
    for (int i=0; i < num; i++)
    {
        cout << "Enter the deposit amount: $";
        cin >> amount;
        savings.deposit(amount);
    }

    cout << "\nHow many withdrawals this month? ";
    cin >> num;
    for (int i=0; i < num; i++)
    {
        cout << "Enter the Withdrawal amount: $";
        cin >> amount;
        savings.withdraw(amount);
    }

    cout << "\n------ Checking Account ------\n";
    cout << "\nHow many deposits this month? ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the deposit amount: $";
        cin >> amount;
        checking.deposit(amount);
    }

    cout << "\nHow many withdrawals this month? ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the withdrawal amount: $";
        cin >> amount;
        checking.withdraw(amount);
    }

    cout << "\n------ MONTHLY STATISTICS ------\n";

    savings.monthlyProc();
    checking.monthlyProc();

    cout << "\nSavings Account:\n";
    displayStatistics(savings);
    

    cout << "\nChecking Account:\n";
    displayStatistics(checking);

   

    return 0;
}

void displayStatistics(Account &acc)
{
    cout << fixed << setprecision(2);
    cout << "----------------\n";
    cout << "\nEnding Balance: $" << acc.getBalance() << endl;
    cout << "Withdrawals: " << acc.getNumWithdrawals() << endl;
    cout << "Service Charge: $" << acc.getMonthlyServiceCharges() << endl;
}
