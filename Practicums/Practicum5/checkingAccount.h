#ifndef checkingAccount_h
#define checkingAccount_h

#include <stdio.h>
#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_CHECKING = 0.04;
const double DEFAULT_MINIMUM_BALANCE = 500.00;
const double DEFAULT_SERVICE_CHARGE = 20.00;

class checkingAccount : public bankAccount
{
protected:
double interestRate, minimumBalance, serviceCharge;

public:
    double getInterestRate() const;
    double getServiceCharge() const;
    double getMinimumBalance() const;

    void setServiceCharges(double charges);
    void setInterestRate(double intRate);
    void setMinimumBalance(double minBalance);

    void postInterest();
    void writeCheck(double amount);
    bool verifyMinimumBalance(double amount);
    void withdraw(double amount);
    void print() const;

    checkingAccount(int acctNumber, double bal, double minBal = DEFAULT_MINIMUM_BALANCE, 
                    double intRate = DEFAULT_INTEREST_RATE_CHECKING, double ServC = DEFAULT_SERVICE_CHARGE);
};

#endif