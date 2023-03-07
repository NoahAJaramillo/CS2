#include "bankAccount.h"
#include <iostream>
#include <iomanip>


bankAccount::bankAccount(int acctnumber, double bal)
{
    accountNumber = acctnumber;
    balance = bal;
}

double bankAccount::getBalance() const
{
    return balance;
}

int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::withdraw(double amount)
{
    balance -= amount;
}

void bankAccount::setAccountNumber(int acctNumber)
{
    accountNumber = acctNumber;
}

void bankAccount::print() const
{
    std::cout << "Your account number is: " << accountNumber << "Your current balance is: " << balance << std::endl;
}