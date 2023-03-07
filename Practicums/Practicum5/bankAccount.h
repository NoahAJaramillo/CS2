#ifndef bankAccount_h
#define bankAccount_h

#include <stdio.h>

class bankAccount
{
protected:
    int accountNumber;
    double balance;
public:
    double getBalance() const;
    int getAccountNumber() const;
    void deposit(double amount);
    void withdraw(double amount);
    void setAccountNumber(int acct);
    void print() const;

    bankAccount(int acctNumber = 1, double bal = 0);

};

#endif 